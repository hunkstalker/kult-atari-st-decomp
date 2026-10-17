#!/usr/bin/env python3
"""Comparador de .PRG para la decompilación *matching* de Kult (plan M0).

Compara un PRG candidato (generado por el build matching) contra el original y
responde a la única pregunta que importa: **¿coinciden byte a byte?** Si no,
localiza la primera divergencia y la muestra con contexto desensamblado.

Uso:
    python3 tools/match_check.py ORIGINAL.PRG CANDIDATO.PRG [--base 0x10000]

Salidas:
    - cabecera de ambos (text/data/bss/relocs) y si difieren;
    - SHA-256 de ambos;
    - conjunto de relocalizaciones: iguales / primera que difiere;
    - primera direccion (runtime, con --base) donde difiere un byte, con +/- 8
      instrucciones de contexto en los dos.

Depende de capstone para el contexto desensamblado (opcional: sin él solo
reporta offsets). Reutiliza el parser de `prg_dis.py`.

Códigos de salida: 0 = idénticos; 1 = difieren; 2 = error de uso/lectura.
"""
import hashlib
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import prg_dis  # noqa: E402

try:
    import capstone
    _MD = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN)
except Exception:  # pragma: no cover - capstone may be absent in a bare env
    _MD = None

TEXT_OFF = 28


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def _hexdump_context(data, off, span=8):
    lo = max(0, off - span)
    hi = min(len(data), off + span + 1)
    out = []
    for i in range(lo, hi):
        mark = "<" if i == off else " "
        out.append("%06x%s %02x" % (i, mark, data[i]))
    return "\n".join(out)


def _disasm_window(data, off, base, before=16, after=16):
    if _MD is None:
        return "(capstone no disponible: contexto en desuso)"
    start = max(0, off - before)
    addr = base + start
    code = data[start:off + after]
    out = []
    for i in _MD.disasm(code, addr):
        mark = "  <-- primera divergencia" if i.address <= base + off < i.address + i.size else ""
        out.append("  %06x: %-20s %s %s%s"
                   % (i.address, i.bytes.hex(), i.mnemonic, i.op_str, mark))
    return "\n".join(out)


def compare(orig_path, cand_path, base):
    if not os.path.exists(orig_path):
        print("ERROR: no existe el original %s" % orig_path)
        return 2
    if not os.path.exists(cand_path):
        print("ERROR: no existe el candidato %s" % cand_path)
        return 2

    o = open(orig_path, "rb").read()
    c = open(cand_path, "rb").read()
    oh, ch = prg_dis.parse_header(o), prg_dis.parse_header(c)

    print("=" * 78)
    print("ORIGINAL  %s  (%d bytes)" % (orig_path, len(o)))
    print("CANDIDATO %s  (%d bytes)" % (cand_path, len(c)))
    print("sha256 original  = %s" % sha256(o))
    print("sha256 candidato = %s" % sha256(c))
    print("-" * 78)
    print("cabecera original : tlen=0x%x dlen=0x%x blen=0x%x slen=0x%x absf=0x%x"
          % (oh["tlen"], oh["dlen"], oh["blen"], oh["slen"], oh["absf"]))
    print("cabecera candidato: tlen=0x%x dlen=0x%x blen=0x%x slen=0x%x absf=0x%x"
          % (ch["tlen"], ch["dlen"], ch["blen"], ch["slen"], ch["absf"]))

    try:
        ofix = prg_dis.parse_reloc(o, oh)
    except ValueError as e:
        ofix = None
        print("relocs original : ERROR %s" % e)
    try:
        cfix = prg_dis.parse_reloc(c, ch)
    except ValueError as e:
        cfix = None
        print("relocs candidato: ERROR %s" % e)
    if ofix is not None and cfix is not None:
        same = ofix == cfix
        print("relocs: original=%d candidato=%d -> %s"
              % (len(ofix), len(cfix), "IGUALES" if same else "DIFIEREN"))
        if not same:
            only_o = sorted(ofix - cfix)[:8]
            only_c = sorted(cfix - ofix)[:8]
            print("  solo en original: %s" % ", ".join("0x%x" % a for a in only_o))
            print("  solo en candidato: %s" % ", ".join("0x%x" % a for a in only_c))

    if o == c:
        print("-" * 78)
        print("RESULTADO: IDENTICOS byte a byte (PRG matching).")
        return 0

    n = min(len(o), len(c))
    first = next((i for i in range(n) if o[i] != c[i]), n)
    print("-" * 78)
    if len(o) != len(c):
        print("TAMANOS DISTINTOS: %d vs %d" % (len(o), len(c)))
    print("PRIMERA DIVERGENCIA en offset de fichero 0x%x (imagen 0x%x, runtime 0x%x)"
          % (first, first - TEXT_OFF if first >= TEXT_OFF else first, base + first - TEXT_OFF))
    print("  original : %02x   candidato: %02x" % (o[first], c[first]))
    print("--- contexto original ---")
    print(_disasm_window(o, first, base))
    print("--- contexto candidato ---")
    print(_disasm_window(c, first, base))
    print("RESULTADO: DIFIEREN (primer byte 0x%x)." % first)
    return 1


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description="Compara dos .PRG (plan matching).")
    ap.add_argument("original")
    ap.add_argument("candidate")
    ap.add_argument("--base", type=lambda s: int(s, 0), default=0x10000)
    ns = ap.parse_args(argv)
    return compare(ns.original, ns.candidate, ns.base)


if __name__ == "__main__":
    sys.exit(main())
