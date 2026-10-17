#!/usr/bin/env python3
"""Build matching multi-objeto: ensambla por trozos (as68) y enlaza (link68).

`as68` tiene un limite de tamano/simbolos con el fichero monolitico; aqui se parte
el `text` en trozos contiguos, cada uno a un `.o` (con `xdef` de sus etiquetas), y
se enlazan en orden con `link68` -> `relmod`.
"""
import hashlib
import json
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "matching"))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import build as B  # noqa: E402
import prg_dis  # noqa: E402

TEXT_OFF = 28
LOAD_BASE = 0x10000
START = LOAD_BASE
LABEL_RE = re.compile(r"^(\w+):", re.M)
CHUNK = 0x10000


def emit_bytes(f, data, base, names):
    i, n = 0, len(data)
    while i < n:
        here = base + i
        if here in names:
            for nm in names[here]:
                f.write(nm + ":\n")
        if data[i] == 0:
            j = i
            while j < n and data[j] == 0:
                if j > i and (base + j) in names:
                    break
                j += 1
            f.write("\tdcb.b %d,0\n" % (j - i))
            i = j
        else:
            j = i
            while j < n and data[j] != 0:
                if j > i and (base + j) in names:
                    break
                j += 1
            run = data[i:j]
            for k in range(0, len(run), 16):
                f.write("\tdc.b " + ",".join("$%02x" % b for b in run[k:k + 16]) + "\n")
            i = j


def main():
    prg = open(os.path.join(ROOT, "work", "disk_a", "KULT.PRG"), "rb").read()
    layout = json.load(open(os.path.join(ROOT, "matching", "layout.json")))
    tlen = layout["header"]["tlen"]
    orig = prg[TEXT_OFF:TEXT_OFF + tlen]
    tool = os.path.join(ROOT, "matching", "toolchain", "bin", "linux")
    as68, link68, relmod = (os.path.join(tool, x) for x in ("as68", "link68", "relmod"))

    frags = B.load_fragments()
    labels = {}
    autoequ = []
    for src in (B.parse_globals(), B.load_symbols()):
        for a, names in src.items():
            tr = a - LOAD_BASE
            if 0 <= tr < tlen:
                labels.setdefault(a, []).extend(names)
            else:
                for n in names:
                    autoequ.append((tr & 0xffffffff, n))
    equ = autoequ + [(v, n) for v, n, _ in B.load_equ()]

    td = tempfile.mkdtemp()
    spans = {}
    for a, p in frags.items():
        ln = B.fraglens[a] if a in B.fraglens else B.measure_fragment(p, as68, td)
        spans[a] = (a, a + ln, p)
    # quitar fragmentos contenidos en otro
    spans = {a: v for a, v in spans.items()
             if not any(s2 < v[0] and v[1] <= e2 for a2, (s2, e2, _) in spans.items() if a2 != a)}

    resources = sorted((r["image_addr"], r["image_addr"] + r["size"]) for r in layout["resources_embedded"])
    end = START + tlen
    pieces = []
    pos = START
    while pos < end:
        if pos in spans:
            s, e, p = spans[pos]
            pieces.append(("frag", pos, min(e, end), p))
            pos = e
        elif any(s <= pos < e for s, e in resources):
            s, e = next((s, e) for s, e in resources if s <= pos < e)
            pieces.append(("data", pos, e, None))
            pos = e
        else:
            nxt = min([s for s, _ in resources if s > pos] + [a for a in spans if a > pos] + [end])
            pieces.append(("gap", pos, nxt, None))
            pos = nxt

    def labels_in(a, b):
        return {x: labels[x] for x in labels if a <= x < b}

    chunks = []
    cur, size = [], 0
    for pc in pieces:
        ln = pc[2] - pc[1]
        if cur and size + ln > CHUNK:
            chunks.append(cur)
            cur, size = [], 0
        cur.append(pc)
        size += ln
    if cur:
        chunks.append(cur)

    out = os.path.join(ROOT, "matching", "out")
    os.makedirs(out, exist_ok=True)
    objs = []
    for ci, ch in enumerate(chunks):
        alabels = labels_in(ch[0][1], ch[-1][2])
        defined = set()
        for kind, a, b, p in ch:
            if kind == "frag":
                defined |= set(LABEL_RE.findall(open(p).read()))
        sfile = os.path.join(out, "chunk%02d.s" % ci)
        with open(sfile, "w") as f:
            f.write("\tTEXT\n")
            if ci == 0:
                for v, n in equ:
                    f.write("xdef\t%s\n%s\tequ\t$%x\n" % (n, n, v))
            for n in sorted({n for ns in alabels.values() for n in ns} | defined):
                f.write("xdef\t%s\n" % n)
            for kind, a, b, p in ch:
                if kind == "frag":
                    f.write(B._force_long(open(p).read()))
                elif kind == "data":
                    emit_bytes(f, orig[a - LOAD_BASE:b - LOAD_BASE], a, labels_in(a, b))
                else:
                    emit_bytes(f, bytes(b - a), a, labels_in(a, b))
        r = subprocess.run([as68, "-u", "-L", "-n", "chunk%02d.s" % ci], cwd=out, capture_output=True)
        if r.returncode != 0:
            print("as68 fallo chunk%d:\n%s" % (ci, r.stdout.decode("latin1")[:500]))
            return 1
        objs.append("chunk%02d.o" % ci)
        print("chunk%02d ok (%d B fuente)" % (ci, os.path.getsize(sfile)))

    r = subprocess.run([link68, "[]", "kult.rel=" + ",".join(objs)], cwd=out, capture_output=True)
    if r.returncode != 0:
        print("link68 fallo:\n%s" % r.stdout.decode("latin1")[:1000])
        return 1
    subprocess.run([relmod, "kult.rel", "KULT.PRG"], cwd=out, check=True)

    built = open(os.path.join(out, "KULT.PRG"), "rb").read()
    print("PRG %d bytes (orig %d)" % (len(built), len(prg)))
    print("sha orig=%s" % hashlib.sha256(prg).hexdigest()[:16])
    print("sha buld=%s" % hashlib.sha256(built).hexdigest()[:16])
    bt = built[TEXT_OFF:TEXT_OFF + tlen]
    diffs = [i for i in range(min(len(bt), tlen)) if bt[i] != orig[i]]
    print("bytes de text distintos: %d" % len(diffs))
    if diffs:
        print("  primeros:", [hex(START + d) for d in diffs[:8]])
    ro = set(prg_dis.parse_reloc(prg, prg_dis.parse_header(prg)))
    rb = set(prg_dis.parse_reloc(built, prg_dis.parse_header(built)))
    print("relocs orig=%d built=%d iguales=%s" % (len(ro), len(rb), ro == rb))
    return 0 if not diffs else 1


if __name__ == "__main__":
    sys.exit(main())
