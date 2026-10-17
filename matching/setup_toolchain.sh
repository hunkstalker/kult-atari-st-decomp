#!/bin/sh
# Prepara el toolchain Alcyon/DRI para el build *matching* de Kult.
#
#   matching/setup_toolchain.sh [dir]     (por defecto: matching/toolchain)
#
# En Alpine/musl hace falta `gcompat` (los binarios son glibc). El toolchain
# viene de th-otto/tos1x (bin/linux), que a su vez conserva los Alcyon del
# developer kit. Ver docs/MATCHING_BUILD.md §1.1.
set -e

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
DEST=${1:-"$ROOT/toolchain"}

if ! command -v apk >/dev/null 2>&1; then
    echo "AVISO: no hay apk; asegurate de tener gcompat (Alpine) o glibc." >&2
else
    apk add --no-cache gcompat >/dev/null 2>&1 || apk add --no-cache gcompat
fi

if [ ! -x "$DEST/bin/linux/as68" ]; then
    echo "Clonando th-otto/tos1x en $DEST ..."
    rm -rf "$DEST"
    git clone --depth 1 https://github.com/th-otto/tos1x "$DEST"
else
    echo "Toolchain ya presente en $DEST"
fi

# vasm (ensamblador portable; el build matching usa vasm porque el as68 del kit
# tiene un bug de fase con el programa completo).
if [ ! -x "$DEST/bin/vasmm68k_mot" ]; then
    echo "Compilando vasm 2.0f ..."
    tmp=$(mktemp -d)
    wget -q http://sun.hasenbraten.de/vasm/release/vasm.tar.gz -O "$tmp/vasm.tar.gz"
    tar xzf "$tmp/vasm.tar.gz" -C "$tmp"
    make -C "$tmp/vasm" CPU=m68k SYNTAX=mot >/dev/null
    cp "$tmp/vasm/vasmm68k_mot" "$DEST/bin/vasmm68k_mot"
    rm -rf "$tmp"
else
    echo "vasm ya presente en $DEST/bin/vasmm68k_mot"
fi

echo
echo "Listo. Usa:"
echo "  export PATH=$DEST/bin/linux:$DEST/bin:\$PATH"
echo "  matching/build_vasm.py        # PRG byte-identico"
