# MATCHING_DEV — referencia técnica del build *matching* de KULT

**Documento de referencia** (no de estado). Explica **cómo está construido** el
build que reconstruye `KULT.PRG` byte a byte y **por qué**. Para estado/handoff:
`matching/README.md` y `matching/RELOCS.md`. Para el plan:
`docs/PLAN_MATCHING_DECOMP.md`. Bitácora de toolchain: `docs/MATCHING_BUILD.md`.

> Base de carga del programa: **`0x10000`**. Direcciones "de imagen"
> (text-relativas) = dirección runtime − `0x10000`. Todo el matching se mueve en
> offsets de imagen salvo donde se diga "runtime".

## 1. Objetivo y criterio de "hecho"

Reconstruir, **desde un árbol de fuentes del repo**, un `KULT.PRG` **byte a byte
idéntico** al original de 1989. Verificación: mismo tamaño (184.291 B), misma
cabecera, **mismo stream DRI de 2.171 relocs** y mismo
`sha256 = 2e85f223167439425ab2096bd21716de135f9b472bde90f4d40e8b0e03132fe6`.

## 2. El artefacto: formato de `KULT.PRG`

Fichero GEMDOS `.PRG`, cabecera de 28 B + segmentos + tabla de relocs. Parser
canónico y documentado: **`tools/prg_dis.py`** (`parse_header`, `parse_reloc`).
Aquí solo lo esencial:

```
0x601A (magic, 2 B) | tlen=0x2C534 | dlen=0 | blen=0 | slen=0 | reserved
flags=0x00 | absflag=0 (=> hay tabla de relocs) | @28: text (181.556 B) | tabla DRI
```

(Reparto exacto de campos: `tools/prg_dis.py::parse_header`. `flags=0` lo pone
vasm; `absflag=0` es lo que manda al cargador aplicar la tabla.)

El `text` mezcla **código y datos** sin segmentación (recursos PI1/sprites/bancos
de texto/tablas/música, intercalados con el código). El layout reproducible está
en **`matching/layout.json`** (generado por `tools/match_layout.py`).

### 2.1 Stream de relocalizaciones DRI

La tabla lista **posiciones (offset de imagen) de longwords a los que el cargador
GEMDOS suma la base de carga**. Encoding (ver `prg_dis.parse_reloc`):

- primer longword = offset de la primera fixup;
- luego 1 byte por paso: `0x00` = fin; `0x01` = *skip* (+254, **no** es fixup);
- cualquier otro byte `d` = `cursor += d` → nueva fixup.

Un valor de fixup apunta a una dirección **relativa al text** (el cargador suma
`0x10000`). Cuando el stored value es "negativo" (`0xffffd8f0`) apunta por debajo
de la base (RAM baja, p. ej. `A_SAVE_DESC` runtime `0xd8f0`); cuando es
`> tlen` apunta a buffers de RAM tras el programa (`A_BLIT_SCRATCH`
runtime `0x55b02`).

## 3. El pipeline

```
work/decomp.c (índice de funciones Ghidra)   work/disk_a/KULT.PRG (original)
            │                                         │
   tools/match_layout.py ────────────────► matching/layout.json (anclas/layout)
            │                                         │
            ▼                                         ▼
   matching/autogen.py ──► matching/src/auto_*.s + autogen.txt
   matching/src/manifest.txt (fragmentos manuales)
   matching/src/symbols.txt, equ.txt (nombres)
            │
            ▼
   matching/build.py ──► matching/out/kult.s  (sintaxis as68, un solo TEXT)
            │
            ▼
   matching/build_vasm.py (normaliza a vasm) ──► vasm -Ftos -nosym ──► KULT.PRG
```

- **`autogen.py`** genera un fragmento `.s` por rango de función no hecha a mano,
  desde el desensamblado (capstone + `prg_dis`), con etiquetas consistentes
  (`f_%06x`, `s_*`/`A_*`, `l_%06x`) y **sustituye los operandos largos por
  símbolos** (§5). **Ya NO se ejecuta en cada build**: sus salidas
  (`auto_*.s` + `autogen.txt`) están **versionadas** (B1a). Solo en dev: `make regen`.
- **`build.py`** compone `out/kult.s`: emite, en orden de dirección, fragmentos
  (auto+manual+**tablas de datos** `data_*.s`), recursos embebidos y rellenos.
  Define los símbolos y las tablas `equ`. Los **bytes de los recursos** salen de
  `matching/data/`, salvo las **tablas de punteros** (`data_*.s`, fuente
  versionada). Usa `as68`/`link68`/`relmod` para **medir** fragmentos y comparar
  regiones (no para el PRG final).
- **`build_vasm.py`** normaliza a vasm (`opt t-`), ensambla con
  `vasmm68k_mot -Ftos -m68000 -no-opt -nosym` y **usa la salida tal cual** (la
  tabla la genera vasm). No regenera autogen. La comparación con el PRG es
  **opcional**.
- **`relocs.py`** ayuda a derivar símbolos de reloc (§5) y nombra destinos;
  `analyze(prg)` lo usa solo `autogen`/`regen`. El build no lo necesita (§5.1).

Comandos (`matching/Makefile`):

```sh
cd matching
make vasm     # build byte-idéntico (no necesita el PRG: B1)
make ingest   # extrae matching/data/ del PRG (una vez, desde la copia del usuario)
make indep    # B3: build desde git archive HEAD sin KULT.PRG -> sha256 idéntico
make regen    # (dev) regenera auto_*.s desde el PRG
make check    # compara out/KULT.PRG con el original
```

### 3.1 Por qué vasm (y no el Alcyon `as68`)

El `as68` de `tos1x` tiene un **bug de fase** con el programa completo
(`illegal relative address` en ramas cortas) y rechaza pseudo-instrucciones que
caen sobre datos; el `as68` original **segfaultea** en Linux. `vasm` es portable,
correcto y **emite la tabla DRI** que necesitamos.

## 4. Árbol de fuentes

```
matching/
├── Makefile                 vasm | layout | data | setup | check
├── layout.json              mapa de anclas (direcciones/nombres, sin bytes)
├── setup_toolchain.sh       descarga Alcyon/tos1x + compila vasm
├── relocs.py                derivación de relocs (destino -> símbolo)
├── autogen.py               fragmentos auto desde el desensamblado
├── build.py                 compone out/kult.s + mide/verifica regiones
├── build_vasm.py            build byte-idéntico (va al PRG final)
├── src/
│   ├── manifest.txt         fragmentos MANUALES: <addr> <fichero>
│   ├── symbols.txt          <addr> <nombre> de datos con reloc
│   ├── equ.txt              <valor> <nombre> [addr|const] (direccion vs constante)
│   ├── autogen.txt          (VERSIONADO) <addr> <auto_*.s> <len>
│   ├── data_manifest.txt    (VERSIONADO) <addr> data_*.s <len>  (tablas de datos)
│   ├── data_*.s             (VERSIONADO) tablas de punteros transcritas (RE)
│   └── *.s                  manuales + auto_*.s (TODOS versionados desde B1a)
├── data/                    recursos embebidos extraidos (assets; gitignore; `make ingest`)
├── verify_independent.sh    B3: build sin el PRG
└── out/                     kult.s / kult_vasm.s / KULT.PRG (gitignore)
```

Versionados: fuentes (`.s`), `manifest/symbols/equ/autogen/data_manifest`,
`layout.json`.
Gitignored: `matching/toolchain/`, `matching/data/`, `matching/out/`, y todo `work/`
(assets del juego y `decomp.c`… ojo: `work/decomp.c` y `work/names.txt` **sí** se
versionan; ver `.gitignore`).

## 5. Cómo se derivan las relocalizaciones

Regla de oro: en un PRG relocalizable, **cada referencia absoluta de 32 bits a una
etiqueta** produce **una reloc**. vasm `-Ftos` emite la tabla por nosotros
(`output_tos.c`: `tos_writerelocs`); un literal `$xxxx.l` **no** genera reloc, un
**símbolo** sí. Por eso el trabajo es: **poner símbolo donde el original tiene
puntero**.

### 5.1 Clasificación (sin semilla: todo desde la fuente)

El build **no usa ningún metadato del original**. `build.py` deriva de los `.s`
(fuente):

- **código**: los `auto_*.s`/manuales ya llevan los símbolos en los operandos.
- `newdefs` — escaneo de los fragmentos → define los `s_*` referenciados.
- `target_vals` — globals fuera del text + los `addr` de `equ.txt`
  (`equ.txt`: `addr`/`const`).
- **tablas de datos en recursos**: transcritas en `matching/src/data_*.s`
  (`dc.l <símbolo>` + nombres), emitidas en lugar de los bytes crudos.

`relocs.analyze(prg)` solo lo usa `autogen`/`regen` (necesita el PRG); el build no.

> Por qué tablas y no detección: los 189 punteros dentro de recursos **no** se
> distinguen de sonido/sprites por valor/estructura (RE en
> `matching/RELOCS.md`). Son lógica (direcciones/nombres), así que se
> transcriben a fuente; el resto de cada recurso sigue siendo asset
> (`matching/data/`).

### 5.2 Símbolos relocalizables (dentro y fuera del text)

Los destinos se definen como **expresión relocalizable**, no como absoluto:

```
s_00a53e  equ  f_010000+$a53e      ; destino en el text
s_045b02  equ  f_010000+$45b02     ; buffer de RAM tras el text
s_00d8f0  equ  f_010000-$2710      ; RAM baja (0xd8f0 runtime -> 0xffffd8f0)
```

`f_010000` es la etiqueta de la primera función (offset 0). Un `equ` de un valor
absoluto **no** relocaliza; de una expresión con un label de sección **sí**. Esto
sustituye a los antiguos `equ` absolutos de fuera del `text` (p. ej.
`A_BLIT_SCRATCH`), que antes no generaban reloc.

### 5.3 Código: campos largos de instrucción

`autogen` instrumenta `prg_dis._reloc_long` para localizar, en cada instrucción,
los campos de 4 B (`abs.l` e inmediatos largos) y los sustituye por el símbolo de
su destino cuando ese offset está en `fixes`. vasm elige `abs.l` (4 B) al ser el
símbolo relocalizable, conservando los bytes.

### 5.4 Datos: punteros incrustados y carvado

Algunos punteros viven en **datos dentro de regiones de código** (tablas inline
del compilador C, p. ej. `auto_015ac8.s`, música `auto_03ae68.s`) o en recursos.
Si una posición de reloc **no** es campo de ninguna instrucción, `gen_range` la
**carva** como `dc.l <símbolo>`: emite instrucciones hasta ahí, el puntero y
continúa. Los recursos embebidos se emiten con `relocs.emit_bytes`
(`dc.b` + `dc.l` en las posiciones de reloc). Las **etiquetas se colocan en su
dirección exacta** (no solo en inicios de instrucción).

### 5.5 Números (original)

| categoría | nº |
|---|---|
| campos largos de instrucción | 1946 |
| punteros en datos | 225 (189 en `SOUCO.BIN` + 36 en 2 fragmentos C) |
| total | **2171** (todos a offset par) |

Distintos destinos: 621 (233 con símbolo nuevo `s_%06x`). Falsos positivos del
criterio ingenuo "el longword vale un destino": bytes de sonido/sprites
(`$4246`/`$8888`) que coinciden con direcciones reales → se evitan restringiendo
a campos de instrucción y a posiciones de reloc en datos.

## 6. Verificación

- **`tools/match_check.py ORIG CAND`** — cabecera, sha256, igualdad del **set de
  relocs**, primer byte divergente con contexto. Salida 0 = idénticos.
- **`tools/match_region.py`** — binario crudo vs una región del PRG (`--addr`).
- **`tools/match_layout.py`** — regenera `layout.json`.
- `matching/build_vasm.py` imprime por sí solo `relocs derivados por vasm: N
  (original M) iguales: True/False`.
- Red de seguridad: [`kult-atari-st-c`](https://github.com/hunkstalker/kult-atari-st-c) `make test`.

Nada se da por bueno sin `sha256` idéntico (o bloqueo documentado).

## 7. Extender el matching

**Añadir un fragmento manual (M4/M5):**
1. Escribir `matching/src/<nombre>.s` con la etiqueta `f_<image_addr>` y el asm
   (sin directiva `TEXT`); referencias a funciones: `f_<addr>`; a globales: el
   nombre de `addrs.h`.
2. Añadir `<image_addr> <fichero>` a `matching/src/manifest.txt`.
3. `python3 matching/build_vasm.py` y comprobar `text igual: True`, relocs
   iguales y `REGIONES OK`.

**Añadir un símbolo de datos** (con reloc): línea `<runtime_addr> <nombre>` en
`matching/src/symbols.txt`. En `equ.txt`, `<valor> <nombre> addr` (dirección,
relocalizable) o `<valor> <nombre> const` (absoluta).

## 8. Trampas (todas pagadas)

- **`as68`** de tos1x: bug de fase con el programa completo; no usarlo para el PRG
  final (solo vasm).
- **Sintaxis MOT de vasm:** hex `$` (no `0x`); no admite `#(expr)`; un símbolo
  `abs.l` debe ir sin sufijo `.l` (si no, "number or identifier expected").
- **vasm `-Ftos` SÍ emite tabla** (creencia antigua: que no). No hacen falta
  `link68`/`relmod`.
- **Coordenadas:** `fixes`/campos van en offset de imagen; `start/end` de
  `gen_range` en runtime. Mezclarlos fue un bug.
- **Capstone desincroniza** sobre datos; por eso el carvado usa el decodificado
  completo (no segmentos truncados) y `prg_dis` para detectar campos.
- **`work/decomp.c` no da fronteras fiables** (Ghidra parte en llamadas); las
  fronteras reales se confirman con el binario.
- **`.b` inmediatos:** capstone solo da el byte; se reescribe la palabra real.
- **No versionar** assets ni binarios (`work/`, `out/`, `auto_*.s`).

## 9. Estado (resumen; detalle en fichas)

- `text` + cabecera + **tabla de relocs**: **derivados de la fuente**;
  `sha256` byte-idéntico. ✅
- **Árbol autocontenido (B1, 2026-10-16):** el build **no abre `KULT.PRG`** para
  código (auto_*.s versionados, B1a) ni datos (`matching/data/` por ingest, B1b).
  **B3 verde**: `make indep` construye desde `git archive HEAD` sin el PRG →
  `sha256` idéntico. ✅
- **B2-estricto (2026-10-16):** **sin ningún metadato del original**. El código
  se deriva de la fuente y las **tablas de datos de recursos** se transcriben a
  `matching/src/data_*.s` (7 fragmentos, 988 B; RE en `matching/RELOCS.md`).
  `reloc_seed.txt` eliminado. `make indep` (desde `git archive HEAD`, sin el PRG)
  → `sha256` idéntico. ✅
- Piezas: `relocs.py`, `verify_independent.sh`, `tools/ingest_data.py` +
  cambios en `autogen.py`/`build.py`/`build_vasm.py`/`Makefile` (2026-10-16).
