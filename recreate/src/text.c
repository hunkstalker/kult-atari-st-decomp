/* text.c — the text-entry walker.
 *
 * FUN_00010f8e @ 0x10f8e: advance A1 by D4 word-length entries ([word len][data], the
 * length includes the length word), then set cur_str_end = A1 + word(A1) and A1 += 2.
 * Returns the updated A1 (the oracle's a1 at rts).
 */
#include <stdint.h>

#include "machine.h"
#include "addrs.h"

static uint32_t ror16(uint32_t v, uint32_t n) {
    n &= 15;
    return n ? (((v >> n) | (v << (16 - n))) & 0xffff) : (v & 0xffff);
}
static uint32_t rol16(uint32_t v, uint32_t n) {
    n &= 15;
    return n ? (((v << n) | (v >> (16 - n))) & 0xffff) : (v & 0xffff);
}

/* print_char @ 0x10838: draw the glyph for D0's low byte at (cursor_x, cursor_y), advance the
 * cursor, using the 6x4 font at image 0x1d202 and the colour table at *(0x1a4d8). The screen
 * base is screen_address(x,y) - *(0x1a46a) (the logical-vs-draw buffer offset). */
void g_print_char(uint8_t *img, uint32_t d0) {
    uint32_t ch = d0 & 0xff;
    uint32_t x = be16(img + A_CURSOR_TEXT_X);
    uint32_t y = be16(img + A_CURSOR_TEXT_Y);
    wr16(img + A_CURSOR_TEXT_X, (x + 1) & 0xffff);

    uint32_t xd = (x << 2) & 0xffff;
    uint32_t d7 = xd & 0xf;
    uint32_t a0 = be32(img + A_SCREEN_PTR_A);
    a0 += (xd & 0xfff0) >> 1;
    a0 += (y & 0xffff) * 0xa0u;
    a0 -= be32(img + A_SCREEN_DRAW_BASE);

    uint32_t font = A_FONT_DATA + (ch * 6);
    uint32_t tbl = be32(img + A_COLOR_TABLE);
    uint32_t d1 = ror16(0x0fff, d7);
    uint32_t d3 = (~d1) & 0xffff;

    for (int row = 0; row < 6; row++) {
        uint32_t g = img[font++];
        uint32_t d2 = ror16(be16(img + tbl + g), d7);
        for (int w = 0; w < 4; w++) {
            uint32_t v = be16(img + a0);
            v = (v & d1) | (d3 & d2);
            wr16(img + a0, v & 0xffff);
            d2 = rol16(d2, 4);
            a0 += 2;
        }
        a0 += 0x98;
    }
}

/* print_word @ 0x108a2: draw the string at A5 up to cur_str_end (0x1a4dc), handling the
 * glyph flags 0x40 (word separator -> stop), 0x80 (append 'E') and 0xc0 (append 'A').
 * Returns the status in D0: 1 when it reached cur_str_end (and sets 0x1a508 = 0xff),
 * 0 when it stopped at a separator/zero glyph; the final A5 goes out through *a5_out. */
uint32_t g_print_word(uint8_t *img, uint32_t a5, uint32_t *a5_out) {
    uint32_t end = be32(img + A_CUR_STR_END);
    if ((img[a5] & 0x3f) == 0)
        goto L_c4;
L_ac:
    if (a5 == end) {
        img[A_TEXT_END_FLAG] = 0xff;
        *a5_out = a5;
        return 1;
    }
    if ((img[a5] & 0x3f) == 0)
        goto L_ee;
    g_print_char(img, img[a5] & 0x3f);
L_c4:
    {
        uint32_t d1 = img[a5] & 0xc0;
        a5++;
        if (d1 == 0)
            goto L_ac;
        if (d1 == 0x80) { g_print_char(img, 0x25); goto L_ac; }   /* append 'E' */
        if (d1 == 0x40) { *a5_out = a5; return 0; }               /* word separator: stop */
        g_print_char(img, 0x21);                                  /* append 'A' */
        goto L_ac;
    }
L_ee:
    if ((img[a5] & 0xc0) == 0)
        a5++;
    *a5_out = a5;
    return 0;
}

/* position_text @ 0x10fc4: skip (D4-4) byte-length entries from A5 ([u8 len][data], len
 * includes itself), then set cur_str_end = A5 + *A5 and return A5 + 1. Also stores D4's low
 * word at 0x1a482. */
uint32_t g_position_text(uint8_t *img, uint32_t a5, uint32_t d4) {
    wr16(img + A_TEXT_INDEX, d4 & 0xffff);
    uint32_t n = (d4 - 5) & 0xffff;
    if ((d4 & 0xffff) >= 5) {
        do {
            a5 += img[a5];
            n = (n - 1) & 0xffff;
        } while (n != 0xffff);
    }
    uint32_t a2 = a5;
    a5 += img[a5];
    wr32(img + A_CUR_STR_END, a5);
    return a2 + 1;
}

/* FUN_00010f8e @ 0x10f8e: avanza D4 entradas [word len][datos] desde A1, fija
 * cur_str_end = A1 + word(A1) y devuelve A1 + 2. La usan el motor de animacion
 * (bancos 0x28ad2/0x31072), el sonido y el formulario de texto. */
uint32_t g_advance_text_entry(uint8_t *img, uint32_t a1, uint32_t d4) {
    uint32_t n = d4 & 0xffff;
    if (n != 0) {
        n = (n - 1) & 0xffff;                       /* subq.w #1,d4 */
        do {
            a1 += be16(img + a1);                   /* move.w (a1),d5; adda.l d5,a1 */
            n = (n - 1) & 0xffff;                   /* dbf d4 */
        } while (n != 0xffff);
    }
    uint32_t end = a1 + be16(img + a1);
    wr32(img + A_CUR_STR_END, end);
    return a1 + 2;
}

/* FUN_0001090e @ 0x1090e: print as many words from A5 as fit in *(0x1a512) cells, one
 * space between them; the word that does not fit, the end of the string or a full line
 * stops it. D0/D1 are preserved (the entry `movem.w` saves them). Hands back the final A5
 * and the leftover width through the out-pointers. */
uint32_t g_fun_10946(uint8_t *img, uint32_t a5, uint32_t *a4_out);
uint32_t g_fun_1090e(uint8_t *img, uint32_t a5, uint32_t d0,
                     uint32_t *a5_out, uint32_t *d6_out) {
    uint32_t d6 = be16(img + A_TEXT_BOX_W);
    for (;;) {
        uint32_t a4 = 0;
        uint32_t w = g_fun_10946(img, a5, &a4);
        if (d6 < w) break;                          /* bcs: la palabra no cabe */
        d6 = (d6 - w) & 0xffff;
        uint32_t s = g_print_word(img, a5, &a5);
        if (s != 0) break;                          /* bne: alcanzado cur_str_end */
        if (d6 == 0) break;
        d6 = (d6 - 1) & 0xffff;
        g_print_char(img, 0);                       /* separador (espacio) */
    }
    *a5_out = a5;
    *d6_out = d6;
    return d0 & 0xffff;
}

/* FUN_00010b24 @ 0x10b24: measure the line from A5 (FUN_00010998) and grow *(0x1a512) to
 * the widest word + 2 if needed, then print the words that fit (FUN_0001090e) and pad the
 * line with spaces up to the leftover width. Returns the advanced A5 (the oracle's a5). */
void g_fun_10998(uint8_t *img, uint32_t a5, uint32_t *d5_out, uint32_t *d6_out);
void g_fun_10b46(uint8_t *img, uint32_t d6);
uint32_t g_fun_10b24(uint8_t *img, uint32_t a5) {
    uint32_t d5, d6;
    g_fun_10998(img, a5, &d5, &d6);
    d6 = (d6 + 2) & 0xffff;
    if (d6 >= be16(img + A_TEXT_BOX_W))
        wr16(img + A_TEXT_BOX_W, d6);
    uint32_t a5o, left;
    g_fun_1090e(img, a5, 0, &a5o, &left);
    if (left != 0)
        g_fun_10b46(img, (left - 1) & 0xffff);
    return a5o;
}

/* FUN_00010b46 @ 0x10b46: pad D6+1 spaces (tail shared by 0x10b24 and 0x10aee). */
void g_fun_10b46(uint8_t *img, uint32_t d6) {
    do {
        g_print_char(img, 0);
        d6 = (d6 - 1) & 0xffff;
    } while (d6 != 0xffff);
}

/* FUN_00010946 @ 0x10946: measure one "word" of the text bank from A5 (copied to A4).
 * Counts 1 per printable byte, +1 more when the byte carries an 0x80/0xc0 flag; a 0x40
 * flag ends the word counting it, and a byte with no low bits (byte & 0x3f == 0) ends it
 * without counting. Returns the count in D0 and the stopping A4 through *a4_out. */
uint32_t g_fun_10946(uint8_t *img, uint32_t a5, uint32_t *a4_out) {
    uint32_t end = be32(img + A_CUR_STR_END);
    uint32_t a4 = a5;
    uint32_t d0 = 0;
    if ((img[a4] & 0x3f) == 0) {
        d0 = 1;
        a4 += 1;
        if (a4 == end) { *a4_out = a4; return 1; }
    }
    for (;;) {
        if ((img[a4] & 0x3f) == 0) { *a4_out = a4; return d0; }
        d0 += 1;
        uint32_t c0 = img[a4] & 0xc0;
        if (c0 == 0x40) { a4 += 1; *a4_out = a4; return d0; }
        if (c0 != 0) d0 += 1;
        a4 += 1;
        if (a4 == end) { *a4_out = a4; return d0; }
    }
}

/* FUN_00010998 @ 0x10998: walk the text bank from A5 to cur_str_end counting the number
 * of words (D5) and the widest one (D6, in font cells). A5 is restored on return. */
void g_fun_10998(uint8_t *img, uint32_t a5, uint32_t *d5_out, uint32_t *d6_out) {
    uint32_t end = be32(img + A_CUR_STR_END);
    uint32_t d5 = 0, d6 = 0, a4 = a5;
    do {
        uint32_t d0 = g_fun_10946(img, a5, &a4);
        d5 += 1;
        if (d6 < d0) d6 = d0;
        a5 = a4;
    } while (a4 != end);
    *d5_out = d5 & 0xffff;
    *d6_out = d6 & 0xffff;
}

/* FUN_000109bc @ 0x109bc: greedy word-wrap of the bank from A5 into lines of width
 * *(0x1a512); returns the line count (D5) and the leftover width (D6) on the last line. */
void g_fun_109bc(uint8_t *img, uint32_t a5, uint32_t *d5_out, uint32_t *d6_out) {
    uint32_t end = be32(img + A_CUR_STR_END);
    uint32_t a4 = a5;
    uint32_t d5 = 1;
    uint32_t d6 = be16(img + A_TEXT_BOX_W);
    for (;;) {
        a5 = a4;
        if (a5 == end) break;
        uint32_t d0 = g_fun_10946(img, a5, &a4);
        if (d6 < d0) {
            d5 += 1;
            d6 = (be16(img + A_TEXT_BOX_W) - d0 - 1) & 0xffff;
            continue;
        }
        d6 = (d6 - d0) & 0xffff;
        if (d6 == 0) {
            d5 += 1;
            d6 = (be16(img + A_TEXT_BOX_W) - d0 - 1) & 0xffff;
            continue;
        }
        d6 = (d6 - 1) & 0xffff;
    }
    *d5_out = d5 & 0xffff;
    *d6_out = d6 & 0xffff;
}

/* FUN_00010fb4 @ 0x10fb4: position_text, pero si D4 < 4 toma el índice de A6[1] (tras
 * intercambiar los bytes de D4) y avanza A6; luego cae en position_text (0x10fc4). */
uint32_t g_fun_10fb4(uint8_t *img, uint32_t a5, uint32_t d4, uint32_t *a6) {
    if ((d4 & 0xffff) < 4) {
        uint32_t lo = (rol16(d4 & 0xffff, 8) & 0xff00u) | (img[*a6 + 1] & 0xff);
        d4 = (d4 & 0xffff0000u) | lo;
        *a6 += 1;
    }
    return g_position_text(img, a5, d4);
}

/* FUN_00010aee @ 0x10aee: centra la línea de A5 reduciendo *(0x1a512) en (ancho-total)/2
 * y sangrando con espacios, y luego cae en el cuerpo de 0x10b24 (medir + imprimir +
 * rellenar). Devuelve el A5 avanzado. */
uint32_t g_fun_10b24(uint8_t *img, uint32_t a5);
void g_fun_10b46(uint8_t *img, uint32_t d6);
uint32_t g_fun_10aee(uint8_t *img, uint32_t a5) {
    uint32_t a5_in = a5;
    uint32_t total = 0, a4 = 0;
    do {
        uint32_t w = g_fun_10946(img, a5, &a4);
        total = (total + w) & 0xffff;
        a5 = a4;
    } while (a4 != be32(img + A_CUR_STR_END));
    a5 = a5_in;
    uint32_t d7 = (((be16(img + A_TEXT_BOX_W) - total) & 0xffff) >> 1) & 0xffff;
    if (d7 != 0) {
        wr16(img + A_TEXT_BOX_W, (be16(img + A_TEXT_BOX_W) - d7) & 0xffff);
        g_fun_10b46(img, (d7 - 1) & 0xffff);
    }
    return g_fun_10b24(img, a5);
}

/* FUN_000109fe @ 0x109fe: activa el overlay de texto A (cursor + tabla 0x41b76) y lo
 * dibuja con 0x10aee. Si *(0x1acc6) == 0x87 (modo sin overlay) sale sin más. */
void g_fun_109fe(uint8_t *img, uint32_t a6) {
    if (img[A_MODE_FLAG] == 0x87)
        return;
    img[A_TEXT_ROW] = img[A_TEXT_COL];
    wr32(img + A_SCREEN_DRAW_BASE, 0x8000);
    wr16(img + A_CURSOR_TEXT_X, be16(img + A_OVERLAY_X));
    wr16(img + A_CURSOR_TEXT_Y, be16(img + A_OVERLAY_Y));
    wr32(img + A_COLOR_TABLE, 0x1d3c2);
    uint32_t a5 = g_fun_10fb4(img, 0x41b76, img[A_TEXT_SEL_A], &a6);
    g_fun_10aee(img, a5);
}

/* FUN_00010a88 @ 0x10a88: igual que 0x109fe pero para el overlay B (0x2f/0xc1, tabla
 * 0x41586) y sin la comprobación de modo. */
void g_fun_10a88(uint8_t *img, uint32_t a6) {
    img[A_TEXT_ROW] = 0x20;
    wr32(img + A_SCREEN_DRAW_BASE, 0x8000);
    wr16(img + A_CURSOR_TEXT_X, 0x2f);
    wr16(img + A_CURSOR_TEXT_Y, 0xc1);
    wr32(img + A_COLOR_TABLE, 0x1d3c2);
    uint32_t a5 = g_fun_10fb4(img, 0x41586, img[A_TEXT_SEL_B], &a6);
    g_fun_10aee(img, a5);
}

/* FUN_00010a54 @ 0x10a54: dibuja el marco del overlay A: screen_address(X-1, Y-2) y el
 * blit de fila enmascarado 0x1215e con D2 = ancho+2, D3 = 9. D7 sale de 0x10fec (la
 * fase de píxel), no del llamante. */
uint32_t g_screen_offset_d7(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t *d7out);
void g_fun_1215e(uint8_t *img, uint32_t a0, uint32_t d2, uint32_t d3, uint32_t d7);
void g_fun_10a54(uint8_t *img) {
    if (img[A_MODE_FLAG] == 0x87)
        return;
    uint32_t d0 = (be16(img + A_OVERLAY_X) - 1) & 0xffff;
    uint32_t d1 = (be16(img + A_OVERLAY_Y) - 2) & 0xffff;
    uint32_t d7;
    uint32_t a0 = g_screen_offset_d7(img, d0, d1, &d7);
    uint32_t d2 = (img[A_TEXT_COL] + 2) & 0xffff;
    g_fun_1215e(img, a0, d2, 9, d7);
}

/* FUN_00010acc @ 0x10acc: lo mismo para el overlay B, con posición fija (0x2f, 0xc1) y
 * ancho 0x20+2. */
void g_fun_10acc(uint8_t *img) {
    uint32_t d7;
    uint32_t a0 = g_screen_offset_d7(img, (0x2f - 1) & 0xffff, (0xc1 - 2) & 0xffff, &d7);
    g_fun_1215e(img, a0, (0x20 + 2) & 0xffff, 9, d7);
}
