/* sprite.c — the sprite blitter.
 *
 * blit_sprite @ 0x124f8: draw an Amiga-format (word-planar) sprite at a descriptor.
 * Descriptor at A1: [u8 outer][u8 inner][long dest][word flags][long src_stride][src data...].
 * For each outer step / inner step it reads a source word, expands its four nibbles to four
 * bytes through the 0x55b02 scratch (the original's `movep` sequence) and merges them into the
 * destination at the four plane bytes (stride 2), masking with 0xf0f0f0f0 (or 0x0f0f0f0f when
 * flag bit2 selects the shifted half). Flag bit3 offsets the destination by one byte.
 *
 * `movep.w`/`movep.l` transfer alternate bytes: a word write puts the high byte at +0 and the
 * low byte at +2; a long write puts bytes at +0/+2/+4/+6.
 */
#include <stdint.h>

#include "machine.h"
#include "addrs.h"

static uint32_t movep_read_l(uint8_t *img, uint32_t a) {
    return ((uint32_t)img[a] << 24) | ((uint32_t)img[a + 2] << 16) |
           ((uint32_t)img[a + 4] << 8) | img[a + 6];
}
static void movep_write_l(uint8_t *img, uint32_t a, uint32_t v) {
    img[a] = (v >> 24) & 0xff;
    img[a + 2] = (v >> 16) & 0xff;
    img[a + 4] = (v >> 8) & 0xff;
    img[a + 6] = v & 0xff;
}

void g_blit_sprite(uint8_t *img, uint32_t a1) {
    if (a1 == 0)
        return;
    uint32_t outer = img[a1 + 0];
    uint32_t inner = img[a1 + 1];
    uint32_t dest = be32(img + a1 + 2);
    uint32_t flags = be16(img + a1 + 6);
    uint32_t stride = be32(img + a1 + 8);
    uint32_t src = a1 + 0xc;

    for (uint32_t c = 0; c < outer; c++) {
        uint32_t mask = 0xf0f0f0f0u;
        uint32_t shift = 0;
        uint32_t d = dest;
        if (flags & 8)
            d += 1;
        if (flags & 4) {
            mask = 0x0f0f0f0fu;
            shift = 4;
        }
        uint32_t inv = ~mask;
        uint32_t s = src;
        for (uint32_t r = 0; r < inner; r++) {
            uint16_t sw = be16(img + s);
            uint8_t oh = (sw >> 8) & 0xff, ol = sw & 0xff;
            uint16_t rot = (uint16_t)(((sw << 4) | (sw >> 12)) & 0xffff);
            uint8_t rh = (rot >> 8) & 0xff, rl = rot & 0xff;
            /* the original writes these four bytes to 0x55b02 and reads them back as a long */
            img[A_BLIT_SCRATCH + 0] = oh;
            img[A_BLIT_SCRATCH + 1] = rh;
            img[A_BLIT_SCRATCH + 2] = ol;
            img[A_BLIT_SCRATCH + 3] = rl;
            uint32_t scratch = ((uint32_t)oh << 24) | ((uint32_t)rh << 16) |
                               ((uint32_t)ol << 8) | rl;
            uint32_t rr = shift ? ((scratch >> shift) | (scratch << (32 - shift))) : scratch;
            uint32_t out = (rr & mask) | (movep_read_l(img, d) & inv);
            movep_write_l(img, d, out);
            d += 0xa0;
            s += stride;
        }
        src += 2;
        flags = (flags + 4) & 0xf;
        if (flags == 0)
            dest += 8;
    }
}

static uint32_t rol32(uint32_t v, uint32_t n) {
    n &= 31;
    return n ? ((v << n) | (v >> (32 - n))) : v;
}
static uint32_t ror16(uint32_t v, uint32_t n) {
    n &= 15;
    return n ? (((v >> n) | (v << (16 - n))) & 0xffff) : (v & 0xffff);
}

/* FUN_0001258a @ 0x1258a: save a screen rect into the descriptor at 0xd8f0.
 * In: D2 width (columns), D3 height (rows), A0 screen source, D7 pixel phase. Writes the
 * same header blit_sprite @ 0x124f8 reads ([w][h][dest][flags][stride = d2*2]) and then
 * packs each screen row into 2 bytes/row (the inverse of the blit). Returns the buffer-end
 * pointer (A4), which is also the final A1.
 *
 * The rectangle walk mirrors blit_sprite: D2 counts columns with the phase cycling every 4
 * (a0 += 8 when it wraps), D3 counts rows (a4 += stride).
 *
 * EL CUERPO VIVE EN g_fun_12590 (0x12590) porque no es privativo de 0xd8f0: 0x164a4 lo
 * invoca con el descriptor en A1 (un buffer de 0x3a556) y espera que A1 avance al fin
 * del buffer. 0x1258a solo fija A1 = 0xd8f0 y cae en el. */
uint32_t g_fun_12590(uint8_t *img, uint32_t a1, uint32_t d2, uint32_t d3, uint32_t a0,
                     uint32_t d7) {
    img[a1++] = d2 & 0xff;
    img[a1++] = d3 & 0xff;
    wr32(img + a1, a0); a1 += 4;
    wr16(img + a1, d7 & 0xffff); a1 += 2;
    uint32_t a3 = ((d2 & 0xffff) << 1);             /* d5 = d2; lsl.l #1,d5; a3 = d5 */
    wr32(img + a1, a3); a1 += 4;

    uint32_t outer = (d2 - 1) & 0xffff;
    uint32_t inner = (d3 - 1) & 0xffff;
    uint32_t a4 = a1;
    for (uint32_t o = 0; o <= outer; o++) {
        uint32_t d1 = 0xf0f0f0f0u;
        uint32_t a2 = a0;
        uint32_t d5 = 0;
        a4 = a1;
        if (d7 & 8) a2 += 1;
        if (d7 & 4) d5 = 4;
        for (uint32_t r = 0; r <= inner; r++) {
            uint32_t d0 = rol32(movep_read_l(img, a2), d5) & d1;
            wr32(img + A_BLIT_SCRATCH, d0);                       /* move.l d0,(a5) */
            uint32_t t = ((uint32_t)img[A_BLIT_SCRATCH + 1] << 8) | img[A_BLIT_SCRATCH + 3];
            t = ror16(t, 4);                                      /* movep.w 1(a5),d0; ror.w #4 */
            uint32_t d4 = ((uint32_t)img[A_BLIT_SCRATCH + 0] << 8) | img[A_BLIT_SCRATCH + 2];
            wr16(img + a4, (t | d4) & 0xffff);                    /* move.w d0,(a4) */
            a2 += 0xa0;
            a4 += a3;
        }
        a1 += 2;
        d7 = (d7 + 4) & 0xf;
        if (d7 == 0) a0 += 8;
    }
    a4 -= a3;
    a4 += 2;
    return a4;
}

uint32_t g_fun_1258a(uint8_t *img, uint32_t d2, uint32_t d3, uint32_t a0, uint32_t d7) {
    return g_fun_12590(img, A_SAVE_DESC, d2, d3, a0, d7);
}

/* FUN_000124f2 @ 0x124f2: restore the rect saved at 0xd8f0 (A1 = 0xd8f0, then drop into
 * blit_sprite @ 0x124f8). This is the inverse of g_fun_1258a. */
void g_fun_124f2(uint8_t *img) {
    g_blit_sprite(img, A_SAVE_DESC);
}

/* FUN_00012510 @ 0x12510: el bucle del blit de sprite (mismo cuerpo que blit_sprite)
 * como entrada independiente: A0 destino, A1 origen, D2 columnas, D3 filas, D7 fase,
 * A3 stride. A5 = scratch 0x55b02. */
void g_fun_12510(uint8_t *img, uint32_t a0, uint32_t a1, uint32_t d2w, uint32_t d3w,
                 uint32_t d7w, uint32_t a3) {
    uint32_t a5 = A_BLIT_SCRATCH;
    uint32_t outer = (d2w - 1) & 0xffff;
    uint32_t inner = (d3w - 1) & 0xffff;
    uint32_t d7 = d7w & 0xffff;
    for (;;) {
        uint32_t d1 = 0xf0f0f0f0u;
        uint32_t a2 = a0, a4 = a1, d5 = 0;
        if (d7 & 8) a2 += 1;
        if (d7 & 4) { d1 = (d1 >> 4) | (d1 << 28); d5 = 4; }
        uint32_t d4 = d1;
        d1 = ~d1;
        uint32_t ic = inner;
        for (;;) {
            uint32_t d6 = be16(img + a4);
            img[a5] = (d6 >> 8) & 0xff; img[a5 + 2] = d6 & 0xff;
            d6 = ((d6 << 4) | (d6 >> 12)) & 0xffff;
            img[a5 + 1] = (d6 >> 8) & 0xff; img[a5 + 3] = d6 & 0xff;
            d6 = ((uint32_t)img[a5] << 24) | ((uint32_t)img[a5 + 1] << 16) |
                 ((uint32_t)img[a5 + 2] << 8) | img[a5 + 3];
            d6 = rol32(d6, (32 - d5) & 31);          /* ror.l d5 (0 o 4) */
            d6 &= d4;
            uint32_t d0 = movep_read_l(img, a2);
            d0 &= d1;
            d0 |= d6;
            movep_write_l(img, a2, d0);
            a2 += 0xa0;
            a4 += a3;
            ic = (ic - 1) & 0xffff;
            if (ic == 0xffff) break;
        }
        a1 += 2;
        d7 = (d7 + 4) & 0xf;
        if (d7 == 0) a0 += 8;
        outer = (outer - 1) & 0xffff;
        if (outer == 0xffff) break;
    }
}

/* FUN_000124da @ 0x124da: reblitea con el stride $1a534 y espera un frame (0x13594). */
void g_fun_13594(uint8_t *img);
void g_fun_124da(uint8_t *img, uint32_t a0, uint32_t a1, uint32_t d2w, uint32_t d3w,
                 uint32_t d7w) {
    uint32_t a3 = be32(img + 0x1a534);
    g_fun_12510(img, a0, a1, d2w, d3w, d7w, a3);
    g_fun_13594(img);
}

/* FUN_000123a0 @ 0x123a0: copia D5+1 filas de (D4+1) longs desde 0xd8f0 a A0 (stride
 * 0xa0), con el origen contiguo. */
void g_fun_123a0(uint8_t *img, uint32_t a0, uint32_t d4, uint32_t d5) {
    uint32_t a2 = 0xd8f0;
    for (uint32_t ro = d5 & 0xffff;; ro = (ro - 1) & 0xffff) {
        uint32_t a3 = a0;
        for (uint32_t ci = d4 & 0xffff;; ci = (ci - 1) & 0xffff) {
            wr32(img + a3, be32(img + a2));
            a3 += 4;
            a2 += 4;
            if (ci == 0) break;
        }
        a0 += 0xa0;
        if (ro == 0) break;
    }
}
