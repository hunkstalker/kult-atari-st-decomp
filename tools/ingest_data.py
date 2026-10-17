#!/usr/bin/env python3
"""Extrae los recursos EMBEBIDOS de KULT.PRG a `matching/data/` (B1b).

Los 16 bloques (`SOURI.BIN`, `SOUCO.BIN`, …, `MUSIQ.BIN`) no existen como ficheros
sueltos en el disco: solo están dentro del PRG (se cargan por una tabla de
recursos). Este ingest los saca a `matching/data/<NOMBRE>.bin` para que el *build*
deje de leer el PRG (los recursos son assets: `matching/data/` está gitignored y
se regenera desde la copia del usuario).

Rangos: `matching/layout.json` → `resources_embedded` (`text_off` + `size`, en
offsets de imagen). Coinciden con los tramos que emite `build.py`.

Uso: python3 tools/ingest_data.py [--prg work/disk_a/KULT.PRG] [--out matching/data]
"""
import argparse
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TEXT_OFF = 28
LOAD_BASE = 0x10000


def main():
    ap = argparse.ArgumentParser(description="Extrae los recursos embebidos de KULT.PRG.")
    ap.add_argument("--prg", default=os.path.join(ROOT, "work", "disk_a", "KULT.PRG"))
    ap.add_argument("--layout", default=os.path.join(ROOT, "matching", "layout.json"))
    ap.add_argument("--out", default=os.path.join(ROOT, "matching", "data"))
    ns = ap.parse_args()

    if not os.path.exists(ns.prg):
        sys.exit("No encuentro el PRG original: %s" % ns.prg)
    prg = open(ns.prg, "rb").read()
    layout = json.load(open(ns.layout))
    os.makedirs(ns.out, exist_ok=True)

    n = 0
    for r in layout["resources_embedded"]:
        off, size, name = r["text_off"], r["size"], r["name"]
        blob = prg[TEXT_OFF + off:TEXT_OFF + off + size]
        if len(blob) != size:
            sys.exit("Recorte fuera de rango para %s (0x%x+0x%x)" % (name, off, size))
        dst = os.path.join(ns.out, name)
        open(dst, "wb").write(blob)
        print("  %-12s -> %s (%d B)" % (name, os.path.relpath(dst, ROOT), size))
        n += 1
    print("ingest: %d recursos -> %s" % (n, os.path.relpath(ns.out, ROOT)))


if __name__ == "__main__":
    main()
