#!/usr/bin/env python3
"""Build matching con **vasm** (ensambla el text del programa completo).

El `as68` de Alcyon tiene un bug (fase) con el programa completo; vasm (portable,
sin ese defecto) ensambla TODA la fuente reconstruida (auto + manual) a un PRG TOS
**byte a byte identico** al original.

- Fuente: `auto_*.s` (VERSIONADOS, ver B1a) + `manifest.txt` (manual) ->
  `build.py` genera `out/kult.s` (sintaxis as68); aqui se normaliza a vasm
  (`opt t-`, sin espacios tras coma) y se ensambla con
  `vasmm68k_mot -Ftos -m68000 -no-opt -nosym`.
- **No regenera** los `auto_*.s` por defecto (ya son fuente versionada). Para
  regenerarlos desde el PRG original (dev): `--regen` / `make regen`.
- **Tabla de relocalizaciones:** la **deriva vasm** de los simbolos de la fuente
  (`autogen.py` sustituye cada destino de reloc por su simbolo; `build.py` los
  define como expresiones relocalizables). No se copia del original. Ver
  `matching/RELOCS.md`.
- La comparacion con `work/disk_a/KULT.PRG` es **opcional** (oraculo): si existe,
  verifica text/cabecera/relocs; si no, solo construye e informa del sha256.
"""
import argparse
import hashlib
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
LOAD_BASE = 0x10000
TEXT_OFF = 28


def main():
    ap = argparse.ArgumentParser(description="Build matching (vasm) byte-identico.")
    ap.add_argument("--regen", action="store_true",
                    help="regenerar auto_*.s desde el PRG original (dev)")
    ns = ap.parse_args()

    python = sys.executable
    tool = os.path.join(ROOT, "matching", "toolchain", "bin")
    vasm = os.path.join(tool, "vasmm68k_mot")
    prg = os.path.join(ROOT, "work", "disk_a", "KULT.PRG")

    # 1) (opcional) regenerar auto fragmentos; build.py genera out/kult.s
    if ns.regen:
        subprocess.run([python, os.path.join(ROOT, "matching", "autogen.py")], check=True)
    subprocess.run([python, os.path.join(ROOT, "matching", "build.py"), "--keep"])  # as68 puede fallar (bug); solo necesitamos kult.s
    kult = os.path.join(ROOT, "matching", "out", "kult.s")

    # 2) normalizar a vasm
    s = open(kult).read()
    s = re.sub(r",\s+", ",", s)
    vs = os.path.join(ROOT, "matching", "out", "kult_vasm.s")
    open(vs, "w").write("\topt t-\n" + s)

    # 3) ensamblar
    out = os.path.join(ROOT, "matching", "out", "kult_vasm.prg")
    r = subprocess.run([vasm, "-Ftos", "-m68000", "-no-opt", "-nosym", "-o", out, vs],
                       capture_output=True)
    if r.returncode != 0:
        sys.stderr.write(r.stdout.decode("latin1") + r.stderr.decode("latin1"))
        return 1
    b = open(out, "rb").read()

    layout = json.load(open(os.path.join(ROOT, "matching", "layout.json")))
    tlen = layout["header"]["tlen"]
    end = TEXT_OFF + tlen
    # 4) PRG final = salida de vasm TAL CUAL: la tabla de relocs la DERIVA vasm
    #    de los simbolos de la fuente (no se copia del original; ver matching/RELOCS.md).
    final = b
    fp = os.path.join(ROOT, "matching", "out", "KULT.PRG")
    open(fp, "wb").write(final)

    # comparativa opcional con el original (oraculo)
    if os.path.exists(prg):
        import prg_dis
        orig = open(prg, "rb").read()
        ro = set(prg_dis.parse_reloc(orig, prg_dis.parse_header(orig)))
        rb = set(prg_dis.parse_reloc(b, prg_dis.parse_header(b)))
        print("text (fuente) igual:", orig[TEXT_OFF:end] == b[TEXT_OFF:end])
        print("cabecera igual:", orig[:TEXT_OFF] == b[:TEXT_OFF])
        print("relocs derivados por vasm: %d (original %d)  iguales: %s"
              % (len(rb), len(ro), rb == ro))
        if rb != ro:
            print("  faltan:", sorted("0x%x" % x for x in ro - rb)[:10])
            print("  sobran:", sorted("0x%x" % x for x in rb - ro)[:10])
        print("PRG final byte-identico:", final == orig)
        print("sha256:", hashlib.sha256(final).hexdigest())
        return 0 if final == orig else 1
    else:
        print("(sin %s: solo se construye, sin comparar)" % os.path.relpath(prg, ROOT))
        print("sha256:", hashlib.sha256(final).hexdigest())
        return 0


if __name__ == "__main__":
    sys.exit(main())
