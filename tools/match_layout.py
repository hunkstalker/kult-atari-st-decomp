#!/usr/bin/env python3
"""Mapa de layout del `KULT.PRG` para el build *matching* (plan M1).

Reúne los "anclajes" conocidos del segmento `text` para saber dónde va cada cosa:

  - cabecera GEMDOS + tabla de relocalizaciones DRI;
  - **tabla de recursos embebidos** (`nombre\\0` + u32 BE con el offset relativo
    al `text`) y la dirección de imagen de cada recurso (= offset + 0x10000);
  - índice de funciones de Ghidra (`work/decomp.c`): inicio/tamaño/nombre.

Salida: `matching/layout.json` (datos) + informe por consola. NO incluye bytes
del juego (solo direcciones/nombres), por lo que es versionable.

Uso: python3 tools/match_layout.py [--prg work/disk_a/KULT.PRG]
"""
import json
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import prg_dis  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LOAD_BASE = 0x10000
TEXT_OFF = 28
RE_IDX = re.compile(r"^//\s+([0-9a-fA-F]{8})\s+(\S+)\s+(\d+) bytes", re.M)


def parse_resource_table(d):
    """Busca la tabla `nombre\\0`+u32 y devuelve [(name, text_off)], la más larga."""
    def parse(start):
        out, p = [], start
        while p < len(d):
            e = d.find(b"\x00", p)
            if e < 0:
                break
            name = d[p:e]
            if not name or len(name) > 16 or not all(32 <= c < 127 for c in name) \
               or not name.endswith(b".BIN"):
                break
            out.append((name.decode(), struct.unpack(">I", d[e + 1:e + 5])[0]))
            p = e + 5
        return out
    best = (0, None)
    for s in range(TEXT_OFF, TEXT_OFF + 0x2c534):
        r = parse(s)
        if len(r) > best[0]:
            best = (len(r), s)
    n, start = best
    return start, parse(start)


def parse_functions(decomp):
    fns = []
    if os.path.exists(decomp):
        for m in RE_IDX.finditer(open(decomp, encoding="latin1").read()):
            fns.append({"addr": int(m.group(1), 16), "name": m.group(2),
                        "size": int(m.group(3))})
    return fns


def main(argv):
    prg = os.path.join(ROOT, "work", "disk_a", "KULT.PRG")
    if "--prg" in argv:
        prg = argv[argv.index("--prg") + 1]
    d = open(prg, "rb").read()
    h = prg_dis.parse_header(d)
    try:
        relocs = sorted(prg_dis.parse_reloc(d, h))
    except ValueError as e:
        relocs = []
        print("AVISO relocs: %s" % e)

    tstart, table = parse_resource_table(d)
    fns = parse_functions(os.path.join(ROOT, "work", "decomp.c"))

    embedded = [(n, o) for n, o in table if o < h["tlen"]]
    external = [(n, o) for n, o in table if o >= h["tlen"]]
    resources = sorted(
        ({"name": n, "text_off": o, "image_addr": o + LOAD_BASE} for n, o in embedded),
        key=lambda r: r["text_off"])
    # El span llega hasta el siguiente anclaje (siguiente recurso o el primer
    # inicio de función que caiga dentro), no hasta el siguiente recurso a
    # ciegas: puede haber código intercalado (p. ej. la música tras PERSO).
    fn_addrs = sorted(f["addr"] for f in fns)
    text_end = h["tlen"]
    for i, r in enumerate(resources):
        nxt = resources[i + 1]["text_off"] if i + 1 < len(resources) else text_end
        bound_img = nxt + LOAD_BASE
        cut = next((a for a in fn_addrs if r["image_addr"] < a < bound_img), bound_img)
        r["span_to_next"] = nxt - r["text_off"]          # cota superior bruta
        r["size"] = cut - r["image_addr"]                 # corte en el primer código
        r["followed_by_code_at"] = cut if cut < bound_img else None

    # regiones de código segun el indice + recursos => anclajes ordenados
    anchors = ([{"kind": "resource", "addr": r["image_addr"], "name": r["name"]}
                for r in resources]
               + [{"kind": "code", "addr": f["addr"], "name": f["name"]}
                  for f in fns])
    anchors.sort(key=lambda a: a["addr"])

    out = {
        "prg": os.path.relpath(prg, ROOT),
        "header": {k: h[k] for k in ("tlen", "dlen", "blen", "slen", "absf")},
        "text": {"image_start": LOAD_BASE, "image_end": LOAD_BASE + h["tlen"]},
        "reloc_count": len(relocs),
        "resource_table_file_off": tstart,
        "resource_table_image_off": tstart - TEXT_OFF + LOAD_BASE,
        "resources_embedded": resources,
        "resources_external": [{"name": n, "text_off": o} for n, o in external],
        "functions": len(fns),
        "code_span": [min(f["addr"] for f in fns), max(f["addr"] + f["size"] for f in fns)],
    }
    dst = os.path.join(ROOT, "matching", "layout.json")
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    json.dump(out, open(dst, "w"), indent=2, ensure_ascii=False)

    print("KULT.PRG  text=0x%x  relocs=%d  funciones(indice)=%d" % (h["tlen"], len(relocs), len(fns)))
    print("tabla de recursos en file 0x%x (imagen 0x%x)" % (tstart, tstart - TEXT_OFF + LOAD_BASE))
    print("recursos embebidos: %d ; externos ($$): %d" % (len(embedded), len(external)))
    print("%-14s %10s %10s %10s  %s" % ("recurso", "text_off", "imagen", "tamano", "codigo tras el"))
    for r in resources:
        tail = "0x%06x" % r["followed_by_code_at"] if r["followed_by_code_at"] else "-"
        print("%-14s 0x%08x 0x%08x 0x%08x  %s"
              % (r["name"], r["text_off"], r["image_addr"], r["size"], tail))
    print("mapa escrito en matching/layout.json")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
