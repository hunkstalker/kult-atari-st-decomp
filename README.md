# kult-st — decompilación *matching* de KULT (Atari ST)

Reconstruye un `KULT.PRG` **byte a byte idéntico** al original de 1989 (Exxos/ERE)
`sha256 2e85f223167439425ab2096bd21716de135f9b472bde90f4d40e8b0e03132fe6`, **a
partir de la fuente** (código ASM + tablas de datos transcritas), sin leer el
binario original en el *build*.

> Proyecto independiente (un repo por decomp). El core/motor nativo multi-versión
> se construye aparte.

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

## Documentación

- `matching/README.md` — estado/método.
- `matching/RELOCS.md` — derivación de la tabla de relocalizaciones.
- `docs/MATCHING_DEV.md` — referencia técnica (formato PRG/DRI, pipeline, RE).
- `docs/PLAN_MATCHING_DECOMP.md`, `docs/MATCHING_BUILD.md` — plan y toolchain.

## Legal

El juego sigue bajo copyright (Piko Interactive). **No** se distribuyen assets ni
binarios del juego; el usuario aporta su copia. Todo lo derivado del juego
(`matching/data/`, `work/disk_*`, el `.PRG`) está en `.gitignore`.
