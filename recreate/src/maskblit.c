/* maskblit.c — the masked screen-row blitter family.
 *
 * FUN_00012698 @ 0x12698: precompute the edge masks a masked row blit needs for a
 * blit of D2 pixels at bit offset D7 (both words), storing them in 0x1a538 (first
 * word), 0x1a53a (last word) and 0x1a53c (number of 4-word groups carried by the
 * row).  Pure: reads D2/D7, writes three image words.
 *
 * FUN_000123c0 @ 0x123c0: blit one row.  The first 4-word group is merged into the
 * destination under 0x1a538 (OR 0x1a53a when there is only one group), the middle
 * groups are copied whole, and the last group is merged under 0x1a53a.  A0 is the
 * destination, A1 the source; A0 is restored on exit (the caller keeps stepping it).
 *
 * FUN_0001215e @ 0x1215e: run FUN_000123c0 over D3 rows.  The source is A0-0x8000
 * (the back buffer), the destination stride is 0xa0.  If the low-memory byte 0xd8ea
 * is not 'A' it clears 0x1d402 first.
 *
 * All three are pure image code (no hardware, no traps), so the differential suite
 * drives them directly with declared D2/D3/D7/A0/A1.
 */
#include <stdint.h>

#include "machine.h"
#include "addrs.h"

/* 68k word shift counts are taken modulo 64; a word result of a shift of 16 or
 * more is zero.  Both helpers take the raw count so a caller never has to clamp. */
static uint16_t lsr_w(uint16_t v, unsigned count) {
    count &= 63;
    return count >= 16 ? 0 : (uint16_t)(v >> count);
}
static uint16_t asl_w(uint16_t v, unsigned count) {
    count &= 63;
    return count >= 16 ? 0 : (uint16_t)(v << count);
}

void g_fun_12698(uint8_t *img, uint32_t d2, uint32_t d7) {
    uint16_t d0 = (uint16_t)d7;
    uint16_t d1 = (uint16_t)~lsr_w(0xffff, d0);   /* first-word mask */
    d0 = (uint16_t)(d0 >> 2);
    uint16_t d5 = (uint16_t)(4 - d0);
    uint16_t d6 = (uint16_t)d2;
    uint16_t d4 = 1;

    /* sub.w d5,d6: d6 is updated, then bls skips the group count when d2 <= d5. */
    uint16_t before = d6;
    d6 = (uint16_t)(before - d5);
    if (!(word_sub_extend(before, d5) || d6 == 0)) {
        for (;;) {
            before = d6;
            d4 = (uint16_t)(d4 + 1);
            d6 = (uint16_t)(before - 4);
            if (word_sub_extend(before, 4) || d6 == 0)   /* subi.w / bhi */
                break;
        }
    }

    d6 = (uint16_t)(-d6);                          /* neg.w */
    d6 = (uint16_t)(d6 << 2);                      /* lsl.w #2 */
    uint16_t right = (uint16_t)~asl_w(0xffff, d6); /* asl.w d6,d5 / not.w */

    wr16(img + A_BLIT_MASK_FIRST, d1);
    wr16(img + A_BLIT_MASK_LAST, right);
    wr16(img + A_BLIT_GROUPS, d4);
}

/* One 4-word group merged into the destination under d4; d5 = ~d4. */
static void merge_group(uint8_t *img, uint32_t *a0, uint32_t *a1,
                        uint16_t d4, uint16_t d5) {
    for (int i = 0; i < 4; i++) {
        uint16_t s = be16(img + *a1);
        uint16_t d = be16(img + *a0);
        wr16(img + *a0, (uint16_t)((d & d4) | (s & d5)));
        *a0 += 2;
        *a1 += 2;
    }
}

void g_fun_123c0(uint8_t *img, uint32_t a0, uint32_t a1) {
    uint16_t d4 = be16(img + A_BLIT_MASK_FIRST);
    uint16_t d6 = (uint16_t)(be16(img + A_BLIT_GROUPS) - 1);
    if (d6 == 0)                                   /* subq/bne misses: single group */
        d4 = (uint16_t)(d4 | be16(img + A_BLIT_MASK_LAST));
    uint16_t d5 = (uint16_t)~d4;

    merge_group(img, &a0, &a1, d4, d5);

    for (;;) {
        uint16_t before = d6;
        d6 = (uint16_t)(before - 1);               /* subq.w #1,d6 */
        if (word_sub_extend(before, 1))            /* bcs: borrow -> done */
            break;
        if (d6 == 0) {                             /* beq: last masked group */
            d4 = be16(img + A_BLIT_MASK_LAST);
            d5 = (uint16_t)~d4;
            merge_group(img, &a0, &a1, d4, d5);
            break;
        }
        wr32(img + a0, be32(img + a1));            /* move.l (a1)+,(a0)+ x2 */
        a0 += 4;
        a1 += 4;
        wr32(img + a0, be32(img + a1));
        a0 += 4;
        a1 += 4;
    }
}

void g_fun_1215e(uint8_t *img, uint32_t a0, uint32_t d2, uint32_t d3, uint32_t d7) {
    g_fun_12698(img, d2, d7);
    if (img[A_BLIT_D8EA] != 0x41)
        img[A_DAT_1D402] = 0;
    uint32_t n = (d3 - 1) & 0xffff;                /* dbf counts body runs */
    do {
        g_fun_123c0(img, a0, a0 - 0x8000u);
        a0 += 0xa0;
        n = (n - 1) & 0xffff;
    } while (n != 0xffff);
}

/* FUN_00012466 @ 0x12466: copia D3 filas del buffer 0x1a534 con máscaras de borde
 * ($1a538/$1a53a) y $1a53c grupos de 4 words por fila. Cada fila: primer grupo
 * enmascarado con $1a538, grupos centrales copiados literales, último grupo enmascarado
 * con $1a53a. A0 avanza 0xa0/fila, A1 0x40/fila. Cierra con una espera de VBL. */
void g_fun_13594(uint8_t *img);
void g_fun_12466(uint8_t *img, uint32_t a0, uint32_t a1, uint32_t d3) {
    uint32_t d7 = (d3 - 1) & 0xffff;
    uint32_t d4 = be16(img + 0x1a538);
    uint32_t d5 = be16(img + 0x1a53a);
    uint32_t a2 = a0, a3 = a1;
    for (;;) {
        uint32_t d6 = (be16(img + 0x1a53c) - 1) & 0xffff;
        uint32_t d0, d1, d2, dv;
        d0 = be16(img + a1); a1 += 2;
        d1 = be16(img + a1); a1 += 2;
        d2 = be16(img + a1); a1 += 2;
        dv = be16(img + a1); a1 += 2;
        uint32_t src[4] = {d0, d1, d2, dv};
        for (uint32_t p = 0; p < 4; p++) {
            wr16(img + a0, ((be16(img + a0) & d4) | src[p]) & 0xffff);
            a0 += 2;
        }
        for (;;) {
            d6 = (d6 - 1) & 0xffff;
            if (d6 == 0) break;
            wr32(img + a0, be32(img + a1)); a0 += 4; a1 += 4;
            wr32(img + a0, be32(img + a1)); a0 += 4; a1 += 4;
        }
        d0 = be16(img + a1); a1 += 2;
        d1 = be16(img + a1); a1 += 2;
        d2 = be16(img + a1); a1 += 2;
        dv = be16(img + a1); a1 += 2;
        src[0] = d0; src[1] = d1; src[2] = d2; src[3] = dv;
        for (uint32_t p = 0; p < 4; p++) {
            wr16(img + a0, ((be16(img + a0) & d5) | src[p]) & 0xffff);
            a0 += 2;
        }
        a0 = a2 + 0xa0;
        a1 = a3 + 0x40;
        a2 = a0;
        a3 = a1;
        d7 = (d7 - 1) & 0xffff;
        if (d7 == 0xffff) break;
    }
    g_fun_13594(img);
}

/* FUN_000120a8 @ 0x120a8: busca el primer hueco libre en la tabla de 10 entradas de 16
 * bytes en 0x1a850 y guarda [word d4][long a0][word d7][word d0][word d1][word d2][word d3];
 * copia $1a851 a $1ad0a. */
void g_fun_120a8(uint8_t *img, uint32_t d4, uint32_t a0, uint32_t d7,
                 uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3) {
    uint32_t a2 = 0x1a850;
    for (uint32_t d6 = 9;; d6 = (d6 - 1) & 0xffff) {
        if (be16(img + a2) == 0)
            break;
        a2 += 0x10;
        if (d6 == 0)
            break;
    }
    wr16(img + a2, d4 & 0xffff); a2 += 2;
    wr32(img + a2, a0); a2 += 4;
    wr16(img + a2, d7 & 0xffff); a2 += 2;
    wr16(img + a2, d0 & 0xffff); a2 += 2;
    wr16(img + a2, d1 & 0xffff); a2 += 2;
    wr16(img + a2, d2 & 0xffff); a2 += 2;
    wr16(img + a2, d3 & 0xffff);
    img[0x1ad0a] = img[0x1a851];
}

/* Cuerpo compartido de selección de icono (0x120f8): dado A1 (entrada de la tabla), D1
 * (valor a escribir) devuelve por out[0..6] = a0, d4, d7, d0, d1, d2, d3 y out[7] = d5. */
static void hint_body(uint8_t *img, uint32_t a1, uint32_t d1, uint32_t *o) {
    uint32_t d4 = be16(img + a1);
    wr16(img + a1, d1 & 0xffff);
    uint32_t dest = be32(img + a1 + 2);
    uint32_t d0 = (be32(img + A_SCREEN_PTR_A) & 0xffff0000u) | (dest & 0xffff);
    uint32_t a0 = d0;
    uint32_t d7 = be16(img + a1 + 6);   /* dest se enmascaró a 0xffff: altos 0 */
    d0 = (a0 & 0xffff0000u) | be16(img + a1 + 8);
    d1 = be16(img + a1 + 10);
    uint32_t d2 = be16(img + a1 + 12);
    uint32_t d3 = be16(img + a1 + 14);
    img[0x1ad0a] = img[0x1a851];
    o[0] = a0; o[1] = d4; o[2] = d7; o[3] = d0; o[4] = d1; o[5] = d2; o[6] = d3; o[7] = 0;
}

/* FUN_000120dc @ 0x120dc (D1=2) y FUN_000120e4 @ 0x120e4 (D1=0): seleccionan el icono
 * d0-esimo de la tabla 0x1a850. */
void g_fun_120dc(uint8_t *img, uint32_t d0, uint32_t *o) {
    hint_body(img, 0x1a850 + ((d0 - 1) & 0xffff) * 0x10, 2, o);
}
void g_fun_120e4(uint8_t *img, uint32_t d0, uint32_t *o) {
    hint_body(img, 0x1a850 + ((d0 - 1) & 0xffff) * 0x10, 0, o);
}

/* FUN_0001213a @ 0x1213a: busca en la tabla el word d0; si lo encuentra lo desactiva
 * (cuerpo con D1=0) y deja d5=0; si no, d5=1. */
void g_fun_1213a(uint8_t *img, uint32_t d0, uint32_t *o) {
    uint32_t a1 = 0x1a850;
    for (uint32_t d6 = 9;; d6 = (d6 - 1) & 0xffff) {
        if (be16(img + a1) == (d0 & 0xffff)) {
            hint_body(img, a1, 0, o);
            return;
        }
        a1 += 0x10;
        if (d6 == 0)
            break;
    }
    o[7] = 1;
}

/* FUN_0001222e @ 0x1222e: selecciona el icono A6[1] (0x120e4) y lo blitea (0x1215e). */
void g_fun_1222e(uint8_t *img, uint32_t a6, uint32_t *a6_out) {
    uint32_t o[8];
    g_fun_120e4(img, img[a6 + 1], o);
    g_fun_1215e(img, o[0], o[5], o[6], o[2]);      /* a0, d2, d3, d7 */
    *a6_out = a6 + 2;
}

/* FUN_0001232e @ 0x1232e: mientras 0x1213a encuentre el icono 1, lo blitea (0x1215e) y
 * luego blitea un trazo de 2x15 desde la dirección del icono (0x10fec + 0x1215e). */
uint32_t g_screen_offset_d7(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t *d7out);
void g_fun_1232e(uint8_t *img, uint32_t *a6) {
    *a6 += 1;
    wr16(img + 0x1a484, 0);
    for (;;) {
        uint32_t o[8];
        g_fun_1213a(img, 1, o);
        if (o[7] != 0)
            break;
        g_fun_1215e(img, o[0], o[5], o[6], o[2]);
        uint32_t d7;
        uint32_t a0 = g_screen_offset_d7(img, o[3], o[4], &d7);
        g_fun_1215e(img, a0, 2, 0xf, d7);
    }
}

/* FUN_00012368 @ 0x12368 (icono 2) y FUN_00012384 @ 0x12384 (icono 3): a6++ y mientras
 * 0x1213a encuentre el icono, lo blitean. */
void g_fun_12368(uint8_t *img, uint32_t *a6) {
    *a6 += 1;
    for (;;) {
        uint32_t o[8];
        g_fun_1213a(img, 2, o);
        if (o[7] != 0) break;
        g_fun_1215e(img, o[0], o[5], o[6], o[2]);
    }
}
void g_fun_12384(uint8_t *img, uint32_t *a6) {
    *a6 += 1;
    for (;;) {
        uint32_t o[8];
        g_fun_1213a(img, 3, o);
        if (o[7] != 0) break;
        g_fun_1215e(img, o[0], o[5], o[6], o[2]);
    }
}
