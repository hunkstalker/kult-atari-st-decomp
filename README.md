# kult-atari-st-decomp — decompilación *matching* de KULT (Atari ST)

Reconstruye un `KULT.PRG` **byte a byte idéntico** al original de 1989 (Exxos/ERE)
`sha256 2e85f223167439425ab2096bd21716de135f9b472bde90f4d40e8b0e03132fe6`, **a
partir de la fuente** (código ASM + tablas de datos transcritas), sin leer el
binario original en el *build*.

> **Este repo (A) es solo el decomp en ensamblador (ASM)**: la verdad byte a byte.
> La **reimplementación en C legible** (a partir de este ASM) vive en un repo
> aparte: **`/app/kult-atari-st-c`** (proyecto B). Aquí no hay C.

## Cómo se construye

```sh
cd matching
sh setup_toolchain.sh           # descarga Alcyon/tos1x + compila vasm (una vez)
python3 ../tools/ingest_data.py # extrae matching/data/ de TU copia de KULT.PRG (assets)
make vasm                       # -> KULT.PRG byte-idéntico (sin el PRG original)
make indep                      # verifica el build desde git archive HEAD, sin el PRG
```

- El **código** sale de `matching/src/*.s` (manuales + `auto_*.s` desensamblados,
  versionados).
- Las **tablas de datos** de recursos salen de `matching/src/data_*.s`
  (transcritas por RE; ver `matching/RELOCS.md`).
- Los **assets** (sprites, sonido, textos…) se **ingestan** de la copia del
  usuario a `matching/data/` (gitignored; **no se distribuyen**).

## Contenido

- `matching/` — reconstrucción **ASM byte a byte** (código + tablas de datos).
  **Es la especificación** que lee el proyecto C.
- `tools/` — utilidades del matching (`prg_dis`, `match_check`, `ingest_data`,
  `gen_data_tables`, …).
- `docs/` — referencia técnica.
- `work/` — índice (`decomp.c`) y nombres (`names.txt`); el PRG es gitignored.

> **Relación con el proyecto C (B):** B (`/app/kult-atari-st-c`) **parte de este
> ASM** y escribe la reimplementación en C (fiel en comportamiento, no byte a
> byte). El intento previo de C (heredado de kult-port) se descartó; el estado de
> ese análisis queda en `docs/` de B.

## Documentación

- `matching/README.md` — estado/método.
- `matching/RELOCS.md` — derivación de la tabla de relocalizaciones.
- `docs/MATCHING_DEV.md` — referencia técnica (formato PRG/DRI, pipeline, RE).
- `docs/PLAN_MATCHING_DECOMP.md`, `docs/MATCHING_BUILD.md` — plan y toolchain.

## Legal

El juego sigue bajo copyright (Piko Interactive). **No** se distribuyen assets ni
binarios del juego; el usuario aporta su copia. Todo lo derivado del juego
(`matching/data/`, `work/disk_*`, el `.PRG`) está en `.gitignore`.
