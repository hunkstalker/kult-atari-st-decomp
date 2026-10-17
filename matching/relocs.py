#!/usr/bin/env python3
"""Derivación de la tabla de relocalizaciones (opción A de `matching/RELOCS.md`).

Idea: en un PRG TOS relocalizable, el enlazador/ensamblador emite **una reloc por
cada referencia absoluta de 32 bits a una etiqueta**. vasm `-Ftos` ya emite esa
tabla. Por tanto, si cada **destino** de reloc del original tiene un **símbolo**
(definido como expresión relocalizable `f_010000±$c`) y en la fuente cada
operando largo/inmediato que apunta a ese destino se escribe con el **símbolo**
(no el literal `$xxxx.l`), vasm reproduce la tabla exacta. Las posiciones las
decide el ensamblador, no nosotros: no se copia la tabla.

Sembrado (permitido por RELOCS.md): el **conjunto de destinos** (el valor de cada
entrada de reloc del original) se usa para saber qué direcciones necesitan
símbolo. La *estructura* de la tabla (offsets, encoding DRI) la genera vasm.

Nombres: se reutiliza el nombre ya conocido del destino (función `f_*`, global
`A_*`, símbolo `s_*`, `equ`) si existe; si no, `s_%06x` (dirección runtime).
"""
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TEXT_OFF = 28
LOAD_BASE = 0x10000
TEXTBASE = "f_010000"
RE_IDX = re.compile(r"^//\s+([0-9a-fA-F]{8})\s+(\S+)\s+(\d+) bytes", re.M)
RE_ADDR = re.compile(r"^#define\s+(A_\w+)\s+0x([0-9a-fA-F]+)")


def _prg_dis():
    sys.path.insert(0, os.path.join(ROOT, "tools"))
    import prg_dis
    return prg_dis


def rd32(b, p):
    return int.from_bytes(b[p:p + 4], "big")


def load_namemap():
    """runtime_addr -> nombre, de todas las fuentes (funciones, symbols, addrs, equ)."""
    m = {}
    decomp = os.path.join(ROOT, "work", "decomp.c")
    if os.path.exists(decomp):
        for mm in RE_IDX.finditer(open(decomp, encoding="latin1").read()):
            m.setdefault(int(mm.group(1), 16), "f_%06x" % int(mm.group(1), 16))
    for fn in ("manifest.txt",):
        p = os.path.join(ROOT, "matching", "src", fn)
        if os.path.exists(p):
            for line in open(p):
                line = line.strip()
                if line and not line.startswith("#"):
                    a = int(line.split()[0], 0)
                    m.setdefault(a, "f_%06x" % a)
    p = os.path.join(ROOT, "matching", "src", "symbols.txt")
    if os.path.exists(p):
        for line in open(p):
            line = line.strip()
            if line and not line.startswith("#"):
                a, n = line.split()[:2]
                m.setdefault(int(a, 0), n)
    p = os.path.join(ROOT, "projects", "kult", "recreate", "include", "addrs.h")
    if os.path.exists(p):
        for line in open(p):
            mm = RE_ADDR.match(line.rstrip())
            if mm:
                m.setdefault(int(mm.group(2), 16), mm.group(1))
    p = os.path.join(ROOT, "matching", "src", "equ.txt")
    if os.path.exists(p):
        for line in open(p):
            line = line.strip()
            if line and not line.startswith("#"):
                v, n = line.split()[:2]
                m.setdefault(int(v, 0) & 0xffffffff, n)
    return m


def analyze(prg_bytes):
    """(fixes, names) desde la tabla del PRG (solo para autogen/regen): `fixes` =
    offsets de reloc (text-rel, set); `names` = valor de destino -> símbolo.

    El *build* no usa esto: deriva los símbolos de la fuente (código en `auto_*.s`
    y tablas de datos en `data_*.s`). Ver `matching/RELOCS.md`."""
    prg_dis = _prg_dis()
    h = prg_dis.parse_header(prg_bytes)
    pairs = [(fx, rd32(prg_bytes, TEXT_OFF + fx))
             for fx in sorted(prg_dis.parse_reloc(prg_bytes, h))]
    fixes = set(fx for fx, _ in pairs)
    namemap = load_namemap()
    names = {}
    for _fx, v in pairs:
        rt = (v + LOAD_BASE) & 0xffffffff
        name = namemap.get(rt) or ("s_%06x" % rt if rt <= 0xffffff else "s_%08x" % rt)
        names.setdefault(v, name)
    return fixes, names



def is_target_sym_equ(name):
    """¿es un símbolo nuevo (no definido ya como etiqueta)? -> se emite como equ."""
    return True


def def_expr(value, name):
    """`name equ f_010000±$c` (expresión relocalizable; NO absoluta)."""
    if value < 0x80000000:
        return "%s\tequ\t%s+$%x\n" % (name, TEXTBASE, value)
    return "%s\tequ\t%s-$%x\n" % (name, TEXTBASE, 0x100000000 - value)


def emit_dc_l(f, value, name):
    """Emite un longword relocalizable a un símbolo."""
    f.write("\tdc.l\t%s\n" % name)


def emit_bytes(f, data, base_img, fixes, names, rd32fn=None):
    """Como build.emit_bytes pero convierte a `dc.l <símbolo>` los longwords que son
    posiciones de reloc; el resto se emite con dc.b/dcb.b (byte-exacto)."""
    i, n = 0, len(data)
    while i < n:
        here = base_img + i  # offset text-relativo de data[i]
        if here in fixes:
            v = rd32(data, i)
            name = names.get(v)
            if name:
                emit_dc_l(f, v, name)
                i += 4
                continue
        if data[i] == 0:
            j = i
            while j < n and data[j] == 0 and (base_img + j) not in fixes:
                j += 1
            f.write("\tdcb.b\t%d,0\n" % (j - i))
            i = j
        else:
            j = i
            while j < n and data[j] != 0 and (base_img + j) not in fixes:
                j += 1
            run = data[i:j]
            for k in range(0, len(run), 16):
                row = run[k:k + 16]
                f.write("\tdc.b\t" + ",".join("$%02x" % b for b in row) + "\n")
            i = j
