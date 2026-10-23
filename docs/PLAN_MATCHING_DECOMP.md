# Plan — Decompilación *matching* de Kult (estilo Mario 64)

> **Nota (2026-10-23):** este documento es el **plan histórico** de la
> decompilación. El C y el arnés se movieron a
> [`kult-atari-st-c`](https://github.com/hunkstalker/kult-atari-st-c). Las
> referencias a `projects/kult/recreate`, `src_c/`, `runtime/native`,
> `PLAN_MULTIVERSION.md` y `AGENTS.md` son históricas y no forman parte de este
> repositorio.

> **Plan activo (nueva meta de ingeniería).** El objetivo a medio plazo deja de ser
> solo "port fiel" y pasa a ser **una decompilación *matching***: un árbol de
> código que, compilado con un toolchain reproducible, produzca un `KULT.PRG`
> **byte a byte idéntico** al original de 1989. Sobre esa base se hará luego la
> fusión Atari ST + Amiga (plan multi-versión del repo C).
>
> Sustituye como **hoja de ruta** al plan multi-versión **solo en la meta**;
> el multi-versión se conserva y se apoya en este (ver §5). Las reglas de trabajo
> del repo C siguen vigentes para todo.

## RESULTADO (2026-10-16) — PRG byte-idéntico

**`matching/build_vasm.py`** reconstruye un `KULT.PRG` **byte a byte idéntico**
al original (`sha256 = 2e85f223…`). El **`text` completo (código + datos) sale de
la fuente** (`autogen.py` genera el ASM de las funciones restantes desde el
desensamblado; `manifest.txt` las manuales; `build.py` compone `out/kult.s`) y se
ensambla con **vasm** (`-Ftos -m68000 -no-opt -nosym`). La **cabecera** también
coincide. **La tabla de relocs también se deriva de la fuente** (2026-10-16,
sesión 2): `vasm -Ftos` la emite a partir de los símbolos (`autogen.py` sustituye
cada operando largo por el símbolo de su destino; `build.py` los define como
expresiones relocalizables; los punteros en datos van con `dc.l`). **2171/2171
relocs iguales**, 0 faltan/sobran. Detalle: **`matching/RELOCS.md`**,
`matching/README.md` y `docs/MATCHING_BUILD.md`.

## 0. Definición de "hecho" (criterios de aceptación)

Se considerará conseguido cuando exista:

1. **Un *build* reproducible** (Linux, `make`) que enlace un `KULT.PRG`
   **byte a byte idéntico** al original:
   - mismo tamaño de fichero (**184.291 B**),
   - misma cabecera (`text=0x2C534`, `data=0`, `bss=0`, `sym=0`, `flags=0`),
   - **mismas 2.171 relocalizaciones DRI** (mismo stream),
   - **mismo SHA-256** que `work/disk_a/KULT.PRG`.
2. **Cobertura 100 % del segmento `text`**: cada byte generado por fuente (C o
   ASM) del repo, **sin funciones "no reconstruidas"** y sin parches al binario.
3. La suite diferencial del repo C sigue **verde** (red de seguridad).
4. Documentación mínima: mapa de fuente por módulo, nombres razonables y cómo se
   construye (nuevo `docs/MATCHING_BUILD.md`).

## 1. Estado de partida (auditoría 2026-10-16)

- **Índice de Ghidra:** 423 funciones (406 del índice + 17 reconstruidas fuera).
- **413 reconstruidas**, **403 con test** → **10 sin test**:
  `0x10b6c`, `0x11026`, `0x110da`, `0x12590`, `0x1478a`, `0x14798`, `0x15b94`,
  `0x1652e`, `0x18316`, `0x18f0c` (varias son envoltorios/colas).
- **10 sin reconstruir:** `_start` (portado aparte en
  el arranque nativo del repo C), 3 artefactos de Ghidra
  (`0x11e7a`/`0x11ec4` = cuerpo/cola de `0x11e5e`; `0x135ba` = 4 B de datos) y
  las **6 del FDC** (`0x19316`/`0x1935a`/`0x193e4`/`0x19438`/`0x19462`/`0x19474`),
  excluidas hasta hoy.
- **Volumen de código:** la suma de tamaños del índice es **37.555 B** sobre un
  `text` de **181.556 B**. Es decir, **~144 KB del segmento `text` son DATOS
  embebidos** (recursos: PI1, sprites, bancos, tablas, música). Un *matching
  build* debe reproducir también **esos datos y su layout exacto**, no solo el
  código.
- **Verificación actual:** diferencial *por función* contra el oráculo Musashi
  (imagen de memoria + registros + ledger). No es un *matching build*.

### 1.1 Hallazgo clave de toolchain (M0, 2026-10-16)

**Resultado del gate M0: el motor NO es Alcyon C; es ensamblador a mano.**
Detalle y evidencia en **`docs/MATCHING_BUILD.md`**. En resumen:

- El `crt0`/arranque SÍ es **Alcyon C / DRI**, y **el toolchain Alcyon se ha
  puesto a funcionar nativamente en Linux** (binarios `bin/linux` de
  `th-otto/tos1x` + `gcompat`; ver `MATCHING_BUILD.md` §1.1).
- Pero el **motor** (todo el `text` salvo `0x3axxx`) **no tiene frames `link`**
  (solo 2 en todo el binario, y están en el módulo de música) y **pasa
  argumentos por registro con estado persistente en `a5`/`a6`** ⇒ no es salida de
  Alcyon (que usa `link R14` + argumentos en pila) ni de un C de la época.
- El **módulo de música `0x3axxx`** sí es C (prólogo `link.w a6,#0` +
  `movem.l d0-d7/a0-a6`), y el **crt0/runtime** también.

### 1.1bis Evidencia del crt0 (Alcyon / DRI)

El `crt0` de `KULT.PRG` es la secuencia clásica **Alcyon C / DRI** de la época:

```
movea.l 4(a5),a5            ; a5 = basepage
move.l  0xc(a5),d0          ; text
add.l   0x14(a5),d0         ; data
add.l   0x1c(a5),d0         ; bss
addi.l  #0x100,d0
move.l  d0,-(sp) / move.l a5,-(sp) / move.w d0,-(sp)
move.w  #0x4a,-(sp) ; trap #1     ; Mshrink
adda.l  #0xc,sp
movea.l #0xd1fe,a7
bsr.w   ...
```

Esto encaja con **Alcyon C (DRI)** —el compilador estándar del Atari ST en 1989—
o un derivado. Es la pista decisiva de viabilidad (§2). El `sym=0` (sin tabla de
símbolos) complica la identificación rápida del *library*, pero el patrón de
`crt0` y el estilo de codegen son reconocibles.

## 2. Barrera crítica y *gate* de viabilidad (M0)

Una *matching decomp* solo funciona si se reproduce el **mismo codegen**. Para
Kult eso exige:

1. **Identificar** el compilador exacto (versión de Alcyon C: 1.x/2.x, o
   Lattice/Megamax/otro si el `crt0` engaña) y el ensamblador/enlazador
   (Alcyon `alink` genera las relocs DRI).
2. **Conseguir** el toolchain original (distribuciones Atari de la época,
   preservadas en archivos: Alcyon C fue liberado; hay copias binarias y parte
   del código fuente) y **ejecutarlo** (emulado o nativo).
3. **Reproducir** flags, cabeceras (`osbind.h`/`gemdefs.h` de la época) y la
   **librería C** (equivalente de `AC.LIB`) que el enlazador incrusta.

> **Gate M0 (decisorio): RESUELTO en contra del C para el motor (2026-10-16).**
> Se identificó y ejecutó el compilador original (Alcyon C/DRI) y se comprobó
> que su codegen **no** reproduce el del motor: KULT no usa frames `link` ni
> argumentos en pila. Conclusión: el motor es **asm** (ver
> `docs/MATCHING_BUILD.md` §2). Por tanto la meta "matching en C" **no aplica al
> motor**; la ruta viable es **matching disassembly** (reconstruir `.s` + datos
> → PRG byte a byte), con el C actual como documentación. El `0x3axxx` (música) y
> el runtime sí pueden ir en C. **Decisión pendiente del usuario** (§6 y
> `MATCHING_BUILD.md` §3).

**Matiz importante:** muchos tramos **no son salida de C**, sino **ASM escrito a
mano** (los blitters `0x11xxx`, los escaladores `0x12/13xxx`, la música/ISR
`0x18xxx`/`0x3axxx`, el FDC). En una *matching decomp* esos van como **fuente en
ensamblador** (`.s`), igual que en Mario 64, no como C. Eso es esperado y válido.

## 3. Arquitectura del *build* matching

Nuevo árbol (nombres provisionales):

```
matching/
├── kult-atari-st-c/src/  reconstrucción C (repo aparte)
├── src_asm/      ASM reconstruido (blitters, música, FDC, crt0…)
├── include/      cabeceras de la época (osbind/gemdefs) + addrs.h
├── lib/          crt0 + librería C mínima equivalente
├── link/         script de enlace PRG: orden de segmentos, tabla de recursos,
│                 generación de las relocs DRI
└── Makefile
tools/match_check.py   comparador de PRG (tamaño, bytes, relocs, diff con contexto)
```

- **Layout del `text`:** primero se fija el mapa de memoria del original (código
  y datos embebidos intercalados; tabla de recursos en `0xA2E4`). El enlace debe
  reproducir el orden exacto.
- **Relocs DRI:** el enlazador debe emitir el mismo *stream* de 2.171 entradas.
- **Estrategia de abajo arriba:** datos/bloques embebidos → `crt0` → librería/E-S
  GEMDOS → funciones C → ASM a mano → hash final.

## 4. Fases

- **M0 — Gate de toolchain** (§2). *Decisorio; sin él no hay matching.*
- **M1 — Esqueleto del PRG:** cabecera + segmento `text` + datos embebidos +
  tabla de recursos + relocs. Objetivo: reproducir todos los bytes del `text`
  que **no** son código (los ~144 KB de datos) y la cabecera.
  **En curso (2026-10-16):** creado `matching/` (README, `setup_toolchain.sh`,
  Makefile), **mapa de layout** (`matching/layout.json` vía
  `tools/match_layout.py`) y herramientas de comparación
  (`tools/match_check.py`, `tools/match_region.py`) con test. Ensamblador `as68`
  validado (codifica idéntico). Layout: código A `[0x10000,0x1949c)`, recursos
  `[0x1949c,0x3a556)`, música `[0x3a556,0x3b1ac)`, `MUSIQ [0x3b1ac,0x3c534)`.
  **M1.1 HECHO:** `matching/build.py` genera el `text` con los datos embebidos,
  ensambla/enlaza/relmod a PRG; **los 16 bloques de datos coinciden byte a byte**.
  Discrepancia: campo `FLAGS` de cabecera (`0x7` vs `0x0`) por usar los binarios
  modificados de `tos1x`; pendiente el *developer kit* original.
- **M2 — `crt0` y arranque:** `_start` (`0x10000`) y `crt0_init` (`0x135e2`)
  idénticos.
  **HECHO (2026-10-16):** build por segmentos (`matching/build.py`) validado;
  **5 funciones** byte-match (`_start`, `crt0_init`, `fun_13686`,
  `gemdos_fclose`, `set_palette`) + 16 datos, con **relocs** correctas. Clave:
  `as68 -n` (ramas largas). Pendiente: byte `FLAGS` de cabecera y representar
  como símbolo relocable una dirección de RAM fuera del `text` (`_start`@`0x116`).
- **M3 — Librería C / GEMDOS:** identificar las rutinas de librería usadas y
  aportar su fuente/objeto que genere idéntico.
- **M4 — Funciones C del juego:** agrupar por patrón de codegen y cerrar bloque
  a bloque (texto/vídeo `0x10xxx`, salas, VM, etc.).
- **M5 — ASM a mano:** blitters, escaladores, música/ISR, FDC; transcribir a
  ensamblador que ensamble a los **mismos bytes** (validado con el
  desensamblador y `match_check.py`).
- **M6 — Cero divergencias:** `SHA-256` final == original; CI que lo verifique.
- **M7 — Puente a multi-versión:** usar el core ST *matching* como canónico y
  abordar AMIGA (ver §5).

## 5. Encaje con la fusión Atari ST + Amiga

La metodología *matching* es la mejor base para el plan multi-versión
(plan multi-versión del repo C):

- El **oráculo** ya no es solo Musashi-ST: el binario Amiga es un **segundo
  oráculo**; la misma técnica diferencial por función sirve para reconstruir la
  lógica Amiga y **detectar divergencias reales** entre versiones (donde el
  código difiere, no se asume: se mide).
- Los **recursos por ID lógico** (plan multi-versión del repo C §0.3) siguen aplicando:
  el *matching* fija el "vanilla ST"; Amiga aporta arte/audio/paleta.
- El objetivo final del usuario (un Kult nativo que una ambas versiones) se
  construye **sobre** un core ST demostrado byte a byte, no en paralelo.

## 6. Riesgos y plan B

| # | Riesgo | Mitigación / plan B |
|---|---|---|
| R1 | Toolchain no recuperable o codegen no reproducible | **Plan B (matching disassembly):** fuente ASM que ensamla al PRG idéntico, con la decompilación C actual como documentación. Se pierde el "C matching", no la fidelidad ni la modificabilidad. |
| R2 | Tramo en ASM a mano que no deriva a C | Transcribir a `.s` (normal en matching). |
| R3 | Datos embebidos con layout exacto | M1; diff sistemático por bloques. |
| R4 | Código autogenerado / overlays / tablas calculadas | Detección con el desensamblador; tratar como datos. |
| R5 | Alcance enorme; presión por "cerrar" | Mantener intacta la red de tests del repo C y avanzar por fases con *gate* en M0. |

**Regla de oro:** ningún avance se da por bueno sin que el binario generado
coincida byte a byte (o se documente el bloqueo). Igual que F4 fijó.

## 7. Siguiente paso inmediato

**M0–M6 hechos (2026-10-16):** matching disassembly con vasm → PRG byte-idéntico
(`sha256 2e85f223…`), **text y tabla de relocs derivados de la fuente**
(2171/2171). Ver §RESULTADO y `matching/RELOCS.md`.

Pendiente:

- **M7 / producto:** usar este core ST como canónico y abordar AMIGA
  (plan multi-versión del repo C).
- **Opcional:** derivación *pura* de las relocs sin sembrar con los destinos del
  original (`matching/RELOCS.md` §"Trabajo futuro").

## 8. Comandos de referencia

```sh
# desde la raíz del repo
python3 tools/ingest_data.py --prg work/disk_a/KULT.PRG
cd matching
make vasm
make check
make indep
```

## 9. Meta: árbol de fuentes autocontenido (independencia del PRG)

**Objetivo acordado (2026-10-16):** el *build* del matching **no debe abrir
`KULT.PRG`**; el árbol de fuentes (+ los assets que aporta el usuario) debe bastar
para reproducir el binario. Es lo que llamamos "reconstruir sin leer el PRG
original": **independencia del PRG en tiempo de build**.

El build leía el original por **dos** motivos; **ambos resueltos** (B1b/B1c y,
para la semilla, **B2-estricto**):

1. **Semilla de relocalizaciones** (`matching/relocs.py::analyze`): las posiciones
   y los destinos se leían de la tabla del original. **Resuelto (B2-estricto):**
   el *código* deriva sus símbolos de la fuente y las **tablas de punteros en
   recursos** se **transcriben a `matching/src/data_*.s`** (lógica, no assets).
   `reloc_seed.txt` eliminado. Ver `matching/RELOCS.md`.
2. **Datos embebidos** (~144 KB del `text`): `build.py` los emite leyendo
   `orig[a:b]` del PRG (`resources_embedded`). **Complicación real:** esos
   recursos (SOURI/SOUCO/ZONES/CARAC/…/MUSIQ) **NO existen como ficheros sueltos**
   en el disco; solo están dentro del PRG. La política del repo prohíbe
   **distribuir assets**, así que no se pueden commitear. Opciones:
   - **(a) Ingesta**: un `tools/` extrae los bloques a `work/` (gitignored; copia
     del usuario) y el build los lee de ahí → el *build* no lee el PRG, pero
     sigue haciendo falta una **ingesta explícita** desde la copia del usuario.
   - **(b) Commitear los bloques** → **viola la política** (no distribuir assets).
   - **(c) Dejarlo como está.**
   La vía honesta es **(a)**.

**Ideal vs política:** en un matching estilo Mario 64 los blobs van en el repo.
Aquí no se pueden distribuir; por tanto "autocontenido" significa:
**todo el CÓDIGO y las relocs salen de fuente; los DATOS se ingestan de la copia
del usuario.**

**Dirección de producto:** **un proyecto por decomp** (ahora: Atari ST). La
**multiversión** (ST+Amiga) será un **proyecto separado**, construido *sobre* los
cores ya decompilados, no dentro de este.

### Backlog matching (estado)

- [x] **B1a — Código sin PRG**: `matching/src/auto_*.s` (307) + `autogen.txt`
  **versionados**; el build ya no ejecuta autogen (`make regen` solo en dev).
- [x] **B1b — Datos desde ingesta**: `tools/ingest_data.py` extrae los 16
  recursos a `matching/data/` (gitignored); `build.py` los lee de ahí
  (`load_data_blob`), no de `orig[a:b]`.
- [x] **B1c — Semilla de relocs serializada (stopgap, luego eliminada)**: sirvió
  para que el build no abriera el PRG; **B2-estricto la eliminó** al transcribir
  las tablas de datos a fuente.
- [x] **B3 — Verificación de independencia**: `matching/verify_independent.sh`
  (`make indep`) construye desde `git archive HEAD` (**sin** `KULT.PRG`) + datos
  ingestados + toolchain → `sha256 2e85f223…` idéntico. ✅
- [x] **B2-lite — Código desde la fuente (2026-10-16):** `newdefs`/`target_vals`
  derivados de la fuente (`auto_*.s` + `addr`/`const` en `equ.txt`).
- [x] **B2-estricto — sin ningún metadato del original (2026-10-16): ✅** los
  189 relocs dentro de recursos son **tablas de lógica** (no se distinguen de
  sonido/sprites por valor/estructura → RE + **transcripción a fuente**):
  `matching/src/data_*.s` (`dc.l <símbolo>` + nombres), 7 fragmentos / 988 B.
  `reloc_seed.txt` **eliminado**. El build emite esas tablas desde la fuente y el
  resto de recursos desde `matching/data/`. Ver `matching/RELOCS.md`.
- [ ] **B4 — Repetir por versión**: al cerrar ST, hacer lo mismo con cada versión
  (Amiga, etc.); un proyecto por decomp.

**Estado (2026-10-16):** el árbol es **autocontenido de verdad** — el build no
abre `KULT.PRG` y **no usa ningún metadato derivado del original**; todo el
código y las tablas de datos salen de la fuente, y los assets de `matching/data/`
(ingesta desde la copia del usuario). Verificado con `make indep` (desde
`git archive HEAD`, sin el PRG). *Se alcanza el nivel "sm64" en el eje de
matching byte a byte / build desde fuente;* queda como trabajo opcional la
legibilidad (nombrar/transcribir a C el motor) — ver §9 de `MATCHING_DEV.md`.
