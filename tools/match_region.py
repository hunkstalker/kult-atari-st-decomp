#!/usr/bin/env python3
"""Compara una región de bytes ensamblada contra el `KULT.PRG` original.

Herramienta central de la ruta "matching disassembly" (plan M1/M5): se ensambla
una función o un bloque de datos a un binario **crudo** y se compara con los
bytes del original en su dirección de imagen.

Uso:
    python3 tools/match_region.py ORIGINAL.PRG CANDIDATO.bin --addr 0x10000 [--len N]
    python3 tools/match_region.py ORIGINAL.PRG CANDIDATO.bin --image-off 0x10000 --len N

Convenciones:
    - `--addr` es una **dirección de imagen** (base de carga 0x10000); el offset de
      fichero = addr - 0x10000 + 28.
    - `--image-off` es un offset **relativo al segmento text** (0 = 0x10000).
    - Si se omite `--len`, se usa el tamaño del candidato.
    - `--holes A,B[,...]` declara tramos a ignorar (p. ej. direcciones de datos
      intercalados que aún no se han reconstruido), en direcciones de imagen.

Código de salida: 0 = la región coincide; 1 = difiere; 2 = error de uso.
"""
import os
import argparse
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import prg_dis  # noqa: E402

TEXT_OFF = 28
LOAD_BASE = 0x10000


def _disasm(data, addr, span=24):
    try:
        import capstone
    except Exception:
        return None
    md = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN)
    out = []
    for i in md.disasm(data, addr):
        out.append("  %06x: %-20s %s %s" % (i.address, i.bytes.hex(), i.mnemonic, i.op_str))
    return "\n".join(out)


def _parse_holes(spec):
    holes = []
    for part in (spec or "").split(","):
        if not part:
            continue
        lo, hi = part.split(":")
        holes.append((int(lo, 0), int(hi, 0)))
    return holes


def main(argv=None):
    ap = argparse.ArgumentParser(description="Compara una región contra el PRG original.")
    ap.add_argument("original")
    ap.add_argument("candidate")
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--addr", type=lambda s: int(s, 0), help="dirección de imagen (base 0x10000)")
    g.add_argument("--image-off", type=lambda s: int(s, 0), help="offset relativo al text")
    ap.add_argument("--len", type=lambda s: int(s, 0), default=None)
    ap.add_argument("--holes", default="", help="A:B,C:D en direcciones de imagen")
    ap.add_argument("--cand-prg", action="store_true",
                    help="el candidato es un .PRG (salta su cabecera de 28 bytes)")
    ns = ap.parse_args(argv)

    addr = ns.addr if ns.addr is not None else LOAD_BASE + ns.image_off
    holes = _parse_holes(ns.holes)

    orig = open(ns.original, "rb").read()
    cand = open(ns.candidate, "rb").read()
    if ns.cand_prg:
        # el candidato es un PRG de imagen completa: trocear en la region
        cand = cand[TEXT_OFF + (addr - LOAD_BASE):]
    n = ns.len if ns.len is not None else len(cand)
    n = min(n, len(cand))
    foff = TEXT_OFF + (addr - LOAD_BASE)
    o = orig[foff:foff + n]
    c = cand[:n]

    in_hole = lambda a: any(lo <= a < hi for lo, hi in holes)  # noqa: E731
    raw = [i for i in range(n) if o[i] != c[i]]
    diffs = [i for i in raw if not in_hole(addr + i)]
    print("region imagen 0x%06x..0x%06x  (%d bytes)  candidato=%s"
          % (addr, addr + n, n, ns.candidate))
    if not diffs:
        extra = "; %d bytes en huecos ignorados" % len(raw) if holes else ""
        print("RESULTADO: COINCIDE byte a byte (%d bytes%s)." % (n, extra))
        return 0
    print("DIFERENCIAS: %d bytes (primera en 0x%06x)" % (len(diffs), addr + diffs[0]))
    for i in diffs[:8]:
        print("  0x%06x: orig %02x  cand %02x" % (addr + i, o[i], c[i]))
    ctx = _disasm(o[max(0, diffs[0] - 8):diffs[0] + 16], addr + max(0, diffs[0] - 8))
    if ctx:
        print("--- contexto original ---")
        print(ctx)
    return 1


if __name__ == "__main__":
    sys.exit(main())

