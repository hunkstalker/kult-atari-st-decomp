#!/usr/bin/env python3
"""Regresión de `tools/match_check.py` y `tools/match_region.py`.

Auto-contenido: fabrica PRGs sintéticos mínimos para no depender de assets con
copyright. Comprueba los veredictos de ambos comparadores. Se ejecuta con
python3 del sistema (solo stdlib; capstone es opcional).
"""
import contextlib
import io
import os
import struct
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import match_check  # noqa: E402
import match_region  # noqa: E402
import prg_dis  # noqa: E402

HEADER = ">HIIIIIIH"


def make_prg(text):
    # magic 0x601A, tlen, dlen=0, blen=0, slen=0, res=0, flags=0, absflag=0
    return struct.pack(HEADER, 0x601A, len(text), 0, 0, 0, 0, 0, 0) + text


def run_case(orig, cand, expect):
    with tempfile.TemporaryDirectory() as d:
        op = os.path.join(d, "o.prg")
        cp = os.path.join(d, "c.prg")
        open(op, "wb").write(orig)
        open(cp, "wb").write(cand)
        with contextlib.redirect_stdout(io.StringIO()):
            rc = match_check.compare(op, cp, 0x10000)
    assert rc == expect, "match_check: esperado %d, obtenido %d" % (expect, rc)


def run_region(orig, cand, extra):
    with tempfile.TemporaryDirectory() as d:
        op = os.path.join(d, "o.prg")
        cp = os.path.join(d, "c.bin")
        open(op, "wb").write(orig)
        open(cp, "wb").write(cand)
        with contextlib.redirect_stdout(io.StringIO()):
            return match_region.main([op, cp] + extra)


def main():
    text = bytes.fromhex("4e7500006010")  # rts + datos
    base = make_prg(text)

    # 1) idénticos -> 0
    run_case(base, base, 0)

    # 2) un byte mutado en el text -> 1
    mut = bytearray(base)
    mut[28 + 2] ^= 0xFF
    run_case(base, bytes(mut), 1)

    # 3) tamaños distintos -> 1
    run_case(base, make_prg(text + b"\x00"), 1)

    # 4) el parser de relocs no debe romper con un text sin tabla
    h = prg_dis.parse_header(base)
    assert h["tlen"] == len(text)

    # 5) match_region: región que coincide -> 0
    assert run_region(base, text[:4], ["--addr", "0x10000"]) == 0

    # 6) match_region: byte distinto -> 1
    assert run_region(base, bytes([0xFF, 0, 0, 0]), ["--addr", "0x10000"]) == 1

    # 7) match_region: hueco que cubre el byte distinto -> 0
    assert run_region(base, bytes([0xFF, 0, 0, 0]),
                      ["--addr", "0x10000", "--holes", "0x10000:0x10004"]) == 0

    print("test_match_check: OK (7 casos)")


if __name__ == "__main__":
    main()
