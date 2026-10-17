#!/bin/sh
# verify_independent.sh — B3: comprueba que el build NO necesita KULT.PRG.
#
# Copia SOLO los ficheros versionados (`git archive HEAD`) a un directorio
# temporal, sin el PRG original, enlaza el toolchain y los datos ingestados
# (assets, gitignored) y construye. El sha256 debe coincidir con el original.
#
# Uso: matching/verify_independent.sh
set -e

HERE=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
ROOT=$(CDPATH= cd -- "$HERE/.." && pwd)
WANT="2e85f223167439425ab2096bd21716de135f9b472bde90f4d40e8b0e03132fe6"

TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT

echo "== B3: arbol autocontenido (git archive HEAD, sin KULT.PRG) =="
git -C "$ROOT" archive HEAD | tar -x -C "$TMP"

# el PRG original NO debe estar (no esta versionado; por si acaso)
if [ -e "$TMP/work/disk_a/KULT.PRG" ]; then
    echo "ERROR: el arbol versionado incluye KULT.PRG" >&2
    exit 1
fi

# toolchain (vasm/as68) y datos ingestados: no versionados -> enlazar
ln -s "$ROOT/matching/toolchain" "$TMP/matching/toolchain"
if [ ! -d "$ROOT/matching/data" ]; then
    echo "ERROR: falta matching/data (ejecuta: python3 tools/ingest_data.py)" >&2
    exit 1
fi
ln -s "$ROOT/matching/data" "$TMP/matching/data"

echo "-- construyendo sin el PRG --"
OUT=$(cd "$TMP/matching" && python3 build_vasm.py 2>&1)
echo "$OUT" | tail -4

GOT=$(printf '%s\n' "$OUT" | sed -n 's/^sha256: *//p' | tail -1)
if [ "$GOT" = "$WANT" ]; then
    echo "OK: build independiente del PRG (sha256 $GOT)"
else
    echo "FALLO: sha256 $GOT != $WANT" >&2
    exit 1
fi
