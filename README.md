# KULT: The Temple of Flying Saucers — decompilación *matching* (Atari ST)

Reconstrucción en ensamblador del motor de **KULT: The Temple of Flying Saucers**
(Exxos/ERE, 1989) que se ensambla y enlaza a un `KULT.PRG` **byte a byte idéntico**
al original:

```text
sha256  2e85f223167439425ab2096bd21716de135f9b472bde90f4d40e8b0e03132fe6
size    184.291 B
text    0x2C534
relocs  2.171 / 2.171
```

El *build* es **reproducible desde la fuente**: código ASM reconstruido, tablas de
datos transcritas y recursos ingestados de una copia **legal** del juego. No se
lee el binario original durante el *build* (`make indep` lo verifica).

> **Proyecto no oficial** de preservación e ingeniería inversa. No está afiliado
> a los titulares de los derechos de KULT. **No se distribuyen assets ni
> binarios del juego**; ver [Legal y licencia](#legal-y-licencia).

Este repositorio contiene **solo la decompilación ASM**. La reimplementación en C
legible vive en un repositorio aparte:

- [`kult-atari-st-c`](https://github.com/hunkstalker/kult-atari-st-c) — reimplementación en C fiel en comportamiento.

## Estado

- **`make vasm`**: reconstruye `KULT.PRG` y coincide byte a byte con el original.
- **`make indep`**: verifica el *build* desde `git archive HEAD`, sin el PRG.
- **`make check`**: compara el PRG reconstruido con la copia del usuario.
- El motor del juego es **ASM escrito a mano**; el `crt0` y la música `0x3axxx`
  son C de Alcyon. Detalle en `docs/MATCHING_BUILD.md` y `matching/README.md`.

## Requisitos

- Linux (probado en x86-64; el toolchain de Alcyon es glibc).
- Python 3, `git`, `make`, `gcc`, `wget`.
- En Alpine/musl: `gcompat` (lo instala `matching/setup_toolchain.sh` si hay `apk`).
- Una copia **legal** de `KULT.PRG` (Atari ST). No se incluye en el repo.

## Build rápido

```sh
git clone https://github.com/hunkstalker/kult-atari-st-decomp.git
cd kult-atari-st-decomp

# El PRG es tu copia; queda en work/disk_a/ (gitignored).
mkdir -p work/disk_a
cp /ruta/a/KULT.PRG work/disk_a/KULT.PRG

# Recursos embebidos -> matching/data/ (gitignored)
python3 tools/ingest_data.py --prg work/disk_a/KULT.PRG

# Toolchain (Alcyon + vasm) -> matching/toolchain/ (gitignored)
cd matching
sh setup_toolchain.sh

# Build matching y verificación
make vasm
make indep
make check
```

Salida principal: `matching/out/KULT.PRG`.

Si no tienes el PRG a mano, `make vasm` construye igualmente el PRG a partir de
la fuente y de `matching/data/`; la comparación byte a byte con el original es la
que necesita tu copia.

## Contenido

```text
matching/        reconstrucción ASM byte a byte (código + tablas de datos)
  src/           fuentes .s (manuales + auto_*.s), manifest, data_*.s
  data/          recursos ingestados del PRG (gitignored)
  toolchain/     Alcyon + vasm descargados (gitignored)
  out/           artefactos del build (gitignored)
tools/           ingest, matching, comprobación y generación de tablas
docs/            referencia técnica y plan de la decompilación
work/            decomp.c + names.txt (el PRG y los discos están gitignored)
```

Documentación principal:

- `matching/README.md` — estado y método del matching.
- `matching/RELOCS.md` — derivación de la tabla de relocalizaciones.
- `docs/MATCHING_BUILD.md` — toolchain, pipeline y resultado del gate.
- `docs/MATCHING_DEV.md` — formato del PRG/DRI y detalles de RE.
- `docs/PLAN_MATCHING_DECOMP.md` — plan y criterios de aceptación.

## Verificación

```sh
cd matching
make check                 # usa work/disk_a/KULT.PRG por defecto
make check PRG=/ruta/KULT.PRG
make indep                 # build autocontenido desde git archive HEAD
```

`make check` compara el PRG reconstruido con el original: tamaño, cabecera,
tabla de relocalizaciones y SHA-256.

## Contribuir

- El ASM es la especificación: cada cambio debe venir de una comparación con el
  decomp/PRG y pasar `make check` (o `make indep` cuando no haya PRG).
- **No** commitear assets, binarios, `matching/data/`, `matching/toolchain/`,
  `matching/out/` ni copias del juego. Están en `.gitignore`.
- Para bloques concretos, usa `tools/match_region.py` y `tools/match_check.py`.
- Los `auto_*.s` son fuente versionada; `make regen` solo se usa en desarrollo.

## Legal y licencia

**KULT: The Temple of Flying Saucers** y todo su código, datos, gráficos, audio,
textos y demás assets son propiedad de sus respectivos titulares. Este
repositorio **no** distribuye assets ni binarios del juego y **no concede
derechos** sobre el juego original.

Las aportaciones originales de este repositorio —herramientas, scripts,
documentación y la reconstrucción en la medida en que sea licenciable— se
distribuyen bajo la licencia **MIT** incluida en [LICENSE](LICENSE), con la
salvedad expresa de que dicha licencia **no se extiende** al código, datos o
assets originales del juego.

Este proyecto se ofrece para preservación, investigación e interoperabilidad,
sin garantía. Si eres titular de derechos y consideras que algún contenido no
debe estar aquí, abre un *issue* en el repositorio.
