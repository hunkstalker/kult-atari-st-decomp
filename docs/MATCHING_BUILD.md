# MATCHING_BUILD — toolchain y estado del *gate* M0

> **RESUELTO (2026-10-16):** el build matching se cierra con **vasm**
> (`matching/build_vasm.py` → `KULT.PRG` **byte a byte idéntico**,
> `sha256 2e85f223…`). El `text` completo sale de la fuente (`autogen.py` + ASM
> manual). Por qué vasm y no el `as68` de Alcyon: el de tos1x tiene un **bug de
> fase** con el programa completo (`illegal relative address` en ramas cortas
> cercanas) y el original del kit **segfaultea** en Linux (tabla con `sbrk`/
> punteros de 32-bit). Ver `matching/README.md`.
>
> **Actualización (2026-10-16, sesión 2):** la **tabla de relocs también se
> deriva** de la fuente: `vasm -Ftos` la emite por cada referencia a una etiqueta
> (no hacen falta `link68`/`relmod`). Los símbolos de destino los aporta
> `matching/relocs.py`; detalle en **`matching/RELOCS.md`**. La nota de M1/M2
> sobre `FLAGS=0x7` y la de "símbolo relocable fuera del text" quedan obsoletas
> (vasm pone `FLAGS=0x00` y las direcciones de RAM se expresan como
> `f_010000±$c`).
>
> **Árbol autocontenido (B1/B2/B3, 2026-10-16): ✅** el build **ya no lee
> `KULT.PRG`** ni usa metadatos del original — `auto_*.s` versionados (B1a),
> datos de `matching/data/` (B1b) y **tablas de datos de recursos transcritas a
> `matching/src/data_*.s`** (B2-estricto); `make indep` lo verifica sin el PRG.
> Ver `docs/PLAN_MATCHING_DECOMP.md` §9 y `matching/RELOCS.md`.

Registro operativo del plan `docs/PLAN_MATCHING_DECOMP.md`. Contiene **cómo se
ejecuta el compilador original** y el **resultado del gate M0** (¿se puede
reproducir el codegen de KULT byte a byte?). Última actualización: 2026-10-16.

## 1. Toolchain original identificado: Alcyon C / DRI

El `crt0` de `KULT.PRG` (`0x10000`) es la secuencia clásica de arranque del
compilador **Alcyon C de Digital Research** (el C estándar del Atari ST en 1989):

```
010000  movea.l a7,a5
010002  movea.l #$d1fe,a7
010008  movea.l $4(a5),a5          ; basepage
01000c  move.l  $c(a5),d0          ; text
010010  add.l   $14(a5),d0         ; data
010014  add.l   $1c(a5),d0         ; bss
010018  addi.l  #$100,d0
01001e  move.l  d0,-(a7) / move.l a5,-(a7) / move.w d0,-(a7)
010024  move.w  #$4a,-(a7) ; trap #1     ; Mshrink
01002a  adda.l  #$c,a7
010030  movea.l #$d1fe,a7
010036  bsr.w   $135e2             ; crt0_init
```

### 1.1 Cómo ejecutarlo nativamente (Linux x86-64)

`th-otto/tos1x` conserva el toolchain **compilado para Linux-64** (`bin/linux`)
más la librería C y las cabeceras. Pasos reproducibles:

```sh
# 1) gcompat: los binarios son glibc; en Alpine/musl hace falta el cargador.
apk add --no-cache gcompat

# 2) traer el toolchain (constructor de TOS 1.x, incluye Alcyon)
git clone --depth 1 https://github.com/th-otto/tos1x /tmp/tos1x
export PATH=/tmp/tos1x/bin/linux:$PATH
L=/tmp/tos1x/lib           # crt0.o, libc.a, libf.a, gem.a

# 3) compilar (K&R C: sin prototipos ANSI) y enlazar a .PRG
cc68 -c foo.c -o foo.o
cc68 -o foo.prg $L/crt0.o foo.o $L/libc.a
```

Ejecutables: `cp68` (preproc), `c068` (front-end), `c168` (codegen),
`optimize` (peephole), `as68`, `link68`, `relmod`. El wrapper `cc68` encadena
todo y acepta `-S` (volcar asm), `--optimize`, `-I`, `-D`.

> Nota: los binarios de `tos1x` están **modificados** para el *line-f dispatcher*
> de TOS 1.04. Para un `match` exacto de Kult conviene usar los originales del
> *developer kit* (`SegHaxx/atari-st-devkit`, 6 discos) o de
> `http://tho-otto.de/download/alcyon.tar.bz2`.

El compilador es **K&R C** (no ANSI): `int f(int x){...}` da *"invalid
declarator"*; hay que usar `f(x) int x; { ... }`.

### 1.2 Codegen de referencia (Alcyon, generado aquí)

```c
int g;
setg(x) int x; { g = x; }
add(a,b) int a,b; { return a+b; }
```
```asm
_setg:  link R14,#-4 ; move 8(R14),_g ; L1: unlk R14 ; rts
_add:   link R14,#-4 ; move 8(R14),R0 ; add 10(R14),R0 ; bra L2 ; L2: unlk R14 ; rts
```

Claves: **`link R14,#-4`** (R14=A6), **argumentos en pila** (`8(R14)`, `10(R14)`),
`unlk`/`rts`. Cadena de runtime del enlazado: `CLEAR68K V02.00, Copyright(c)
1984, Digital Research`.

## 2. Resultado del gate M0 — el motor NO es Alcyon C

Comparación del `KULT.PRG` real (todo el segmento `text`, 0x2C534 B) contra el
codegen Alcyon:

| Señal | Alcyon C | KULT.PRG (motor) |
|---|---|---|
| Prólogo | `link R14,#-4` / `unlk` | **ninguno** (solo 2 `link a6` en TODO el binario, ambos en `0x3axxx`) |
| Paso de argumentos | pila (`8(a6)`, `10(a6)`) | **registros** (`d0`, `d1`…), y punteros de estado en `a5`/`a6` |
| Estado entre llamadas | pila/`movem` | `a5`/`a6` **vivos a través de `bsr`/`jsr`** (convención global) |
| Frames de pila | todos | casi inexistentes |

Evidencia concreta (desensamblado con capstone):
- `0x10440 draw_text_box_variant`: entra leyendo `d1` (`andi.w #$3ff,d1`), usa
  `d0,d2,d3,d4,d5,d6`, no guarda/restaura ni abre frame; `rts`.
- `0x10630` (VM): lee el byte del guion con `(a6)` y avanza `a6`, despacha por
  tabla y `jsr (a1)` — estado de script en `a6` a través de las llamadas.
- `0x10838 print_char`: usa `d7` como contador de desplazamiento **sin
  inicializarlo** (lo hereda del llamante).
- Únicos `link a6` reales: `0x3a62e`/`0x3a734` (módulo de música `0x3axxx`), con
  el prólogo de compilador `link.w a6,#0 ; movem.l d0-d7/a0-a6,-(a7)` y args en
  pila (`8(a6)`, `a(a6)`). → esa parte **sí** parece C compilado.

**Conclusión M0:** el **motor del juego es ensamblador escrito a mano** (o un
compilador no recuperado; descartado Alcyon por la ausencia total de frames y el
paso por registros con estado persistente en `a5`/`a6`). El **runtime/arranque y
el módulo de música** provienen de C (Alcyon).

## 3. Implicación para el plan

Una *matching decomp en C* del **motor** es **imposible por construcción**: no
hay fuente C que reproducir; el original es asm. Lo alcanzable y honesto es:

- **Matching disassembly (plan B del `PLAN_MATCHING_DECOMP.md`)**: reconstruir
  fuentes **ASM** (+ datos) que se ensamblen/enlacen a un `KULT.PRG` **byte a
  byte idéntico**. Sigue entregando un árbol fuente verificable y modificable
  (el objetivo real del usuario), solo que en `.s` en vez de `.c`.
- El C ya reconstruido vive en [`kult-atari-st-c`](https://github.com/hunkstalker/kult-atari-st-c)
  (`src/`) y queda como **documentación ejecutable** del comportamiento.
- El **módulo de música `0x3axxx`** y el **crt0/runtime** sí pueden ir en C
  (Alcyon), si se fija la versión exacta de DRI C.

### Decisión (cerrada 2026-10-16)

El objetivo se acepta como **matching disassembly** (ASM + datos → PRG byte a
byte). Ya está **cerrado** con vasm, incluidas las relocs derivadas de la fuente
(`matching/RELOCS.md`). No se invierte en buscar un compilador C alternativo del
motor.

## 4. Herramientas creadas

- `tools/match_check.py` — compara un PRG candidato con el original (cabecera,
  SHA-256, relocs, primer byte divergente + contexto desensamblado). Auto-test
  verificado mutando un byte en `0x135da`.
- Este documento + `docs/PLAN_MATCHING_DECOMP.md` (plan).

## 5. Comandos

```sh
# comparar dos PRG (código de salida 0 = idénticos)
python3 tools/match_check.py work/disk_a/KULT.PRG CANDIDATO.PRG
# volcar asm de una función del original (base imagen + 0x10000)
python3 tools/prg_dis.py work/disk_a/KULT.PRG --start $((ADDR-0x10000+28)) --len N --base 0x10000
```
