# matching/ — decompilación *matching* de Kult (ruta ASM)

Meta (ver `docs/PLAN_MATCHING_DECOMP.md`): reconstruir fuentes que se ensamblen y
enlacen a un `KULT.PRG` **byte a byte idéntico** al original.

> **Referencia técnica del build: `docs/MATCHING_DEV.md`** (arquitectura del
> pipeline, formato del PRG/stream DRI, derivación de relocs, árbol de fuentes,
> verificación y trampas). Este README es estado/método; `RELOCS.md`, la ficha de
> las relocalizaciones.

## Estado (2026-10-16) — ¡PRG **byte-idéntico**!

- **`make vasm`** (o `python3 matching/build_vasm.py`) reconstruye un `KULT.PRG`
  **byte a byte idéntico** al original:
  `sha256 = 2e85f223167439425ab2096bd21716de135f9b472bde90f4d40e8b0e03132fe6`.
- **El `text` completo (código + datos) sale de la fuente**: `manifest.txt` tiene
  las funciones a mano y **`auto_*.s` (VERSIONADOS)** las desensambladas
  (`autogen.py` solo se usa en dev con `make regen`); `build.py` los compone en
  `out/kult.s` y **vasm** (`vasmm68k_mot -Ftos -m68000 -no-opt -nosym`) ensambla
  todo a un PRG TOS con el `text` y la cabecera exactos.
- **Árbol AUTOCONTENIDO (2026-10-16):** el build **no abre `KULT.PRG`** y **no usa
  ningún metadato del original** — código (`auto_*.s` versionados), **tablas de
  datos de recursos transcritas a fuente** (`matching/src/data_*.s`; RE en
  `RELOCS.md`) y assets (`matching/data/` por `make ingest`). Sin semilla.
  **`make indep`** lo verifica: build desde `git archive HEAD` sin el PRG →
  `sha256` idéntico.
- **Por qué vasm y no as68:** el `as68` de tos1x tiene un **bug de fase** con el
  programa completo (`illegal relative address` en ramas cortas cercanas); el
  `as68` original del kit **segfaultea** en Linux (usa `sbrk`/tabla con punteros
  de 32-bit). vasm es portable y correcto. (El `as68` de tos1x se sigue usando en
  `build.py` para **medir** fragmentos y para el subconjunto manual, que sí
  ensambla.)
- **Tabla de relocalizaciones DERIVADA DE LA FUENTE (2026-10-16):** ya **no** se
  copia del original. `vasm -Ftos` **emite** la tabla para cada referencia a una
  etiqueta; `autogen.py` sustituye cada operando/inmediato largo cuyo destino es
  una reloc por su **símbolo** y `build.py` los define como **expresiones
  relocalizables** (`s_%06x equ f_010000±$c`). Los punteros incrustados en datos
  (tablas del compilador C) se emiten como `dc.l <símbolo>`. Resultado:
  **2171/2171 relocs iguales** y `sha256 2e85f223…`. Detalle y método en
  **`matching/RELOCS.md`**.
- Veredicto M0 (`docs/MATCHING_BUILD.md`): el motor es **ASM a mano** (no Alcyon
  C); el `crt0`/runtime y la música `0x3axxx` sí son C.

## Añadir un fragmento (flujo M4/M5)

1. Escribir `matching/src/<nombre>.s` con la etiqueta `f_<image_addr>` y el asm
   (sin directiva `TEXT`); referencias a otras funciones: `f_<addr>`; a globales:
   el nombre de `addrs.h` (`A_...`) — ambos generan/definen relocs como el original.
2. Añadir la línea `<image_addr> <fichero>` a `matching/src/manifest.txt`.
3. `matching/build.py` y comprobar que la región sale en `REGIONES OK` (o usar
   `tools/match_region.py --cand-prg --addr <addr>`).
- **Herramientas de matching**: `tools/match_check.py` (PRG vs PRG),
  `tools/match_region.py` (binario crudo vs región del PRG), `tools/match_layout.py`.

## Toolchain (Alcyon / DRI)

```sh
matching/setup_toolchain.sh          # apk gcompat + clona th-otto/tos1x
export PATH=$PWD/matching/toolchain/bin/linux:$PATH
```

- `as68` (ensamblador), `cp68`/`c068`/`c168` (C K&R), `optimize`, `link68`,
  `relmod`, `lib/libc.a`, `lib/crt0.o`.
- Nota: `link68` espera bases hex **sin `0x`** (`text[10000]`). La generación
  exacta del `.prg` GEMDOS (flujo `link68`→`relmod` con cabecera 0x601A) es el
  trabajo de M2.

## Flujo de trabajo

1. Transcribir un bloque a `.s` (o emitir datos con `incbin`).
2. Ensamblar y enlazar.
3. Comparar:
   - `python3 tools/match_region.py work/disk_a/KULT.PRG CAND.bin --addr 0x1XXXX`
   - `python3 tools/match_check.py work/disk_a/KULT.PRG CAND.prg`
4. Nada se da por bueno hasta que coincida byte a byte (o se documenta el bloqueo).

## Estructura

```
matching/
├── README.md            <- este fichero
├── setup_toolchain.sh   <- descarga/prepara Alcyon
├── Makefile             <- layout / check
├── layout.json          <- mapa de anclajes (solo direcciones/nombres)
├── src/                 <- .s reconstruidos (M2+)
└── data/                <- recursos extraídos del original (gitignored)
```

`data/` y los binarios generados están en `.gitignore`: nunca se versionan
assets con copyright ni binarios del juego.

## Autogenerador (`autogen.py`) y build con vasm (`build_vasm.py`) — RESUELTO

- `autogen.py`: para cada función del índice aún no hecha a mano, emite
  `auto_*.s` con capstone: saltos/`(pc)` a desplazamiento, **nombres de etiqueta
  consistentes** (`f_%06x` funciones, `s_*` símbolos, `A_*` globals, `l_%06x`
  internos), **rangos que acaban en fronteras reales de instrucción** (absorbe
  anclas-artefacto de Ghidra a mitad de instrucción), e inmediatos `.b` con la
  palabra real.
- `build.py`: compone `out/kult.s` (fragmentos + datos + huecos). El `as68` de
  tos1x se usa para **medir**; su ensamblado monólito tiene el bug de fase.
- `relocs.py`: nombra destinos y símbolos relocalizables (`s_%06x equ
  f_010000±$c`); el build deriva todo de la fuente. Ver `RELOCS.md`.
- `tools/gen_data_tables.py`: transcribe las tablas de punteros de recursos a
  `data_*.s` (`make gendata`).
- `build_vasm.py`: normaliza a vasm (`opt t-`, sin espacio tras coma) y ensambla
  con `vasmm68k_mot -Ftos -m68000 -no-opt -nosym` → **PRG byte-idéntico** (ver
  arriba). La tabla de relocs la **genera vasm**; no se copia del original. **No**
  regenera autogen por defecto (`--regen` en dev).

`verify_independent.sh` = B3 (build sin el PRG).

