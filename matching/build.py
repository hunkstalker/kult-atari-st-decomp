#!/usr/bin/env python3
"""Build *matching* de Kult (arquitectura por segmentos, M1.1/M2).

Genera `matching/out/kult.s`: un único fichero `TEXT` que emite, en orden de
dirección, cada **segmento** del `text` con `org`:

  - **funciones**: si hay un fragmento reconstruido (`matching/src/`, manifest),
    se inserta; si no, se emite solo su etiqueta (el hueco lo rellena `as68`
    con ceros, y así el build tolera funciones aún no hechas);
  - **recursos/datos**: se emiten sus bytes (`dc.b`) en su offset, partiendo el
    bloque donde haya etiquetas de globales;
  - **globales** (`addrs.h`): etiqueta en su dirección (para que las referencias
    absolutas generen reloc).

Luego ensambla (`as68`), enlaza (`link68`) y convierte a `.prg` (`relmod`), y
compara cada región reconstruida/datos con el original.

Uso: matching/build.py [--toolchain DIR] [--prg RUTA] [--keep]

Fragmentos: `matching/src/manifest.txt` con líneas `<image_addr_hex> <fichero>`.
Cada fragmento es asm (sin `TEXT`) que **define su propia etiqueta de entrada**
(`f_<image_addr>`). Ver matching/README.md.
"""
import argparse
import hashlib
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import relocs  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TEXT_OFF = 28
LOAD_BASE = 0x10000
DATA_DIR = os.path.join(ROOT, "matching", "data")
RE_IDX = re.compile(r"^//\s+([0-9a-fA-F]{8})\s+(\S+)\s+(\d+) bytes", re.M)
fraglens = {}
RE_ADDR = re.compile(r"^#define\s+(A_\w+)\s+0x([0-9a-fA-F]+)\s*(?:/\*.*?\*/)?\s*$")


def fname(image_addr):
    return "f_%06x" % image_addr


def load_data_blob(layout, tlen):
    """Imagen del `text` con los recursos embebidos leidos de `matching/data/`
    (B1b: el build ya no lee esos bytes del PRG)."""
    blob = bytearray(tlen)
    for r in layout["resources_embedded"]:
        off, size, name = r["text_off"], r["size"], r["name"]
        p = os.path.join(DATA_DIR, name)
        if not os.path.exists(p):
            sys.exit("Falta %s; ejecuta `python3 tools/ingest_data.py` (o `make ingest`)."
                     % os.path.relpath(p, ROOT))
        b = open(p, "rb").read()
        if len(b) != size:
            sys.exit("Tamano de %s = %d != %d (layout)" % (p, len(b), size))
        blob[off:off + size] = b
    return bytes(blob)


def parse_functions():
    fns = {}
    path = os.path.join(ROOT, "work", "decomp.c")
    if os.path.exists(path):
        for m in RE_IDX.finditer(open(path, encoding="latin1").read()):
            fns[int(m.group(1), 16)] = m.group(2)
    return fns


def parse_globals():
    out = {}
    path = os.path.join(ROOT, "matching", "include", "addrs.h")
    if os.path.exists(path):
        for line in open(path):
            m = RE_ADDR.match(line.rstrip())
            if m:
                out.setdefault(int(m.group(2), 16), []).append(m.group(1))
    return out


def load_fragments():
    global fraglens
    frags = {}
    for man in ("manifest.txt", "autogen.txt", "data_manifest.txt"):
        path = os.path.join(ROOT, "matching", "src", man)
        if not os.path.exists(path):
            continue
        for line in open(path):
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split()
            a, f = parts[0], parts[1]
            frags[int(a, 0)] = os.path.join(ROOT, "matching", "src", f)
            if len(parts) > 2:
                fraglens[int(a, 0)] = int(parts[2], 0)
    return frags


def load_symbols():
    """`symbols.txt`: `<image_addr_hex> <nombre>` -> etiquetas con reloc."""
    out = {}
    path = os.path.join(ROOT, "matching", "src", "symbols.txt")
    if os.path.exists(path):
        for line in open(path):
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            a, n = line.split()
            out.setdefault(int(a, 0), []).append(n)
    return out


RE_SYM = re.compile(r"\b[A-Za-z_][A-Za-z0-9_]*\b")
RE_SNAME = re.compile(r"^s_([0-9a-fA-F]{4,8})$")


def source_identifiers(frags):
    """Identificadores referenciados en los fragmentos de la fuente (B2-lite)."""
    refs = set()
    for p in frags.values():
        refs |= set(RE_SYM.findall(open(p).read()))
    return refs


def source_newdefs(refs, names, existing):
    """Símbolos nuevos a definir (`s_%06x equ f_010000±$c`), derivados de la fuente:
    los `s_*` referenciados en fragmentos + los nombres usados en recursos."""
    out = {}
    for n in refs:
        m = RE_SNAME.match(n)
        if m and n not in existing:
            out[n] = (int(m.group(1), 16) - LOAD_BASE) & 0xffffffff
    for v, n in names.items():          # nombres usados en dc.l de recursos
        if n not in existing:
            out.setdefault(n, v)
    return sorted((v, n) for n, v in out.items())


def load_equ():
    """`equ.txt`: `<valor_hex> <nombre> [addr|const]`.

    Devuelve `(valor, nombre, tipo)`; `tipo` = `addr` (dirección relocalizable) o
    `const` (absoluta). Default `const` (retrocompatible)."""
    out = []
    path = os.path.join(ROOT, "matching", "src", "equ.txt")
    if os.path.exists(path):
        for line in open(path):
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split()
            v, n = parts[0], parts[1]
            kind = parts[2] if len(parts) > 2 else "const"
            out.append((int(v, 0), n, kind))
    return out


def emit_bytes(f, data):
    """Emite `data` con dc.b (16/linea) y dcb.b para ceros."""
    i, n = 0, len(data)
    while i < n:
        if data[i] == 0:
            j = i
            while j < n and data[j] == 0:
                j += 1
            f.write("\tdcb.b %d,0\n" % (j - i))
            i = j
        else:
            j = i
            while j < n and data[j] != 0:
                j += 1
            run = data[i:j]
            for k in range(0, len(run), 16):
                row = run[k:k + 16]
                f.write("\tdc.b " + ",".join("$%02x" % b for b in row) + "\n")
            i = j


def _force_long(text):
    """Impide que as68 acorte instrucciones con inmediato a formas cortas.

    as68 convierte `move.l/movea.l #c,dn` en `moveq` y `add/addi/sub/subi` con
    inmediato pequenyo en `addq/subq`; el binario de 1989 conserva la forma larga.
    Envolver el inmediato en parentesis (`#(c)`) lo impide (verificado). Solo
    afecta a esas familias de mnemonicos con inmediato numerico."""
    risk = re.compile(r"^\s*(movea?\.l|(?:add|addi|sub|subi)\.[wlb])\s")
    out = []
    for line in text.splitlines(keepends=True):
        # btst/bset/bclr/bchg #imm,Dn: as68 exige sin sufijo de tamano.
        line = re.sub(r"\b(b(?:tst|set|clr|chg))\.b(\s+.*,\s*d[0-7]\s*)$", r"\1\2", line)
        if risk.match(line) and "#" in line:
            line = re.sub(r"#([$0-9][^\s,]*)", r"#(\1)", line)
        out.append(line)
    return "".join(out)


def measure_fragment(path, as68, tmpdir):
    """Ensambla un fragmento en aislado y devuelve la longitud de su text.

    El objeto DRI (mismo layout que el PRG) lleva la longitud del text en el
    u32 BE del offset 2."""
    import shutil
    src = os.path.join(tmpdir, "frag.s")
    text = _force_long(open(path).read())
    # En aislado, define las etiquetas `f_`/`s_` referenciadas para que as68
    # pueda resolver ramas cortas a simbolos aun no enlazados (solo importa la
    # longitud). Se omiten las ya definidas en el propio fragmento.
    defined = set(re.findall(r"^(\w+):", text, re.M))
    refs = set(re.findall(r"\b([fsl]_[0-9a-fA-F]+)\b", text))
    for n in sorted(refs - defined):
        text += n + ":\n\tdcb.b 0\n"
    with open(src, "w") as fh:
        fh.write(text)
    p = subprocess.run([as68, "-u", "-L", "-n", "frag.s"], cwd=tmpdir, capture_output=True)
    if p.returncode != 0:
        sys.stderr.write("FALLO midiendo %s:\n%s\n" % (path, p.stdout.decode("latin1")))
        raise SystemExit(1)
    obj = open(os.path.join(tmpdir, "frag.o"), "rb").read()
    return int.from_bytes(obj[2:6], "big")


def build_asm(layout, prg, frags, fns, labels, equ, as68, path,
              target_vals=None, newdefs=None, fixes=None, names=None, data_blob=None):
    tlen = layout["header"]["tlen"]
    # bytes de los recursos: del blob ingestado (B1b); fallback al PRG (compat)
    orig = data_blob if data_blob is not None else prg[TEXT_OFF:TEXT_OFF + tlen]
    target_vals = target_vals or set()
    newdefs = newdefs or []
    fixes = fixes or set()
    names = names or {}
    resources = [(r["image_addr"] - LOAD_BASE, r["size"]) for r in layout["resources_embedded"]]

    def in_res(off):
        return any(s <= off < s + sz for s, sz in resources)

    # longitud de cada fragmento (pre-pase a as68)
    import tempfile
    with tempfile.TemporaryDirectory() as td:
        flen = {a: (fraglens[a] if a in fraglens else measure_fragment(p, as68, td)) for a, p in frags.items()}

    segs = set(a - LOAD_BASE for a in fns) | set(a - LOAD_BASE for a in frags) \
        | set(a - LOAD_BASE for a in labels) | set(s for s, _ in resources) \
        | set((a - LOAD_BASE) + flen[a] for a in frags)
    segs = sorted(x for x in segs if 0 <= x < tlen)
    segs.append(tlen)

    spans = [(a - LOAD_BASE, a - LOAD_BASE + flen[a]) for a in frags]

    def inside(a):
        return any(fa < a < fe for fa, fe in spans)

    with open(path, "w") as f:
        f.write("\tTEXT\n")
        for v, n in equ:
            if v in target_vals:  # destino de reloc -> simbolo relocalizable
                f.write(relocs.def_expr(v, n))
            else:
                f.write("%s\tequ\t$%x\n" % (n, v))
        for v, n in newdefs:
            f.write(relocs.def_expr(v, n))
        pos = 0
        for idx in range(len(segs) - 1):
            a, b = segs[idx], segs[idx + 1]
            if inside(a):
                continue
            if a > pos:
                f.write("\tdcb.b %d,0\n" % (a - pos))
            elif a < pos:
                sys.exit("Estructura solapada en 0x%x (fragmento demasiado largo)" % a)
            img = a + LOAD_BASE
            if img in labels and img not in frags:
                for n in labels[img]:
                    f.write("%s:\n" % n)
            if img in fns and img not in frags:
                f.write("%s:\n" % fname(img))
            if img in frags:
                f.write(_force_long(open(frags[img]).read()))
                if not open(frags[img]).read().endswith("\n"):
                    f.write("\n")
                pos = a + flen[img]
            elif in_res(a):
                if fixes:
                    relocs.emit_bytes(f, orig[a:b], a, fixes, names)
                else:
                    emit_bytes(f, orig[a:b])
                pos = b
            else:
                pos = a
        if pos < tlen:
            f.write("\tdcb.b %d,0\n" % (tlen - pos))
    return flen


def run(cmd, cwd):
    p = subprocess.run(cmd, cwd=cwd, capture_output=True)
    if p.returncode != 0:
        sys.stderr.write("FALLO: %s\n%s%s\n" % (
            " ".join(cmd),
            p.stdout.decode("latin1"), p.stderr.decode("latin1")))
        raise SystemExit(1)
    return p


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--toolchain", default=os.environ.get(
        "ALCYON", os.path.join(ROOT, "matching", "toolchain", "bin", "linux")))
    ap.add_argument("--prg", default=os.path.join(ROOT, "work", "disk_a", "KULT.PRG"))
    ap.add_argument("--layout", default=os.path.join(ROOT, "matching", "layout.json"))
    ap.add_argument("--keep", action="store_true")
    ns = ap.parse_args()

    as68 = os.path.join(ns.toolchain, "as68")
    if not os.path.exists(as68):
        sys.exit("No encuentro as68 en %s\nEjecuta matching/setup_toolchain.sh" % ns.toolchain)
    link68 = os.path.join(ns.toolchain, "link68")
    relmod = os.path.join(ns.toolchain, "relmod")

    layout = json.load(open(ns.layout))
    prg = open(ns.prg, "rb").read() if os.path.exists(ns.prg) else None
    data_blob = load_data_blob(layout, layout["header"]["tlen"])
    frags = load_fragments()
    fns = parse_functions()
    globals_ = parse_globals()
    tlen = layout["header"]["tlen"]
    labels = {}
    autoequ = []
    for src in (globals_, load_symbols()):
        for a, names in src.items():
            tr = a - LOAD_BASE
            if 0 <= tr < tlen:
                labels.setdefault(a, []).extend(names)
            else:
                for n in names:
                    autoequ.append((tr & 0xffffffff, n))
    equ_txt = load_equ()
    equ = autoequ + [(v, n) for v, n, _ in equ_txt]

    # derivacion de relocs: TODO desde la fuente (codigo + tablas de datos
    # transcritas en data_*.s); si hay PRG se usa la tabla completa como
    # comprobacion. Ya no hay semilla (B2-estricto via tablas en fuente).
    fixes, names = relocs.analyze(prg) if prg is not None else (set(), {})
    existing = set(relocs.load_namemap().values())
    refs = source_identifiers(frags)
    # destinos relocalizables: globals fuera del text (direcciones) + los `addr`
    # de equ.txt. Los `const` quedan absolutos. (Intencion de la fuente, B2-lite.)
    target_vals = set(v for v, _ in autoequ) | set(v for v, _, k in equ_txt if k == "addr")
    newdefs = source_newdefs(refs, names, existing)

    out = os.path.join(ROOT, "matching", "out")
    os.makedirs(out, exist_ok=True)
    sfile = os.path.join(out, "kult.s")
    print("asm: %s  (funciones=%d fragmentos=%d etiquetas=%d equ=%d destinos=%d nuevos=%d)"
          % (sfile, len(fns), len(frags), len(labels), len(equ), len(target_vals), len(newdefs)))
    flen = build_asm(layout, prg, frags, fns, labels, equ, as68, sfile,
                     target_vals=target_vals, newdefs=newdefs, fixes=fixes, names=names,
                     data_blob=data_blob)

    run([as68, "-u", "-L", "-n", "kult.s"], out)
    run([link68, "[]", "kult.rel=kult.o"], out)
    run([relmod, "kult.rel", "KULT.PRG"], out)
    built = os.path.join(out, "KULT.PRG")
    if prg is not None:
        print("PRG: %s (%d bytes; original %d)" % (built, os.path.getsize(built), len(prg)))
        print("sha256 original=%s" % hashlib.sha256(prg).hexdigest())
    else:
        print("PRG: %s (%d bytes; sin original para comparar)" % (built, os.path.getsize(built)))
    print("sha256 built   =%s" % hashlib.sha256(open(built, "rb").read()).hexdigest())

    # veredicto: contar bytes iguales en cada region de datos y en cada fragmento
    ok, bad = 0, []
    if prg is not None:
        bt = open(built, "rb").read()[TEXT_OFF:]
        for addr, size in [(r["image_addr"], r["size"]) for r in layout["resources_embedded"]]:
            o = addr - LOAD_BASE
            if bt[o:o + size] == prg[TEXT_OFF + o:TEXT_OFF + o + size]:
                ok += 1
            else:
                bad.append("dato 0x%06x (%d B)" % (addr, size))
        for addr in sorted(frags):
            o = addr - LOAD_BASE
            ln = flen[addr]
            if bt[o:o + ln] == prg[TEXT_OFF + o:TEXT_OFF + o + ln]:
                ok += 1
            else:
                bad.append("func 0x%06x (%d B)" % (addr, ln))
        print("REGIONES OK=%d  MAL=%d %s" % (ok, len(bad), bad if bad else ""))

    if not ns.keep:
        for x in ("kult.o", "kult.rel", "kult.s"):
            p = os.path.join(out, x)
            if os.path.exists(p):
                os.remove(p)
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
