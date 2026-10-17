# Build *matching* de Kult (ruta ASM). Ver docs/PLAN_MATCHING_DECOMP.md y matching/README.md.
#
#   make vasm     -> reconstruye un KULT.PRG BYTE-IDÉNTICO al original (pipeline vasm)
#   make regen    -> regenera auto_*.s desde el PRG original (dev; NO hace falta para build)
#   make gendata  -> regenera data_*.s (tablas de punteros en recursos) desde el PRG (dev)
#   make layout   -> regenera matching/layout.json (anclajes)
#   make data     -> build incremental de los bloques de datos (M1.1)
#   make ingest   -> extrae los recursos embebidos a matching/data/ (B1b)
#   make setup    -> descarga el toolchain Alcyon en matching/toolchain
#   make check    -> compara el PRG reconstruido con el original
#
# Variables:
#   PRG   original (por defecto work/disk_a/KULT.PRG)
#   PY    interprete python (por defecto python3)

ROOT   := $(abspath $(CURDIR)/..)
PRG    ?= $(ROOT)/work/disk_a/KULT.PRG
PY     ?= python3

.PHONY: vasm regen gendata layout data ingest indep setup check

vasm:
	$(PY) build_vasm.py

regen:
	$(PY) build_vasm.py --regen

gendata:
	$(PY) $(ROOT)/tools/gen_data_tables.py --prg $(PRG)

layout:
	$(PY) $(ROOT)/tools/match_layout.py --prg $(PRG)

data:
	$(PY) build.py --prg $(PRG)

ingest:
	$(PY) $(ROOT)/tools/ingest_data.py --prg $(PRG)

# B3: build sin KULT.PRG (arbol autocontenido) -> sha256 identico
indep:
	sh verify_independent.sh

setup:
	sh setup_toolchain.sh

check:
	$(PY) $(ROOT)/tools/match_check.py $(PRG) out/KULT.PRG
