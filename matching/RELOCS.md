# RELOCS — derivar la tabla de relocalizaciones — ✅ RESUELTA (2026-10-16)

Contexto en `matching/README.md`, `docs/PLAN_MATCHING_DECOMP.md`.

## Resultado

La tabla de relocs **ya no se toma del original**: la **deriva vasm** de los
símbolos de la fuente. `python3 matching/build_vasm.py` reconstruye `KULT.PRG`
**byte a byte idéntico** (`sha256 2e85f223…`), y ahora imprime:

```
relocs derivados por vasm: 2171 (original 2171)  iguales: True
```

(2171/2171, 0 de faltantes y 0 de sobrantes; `text` y cabecera 100 % de la
fuente). El único matiz es el **sembrado de la clasificación** (opción A
acordada con el usuario): se usa del original el **conjunto de destinos**
(direcciones apuntadas) para decidir qué direcciones necesitan símbolo; los
**offsets y el encoding DRI de la tabla los genera vasm**.

## Mecanismo (hallazgo clave)

El supuesto antiguo «`vasm -Ftos` resuelve los relocs y no emite tabla» era
**falso**: `vasm -Ftos` **emite una tabla DRI** por cada **referencia absoluta
de 32 bits a una etiqueta** (`output_tos.c`: `tos_writerelocs`), con `FLAGS=0x00`
(el original). Por tanto **no hacen falta `link68`/`relmod`** (se caen los
bloqueos 2 y 4 del plan antiguo).

Detalles verificados:

- Un literal `$xxxx.l` **no** genera reloc; un **símbolo** sí. `name equ
  f_010000+$c` / `-$c` (expresión relocalizable) también genera reloc, y produce
  el **mismo byte** que el literal (probado sobre la fuente real).
- Sintaxis MOT de vasm: hex `$` (no `0x`); **no** admite `#(expr)` ni sufijo
  `.l` tras un símbolo en operandos `abs.l` … salvo que se defina el símbolo con
  `equ` y se referencie por nombre (entonces vasm elige `abs.l` por ser
  relocalizable, conservando los 4 bytes). Sustituir `$xxxx.l` → `s_xxxx`
  funciona; `$xxxx.l` → `f_010000+$xxxx` a veces no (sintaxis).
- `equ` de un valor absoluto **no** relocaliza; `equ` de una expresión con un
  label de sección **sí**.

## Diagnóstico de los 2171 relocs

| categoría | nº | cómo se resuelve |
|---|---|---|
| campos largos de instrucción (`abs.l` / inmediato largo) | 1946 | `autogen.py` sustituye el literal por el símbolo del destino |
| punteros incrustados en datos (tablas C) | 225 | `dc.l <símbolo>` (carvado en fragmentos + recursos) |
| total | 2171 | todos a offset par |

- 621 destinos distintos; 233 requieren símbolo nuevo (`s_%06x`); el resto ya
  tenían nombre (funciones/globals/symbols/equ). Todos se definen como
  `s_%06x equ f_010000±$c` (relocalizable).
- Los 225 punteros de datos están en **2 fragmentos** autogenerados (tablas
  inline del compilador C): `auto_015ac8.s` (~40) y `auto_03ae68.s` (36) —música—
  y 189 en la región que `layout.json` llama `SOUCO.BIN`. En `gen_range` esas
  posiciones (que no son campo de ninguna instrucción) se carvan como `dc.l`.
- Falsos positivos del criterio ingenuo «el longword vale un destino»: bytes de
  datos (`$4246`/`$8888` en sonido/sprites) que coinciden con direcciones reales.
  Se evitan restringiendo a **campos de instrucción** y a **posiciones de reloc**
  en datos.

## Implementación

- **`matching/relocs.py`** (nuevo): `analyze(prg)` → `(fixes, names)` con
  `names[valor_destino] = símbolo` (reusa `f_/A_/s_/equ` o `s_%06x`);
  `def_expr(v,name)` = `name equ f_010000±$c`; `emit_bytes(...)` = `dc.b` con
  `dc.l` en las posiciones de reloc.
- **`autogen.py`**: instrumenta `prg_dis._reloc_long` para localizar los campos
  largos de cada instrucción; sustituye por símbolo los que son destino de reloc;
  `gen_range` emite instrucciones + `dc.l` (punteros) + `dc.b` (resto) con
  **etiquetas en su dirección exacta** (carvado). Un bug de coordenadas
  (runtime vs offset text-relativo) y el decodificado de segmentos truncados se
  corrigieron.
- **`build.py`**: define los destinos como expresiones relocalizables (incluidos
  los `equ` de fuera del text, antes absolutos) y emite los recursos con
  `dc.l` en las posiciones de reloc.
- **`build_vasm.py`**: paso 4 = salida de vasm **tal cual** (ya no `orig[end:]`)
  + informe de igualdad de la tabla derivada.

## Comandos

```sh
cd /app/kult-port
python3 matching/build_vasm.py            # PRG byte-idéntico; relocs DERIVADOS
python3 tools/match_check.py work/disk_a/KULT.PRG matching/out/KULT.PRG
# (2171 == 2171, sha256 2e85f223…)
```

Toolchain: `matching/setup_toolchain.sh` (Alcyon/tos1x + vasm). El `as68` de
tos1x sigue teniendo bug de fase con el programa completo (y el original
segfaultea en Linux); por eso se usa **vasm**, que además ya no necesita
`link68`/`relmod`.

## B2-lite (2026-10-16) — hecho, luego superado por B2-estricto

El build deriva **todo el código** de la fuente:

- `newdefs`: escaneo de los fragmentos `.s` → define los `s_*` referenciados.
- `target_vals`: globals fuera del text (direcciones) + los `addr` de `equ.txt`
  (`equ.txt` lleva tipo `addr`/`const`; `s_15623` es la única `const`).

Esto bajó la semilla a 189 líneas; **B2-estricto (abajo) la eliminó del todo**
al transcribir las tablas de datos a `data_*.s`.

## B2-estricto (sin ningún metadato del original) — ✅ HECHO (2026-10-16)

Se eliminó la semilla. Los 189 relocs dentro de recursos son **tablas de lógica**:

| bloque | nº | qué es |
|---|---|---|
| punteros a código (0x9eaa..0xa106) | 152 | tabla de despacho/script → `dc.l` |
| tabla de recursos `nombre\0`+u32 (0xa2d2..) | 23 | nombre → offset del recurso |
| tabla de estado (0xa752..0xa776) | 9 | punteros a variables |
| punteros sueltos (0x99ca, 0xa4d8, 0xa7d6, 0xa822) | 5 | estructuras de datos |

**RE (por qué no se derivan solas):** por valor/estructura **no** se distinguen de
sonido/sprites: "el longword vale una dirección" da ~12.000 falsos positivos, y
las rachas de punteros verdaderas (152, 9) son indistinguibles de rachas
casuales en sonido (hasta len 13). Además sus *posiciones* viven dentro de bytes
que son **assets** (gitignored): symbolizarlas en fuente sin commitear assets
exige *conocerlas*.

**Solución (estilo matching decomp):** transcribirlas a **fuente**
`matching/src/data_*.s` (7 fragmentos, 988 B) — son lógica (direcciones/nombres),
no arte, así que se pueden versionar. `tools/gen_data_tables.py` las genera una
vez desde el PRG (`make gendata`); luego se versionan, como `auto_*.s`.

El build emite esos fragmentos en lugar de los bytes crudos del recurso; el resto
de cada recurso sigue saliendo de `matching/data/` (assets). `reloc_seed.txt`
**eliminado**.

**Resultado:** `make indep` (build desde `git archive HEAD`, **sin el PRG** y sin
ningún metadato derivado del original) → `sha256 2e85f223…` idéntico.

## Latiguillo: `data_*.s` ilustran el RE

La tabla de recursos queda **legible**: `A_FONT_DATA`, `A_ANIM_BACKUP`, nombres
`SOURI.BIN`/`SOUCO.BIN`… con sus offsets simbólicos. Es el mayor salto de "dump"
a "decompilación".
