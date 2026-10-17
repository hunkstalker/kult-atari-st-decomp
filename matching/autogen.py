#!/usr/bin/env python3
"""Autogenera fragmentos ASM desde el desensamblado (matching por byte).

Para cada funcion del indice aun no reconstruida a mano, desensambla su rango y
emite asm compatible con `as68`, con **nombres de etiqueta consistentes** con el
resto del proyecto:

  - funciones (`fns`, manifest manual, symbols con `f_`) -> `f_%06x`
  - simbolos de datos (`symbols.txt`)                    -> `s_<hex>`
  - globals (`addrs.h`)                                  -> `A_...`
  - destinos internos                                    -> `l_%06x`

Las referencias absolutas se dejan tal cual (`$xxxx.l`): byte-exactas. Las
relocs se resuelven en una fase posterior. Escribe `autogen.txt` (manifest).
"""
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import capstone  # noqa: E402
import prg_dis  # noqa: E402
sys.path.append(os.path.join(ROOT, "matching"))
import build as _build  # noqa: E402
import relocs  # noqa: E402

TEXT_OFF = 28
LOAD_BASE = 0x10000
FIXES = set()
NAMES = {}
RE_IDX = re.compile(r"^//\s+([0-9a-fA-F]{8})\s+(\S+)\s+(\d+) bytes", re.M)
RE_ADDR = re.compile(r"^#define\s+(A_\w+)\s+0x([0-9a-fA-F]+)")
BR = re.compile(r"^b(?!tst|set|clr|chg|f$|f\b|t\b|t$)")
_MD = capstone.Cs(capstone.CS_ARCH_M68K, capstone.CS_MODE_BIG_ENDIAN)

NAMEMAP = {}


def name_of(addr):
    return NAMEMAP.get(addr) or ("l_%06x" % addr)


def collect_targets(ins, start, end):
    ts = set()
    for i in ins:
        mn = i.mnemonic
        if BR.match(mn) or mn.startswith("db"):
            m = re.search(r"\$([0-9a-f]+)\s*$", i.op_str)
            if m:
                ts.add(int(m.group(1), 16))
        for m in re.finditer(r"\$([0-9a-f]+)\(pc\)", i.op_str):
            ts.add(int(m.group(1), 16))
    return ts


def _long_fields(data, addr):
    """Offsets (text-relativos) de los campos de 4 bytes (abs.l / inmediato largo)
    de la instruccion en `addr`, via `prg_dis.decode` instrumentado."""
    recs = []
    orig = prg_dis._reloc_long

    def rec(dd, p, fx, ba):
        recs.append(p - TEXT_OFF)
        return orig(dd, p, fx, ba)

    prg_dis._reloc_long = rec
    try:
        prg_dis.decode(data, TEXT_OFF + addr - LOAD_BASE, LOAD_BASE)
    except Exception:
        pass
    finally:
        prg_dis._reloc_long = orig
    return recs


def _subst_relocs(data, addr, ops):
    """Sustituye los literales de campos largos que son destinos de reloc por su
    simbolo (expresion relocalizable), para que vasm emita la reloc."""
    repls = []
    for fo in _long_fields(data, addr):
        if fo in FIXES:
            v = int.from_bytes(data[TEXT_OFF + fo:TEXT_OFF + fo + 4], "big")
            nm = NAMES.get(v)
            if nm:
                repls.append([v, nm])

    def sub(m):
        v = int(m.group(1), 16)
        for r in repls:
            if r[0] == v:
                r[0] = None
                return r[1]
        return m.group(0)

    return re.sub(r"\$([0-9a-fA-F]+)(\.l|\.w)?", sub, ops)


def _render_ins(data, i, start, gtargets, emit_labels=True):
    out = []
    if emit_labels and i.address == start:
        out.append("f_%06x:\n" % start)
    elif emit_labels and (i.address in NAMEMAP or i.address in gtargets):
        out.append("%s:\n" % name_of(i.address))
    mn, ops = i.mnemonic, i.op_str
    # immediato de tamano .b: usar la palabra real (capstone solo da el byte)
    if mn in ("move.b","addi.b","subi.b","andi.b","ori.b","eori.b","cmpi.b") and ops.lstrip().startswith("#") and len(i.bytes) >= 4:
        word = (i.bytes[2] << 8) | i.bytes[3]
        ops = re.sub(r"#\$[0-9a-fA-F]+", "#$%04x" % word, ops, count=1)
    # referencias a destinos de reloc -> simbolo (relocalizable)
    if FIXES:
        ops = _subst_relocs(data, i.address, ops)
    if mn in ("bra", "bsr"):
        m = re.search(r"\$([0-9a-f]+)\s*$", ops)
        if m:
            ops = ops[:m.start()] + name_of(int(m.group(1), 16))
    elif mn.startswith("db"):
        m = re.search(r",\s*\$([0-9a-f]+)\s*$", ops)
        if m:
            ops = ops[:m.start(1) - 1] + name_of(int(m.group(1), 16))
    elif BR.match(mn) and mn not in ("btst", "bset", "bclr", "bchg"):
        m = re.search(r"\$([0-9a-f]+)\s*$", ops)
        if m:
            ops = ops[:m.start()] + name_of(int(m.group(1), 16))
    def _fixpc(m, addr=i.address):
        t = int(m.group(1), 16)
        rest = m.group(2)
        if rest[0] == ")":
            return "$%x(pc)" % ((t - (addr + 2)) & 0xffff)
        return "$%x(pc%s" % ((t - (addr + 2)) & 0xff, rest)
    ops = re.sub(r"\$([0-9a-f]+)\(pc(\s*[,)])", _fixpc, ops)
    out.append("\t%s\t%s\n" % (mn, ops))
    return "".join(out)


def _dcb(data, a, b):
    raw = data[TEXT_OFF + a - LOAD_BASE: TEXT_OFF + b - LOAD_BASE]
    out = []
    for k in range(0, len(raw), 16):
        out.append("\tdc.b\t" + ",".join("$%02x" % x for x in raw[k:k + 16]) + "\n")
    return "".join(out)


def gen_range(data, start, end, gtargets):
    """Emite el rango [start,end) (direcciones runtime) byte-exacto.

    - Instrucciones decodificadas (capstone); los campos largos que son destinos
      de reloc se escriben con su simbolo.
    - Punteros incrustados en datos (posiciones de reloc que no son campo de
      instruccion): `dc.l <simbolo>`.
    - El resto, `dc.b`. Todas las etiquetas (funciones/gtargets/NAMEMAP) se
      insertan en su direccion exacta.
    """
    ins = list(_MD.disasm(data[TEXT_OFF + start - LOAD_BASE: TEXT_OFF + end - LOAD_BASE], start))
    ins_by = {i.address: i for i in ins}
    handled = set()
    for i in ins:
        for fo in _long_fields(data, i.address):
            if fo in FIXES and NAMES.get(int.from_bytes(data[TEXT_OFF + fo:TEXT_OFF + fo + 4], "big")):
                handled.add(fo)
    s_off, e_off = start - LOAD_BASE, end - LOAD_BASE
    data_pos = set(fo + LOAD_BASE for fo in FIXES if s_off <= fo < e_off and fo not in handled)
    label_pos = sorted(set(t for t in gtargets if start <= t < end)
                       | set(t for t in NAMEMAP if start <= t < end) | {start})
    events = set(ins_by) | data_pos | set(label_pos)
    out = []
    li = 0

    def flush_labels(upto):
        nonlocal li
        while li < len(label_pos) and label_pos[li] <= upto:
            out.append("%s:\n" % name_of(label_pos[li]))
            li += 1

    pos = start
    while pos < end:
        if pos in data_pos:
            flush_labels(pos)
            off = TEXT_OFF + pos - LOAD_BASE
            out.append("\tdc.l\t%s\n" % NAMES[int.from_bytes(data[off:off + 4], "big")])
            pos += 4
            continue
        i = ins_by.get(pos)
        if i is not None and pos + i.size <= end and not any(pos < dp < pos + i.size for dp in data_pos):
            flush_labels(pos)
            out.append(_render_ins(data, i, start, gtargets, emit_labels=False))
            pos += i.size
            continue
        if i is not None and pos + i.size <= end:  # la instruccion cruza un puntero
            nxt = min(dp for dp in data_pos if pos < dp < pos + i.size)
            flush_labels(pos)
            out.append(_dcb(data, pos, nxt))
            pos = nxt
            continue
        nxt = min([end] + [x for x in events if x > pos])
        flush_labels(pos)
        out.append(_dcb(data, pos, nxt))
        pos = nxt
    flush_labels(end)
    return "".join(out)


def build_namemap(fns):
    # funciones
    for a in fns:
        NAMEMAP[a] = "f_%06x" % a
    # manual manifest
    for man in ("manifest.txt",):
        p = os.path.join(ROOT, "matching", "src", man)
        if os.path.exists(p):
            for line in open(p):
                line = line.strip()
                if line and not line.startswith("#"):
                    a = int(line.split()[0], 0)
                    NAMEMAP.setdefault(a, "f_%06x" % a)
    # symbols.txt (s_ names)
    p = os.path.join(ROOT, "matching", "src", "symbols.txt")
    if os.path.exists(p):
        for line in open(p):
            line = line.strip()
            if line and not line.startswith("#"):
                a, n = line.split()[:2]
                NAMEMAP.setdefault(int(a, 0), n)
    # addrs.h (A_ names)
    p = os.path.join(ROOT, "matching", "include", "addrs.h")
    if os.path.exists(p):
        for line in open(p):
            m = RE_ADDR.match(line.rstrip())
            if m:
                NAMEMAP.setdefault(int(m.group(2), 16), m.group(1))


def main():
    global FIXES, NAMES
    d = open(os.path.join(ROOT, "work", "disk_a", "KULT.PRG"), "rb").read()
    FIXES, NAMES = relocs.analyze(d)
    layout = json.load(open(os.path.join(ROOT, "matching", "layout.json")))
    fns = {}
    for m in RE_IDX.finditer(open(os.path.join(ROOT, "work", "decomp.c"), encoding="latin1").read()):
        fns[int(m.group(1), 16)] = m.group(2)
    build_namemap(fns)
    done = set()
    for man in ("manifest.txt",):
        p = os.path.join(ROOT, "matching", "src", man)
        if os.path.exists(p):
            for line in open(p):
                line = line.strip()
                if line and not line.startswith("#"):
                    done.add(int(line.split()[0], 0))

    resources = [(r["image_addr"], r["image_addr"] + r["size"]) for r in layout["resources_embedded"]]
    res_starts = sorted(s for s, _ in resources)

    def in_res(a):
        return any(s <= a < e for s, e in resources)

    END = LOAD_BASE + layout["header"]["tlen"]
    anchors = sorted(a for a in fns if not in_res(a))
    # spans de los fragmentos manuales (medidos)
    as68 = os.path.join(ROOT, "matching", "toolchain", "bin", "linux", "as68")
    hand_spans = []
    tmp = None
    if os.path.exists(as68):
        import tempfile
        tmp = tempfile.mkdtemp()
        for man in ("manifest.txt",):
            p = os.path.join(ROOT, "matching", "src", man)
            if os.path.exists(p):
                for line in open(p):
                    line = line.strip()
                    if line and not line.startswith("#"):
                        a = int(line.split()[0], 0)
                        f = os.path.join(ROOT, "matching", "src", line.split()[1])
                        ln = _build.measure_fragment(f, as68, tmp)
                        hand_spans.append((a, a + ln))

    def inside_hand(a):
        return any(s < a < e for s, e in hand_spans)

    auto_anchors = sorted(a for a in anchors if a not in done and not inside_hand(a))
    hand_starts = set(s for s, _ in hand_spans)
    boundset = set(auto_anchors) | hand_starts | set(res_starts) | {END}

    def next_boundary(p):
        return min(x for x in boundset if x > p)

    # rangos codiciosos: cada uno termina en una frontera que ademas es fin de instruccion
    ranges = []
    i = 0
    while i < len(auto_anchors):
        a = auto_anchors[i]
        pos = a
        while True:
            ins = next(iter(_MD.disasm(d[TEXT_OFF + pos - LOAD_BASE: TEXT_OFF + END - LOAD_BASE], pos)), None)
            if ins is None:  # datos o fuera: cerrar en la siguiente frontera
                pos = next_boundary(pos)
                break
            pos += ins.size
            if pos in boundset:
                break
            if pos >= END:
                break
        end = pos
        ranges.append((a, end))
        while i < len(auto_anchors) and auto_anchors[i] < end:
            i += 1

    gtargets = set()
    for a, nxt in ranges:
        ins = list(_MD.disasm(d[TEXT_OFF + a - LOAD_BASE: TEXT_OFF + nxt - LOAD_BASE], a))
        gtargets |= collect_targets(ins, a, nxt)

    entries = []
    for a, nxt in ranges:
        if len(list(_MD.disasm(d[TEXT_OFF + a - LOAD_BASE: TEXT_OFF + nxt - LOAD_BASE], a))) == 0:
            continue
        src = gen_range(d, a, nxt, gtargets)
        name = "auto_%06x.s" % a
        open(os.path.join(ROOT, "matching", "src", name), "w").write(src)
        entries.append("%#x   %s   %#x" % (a, name, nxt - a))

    with open(os.path.join(ROOT, "matching", "src", "autogen.txt"), "w") as f:
        f.write("# generado por autogen.py\n")
        f.write("\n".join(entries) + "\n")
    print("autogen: %d fragmentos" % len(entries))


if __name__ == "__main__":
    main()
