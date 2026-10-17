#!/usr/bin/env python3
"""Genera fragmentos de datos para las TABLAS DE PUNTEROS embebidas en recursos.

RE (punto 1): los 189 relocs que viven dentro de regiones de recurso no se pueden
distinguir de sonido/sprites por valor ni por estructura (los datos dan rachas de
falsos positivos). Son **tablas de lógica** (tabla de recursos, tablas de
despacho/estado), no arte. Se **transcriben a fuente** (`dc.l <símbolo>`), como
en un matching decomp: los bytes de esas tablas son direcciones/nombres, no assets.

Salida: `matching/src/data_<addr>.s` + `matching/src/data_manifest.txt`
(`<addr> <fichero> <len>`). Una vez generados, el *build* ya no necesita la
semilla: emite estos fragmentos en lugar de los bytes crudos del recurso.

Uso: python3 tools/gen_data_tables.py [--prg work/disk_a/KULT.PRG]
"""
import argparse
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
sys.path.insert(0, os.path.join(ROOT, "matching"))
import prg_dis  # noqa: E402
import relocs  # noqa: E402

TEXT_OFF = 28
LOAD_BASE = 0x10000
GAP = 16          # agrupa posiciones separadas <= GAP bytes (tabla de recursos: 14)
SPAN_MAX = 0x600  # no fusionar tablas lejanas


def sym_name(v, namemap):
    rt = (v + LOAD_BASE) & 0xffffffff
    return namemap.get(rt) or ("s_%06x" % rt if rt <= 0xffffff else "s_%08x" % rt)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--prg", default=os.path.join(ROOT, "work", "disk_a", "KULT.PRG"))
    ap.add_argument("--layout", default=os.path.join(ROOT, "matching", "layout.json"))
    ns = ap.parse_args()

    d = open(ns.prg, "rb").read()
    h = prg_dis.parse_header(d)
    fixes = set(prg_dis.parse_reloc(d, h))
    layout = json.load(open(ns.layout))
    res = [(r["text_off"], r["text_off"] + r["size"]) for r in layout["resources_embedded"]]

    def inres(o):
        return any(s <= o < e for s, e in res)

    in_res = sorted(o for o in fixes if inres(o))
    # agrupa en spans
    spans = []
    for o in in_res:
        if spans and o - spans[-1][1] <= GAP and (o - spans[-1][0]) < SPAN_MAX:
            spans[-1][1] = o + 4
        else:
            spans.append([o, o + 4])

    namemap = relocs.load_namemap()
    outdir = os.path.join(ROOT, "matching", "src")
    manifest = []
    total = 0
    for a, b in spans:
        names = {}
        for p in range(a, b):
            if p in fixes:
                v = int.from_bytes(d[TEXT_OFF + p:TEXT_OFF + p + 4], "big")
                names[v] = sym_name(v, namemap)
        fn = "data_%06x.s" % a
        with open(os.path.join(outdir, fn), "w") as f:
            f.write("d_%06x:\n" % a)
            # emite bytes/`dc.l` intercalando los labels de globals del span
            i, n = a, b
            p = a
            while p < b:
                img = p + LOAD_BASE
                if img in namemap:
                    f.write("%s:\n" % namemap[img])
                if p in fixes:
                    f.write("\tdc.l\t%s\n" % names[int.from_bytes(d[TEXT_OFF + p:TEXT_OFF + p + 4], "big")])
                    p += 4
                    continue
                q = p + 1
                while q < b and (q not in fixes) and ((q + LOAD_BASE) not in namemap):
                    q += 1
                raw = d[TEXT_OFF + p:TEXT_OFF + q]
                for k in range(0, len(raw), 16):
                    f.write("\tdc.b\t" + ",".join("$%02x" % x for x in raw[k:k + 16]) + "\n")
                p = q
        manifest.append("0x%x   %s   %#x" % (a + LOAD_BASE, fn, b - a))
        total += b - a
        print("  data_%06x.s  0x%06x..0x%06x  (%d B, %d punteros)"
              % (a, a, b, b - a, sum(1 for p in range(a, b) if p in fixes)))
    with open(os.path.join(outdir, "data_manifest.txt"), "w") as f:
        f.write("# generado por tools/gen_data_tables.py (tablas de punteros en recursos)\n")
        f.write("\n".join(manifest) + "\n")
    print("total: %d fragmentos, %d B, %d punteros" % (len(spans), total, len(in_res)))


if __name__ == "__main__":
    main()
