/* cursor.c — the cursor save-buffer restore.
 *
 * FUN_0001060a @ 0x1060a: copy 16 rows of 4 longs (16 bytes) from the saved buffer at 0x99ce
 * to *(0x9ace), the destination advancing 0xa0 bytes per row (the source 0x10). Pure: the whole
 * effect is the image.
 */
#include <stdint.h>

#include "machine.h"
#include "addrs.h"

static uint32_t ror32(uint32_t v, uint32_t n) {
    n &= 31;
    return n ? ((v >> n) | (v << (32 - n))) : v;
}

/* FUN_00010526 @ 0x10526: save the 16x16 area under the cursor and draw the cursor
 * sprite. Cursor/origin globals; screen_address WITHOUT the `lsl.w #2` (0x10fee). The
 * 4th word of each half is OR-ed only when 0x1a48a is nonzero. */
void g_draw_cursor(uint8_t *img) {
    uint32_t sprite = be32(img + A_CURSOR_SPRITE_PTR);
    uint32_t a2 = A_CURSOR_SAVE_BUF + 8;
    uint16_t cx = be16(img + A_CURSOR_X), clx = be16(img + A_CLIP_X);
    uint16_t cy = be16(img + A_CURSOR_Y), cly = be16(img + A_CLIP_Y);
    uint16_t d0 = (cx >= clx) ? (uint16_t)(cx - clx) : 0;
    uint16_t d1 = (cy >= cly) ? (uint16_t)(cy - cly) : 0;
    uint32_t d7 = d0 & 0xf;
    uint32_t a0 = be32(img + A_SCREEN_PTR_A) + ((d0 & 0xfff0) >> 1) + (uint32_t)d1 * 0xa0u;
    wr32(img + A_CURSOR_SAVE_DEST, a0);
    a0 += 8;
    uint32_t src = sprite;
    for (int row = 0; row < 16; row++) {
        uint16_t w1 = be16(img + src); src += 2;
        uint16_t w2 = be16(img + src); src += 2;
        uint32_t m1 = ror32(((uint32_t)w1 << 16) | 0xffffu, d7);
        uint32_t m2 = ror32((uint32_t)w2 << 16, d7);
        for (int half = 0; half < 2; half++) {
            for (int i = 0; i < 4; i++) {
                uint32_t off = half ? (uint32_t)i * 2 - 8 : (uint32_t)i * 2;
                uint32_t ad = a0 + off, sd = a2 + off;
                uint16_t v = be16(img + ad);
                wr16(img + sd, v);
                v = (uint16_t)(v & (m1 & 0xffff));
                if (!(i == 3 && img[A_CURSOR_HOTSPOT] == 0))
                    v = (uint16_t)(v | (m2 & 0xffff));
                wr16(img + ad, v);
            }
            m1 = (m1 << 16) | (m1 >> 16);
            m2 = (m2 << 16) | (m2 >> 16);
        }
        a0 += 0xa0;
        a2 += 0x10;
    }
}

void g_restore_cursor(uint8_t *img) {
    uint32_t a0 = be32(img + A_CURSOR_SAVE_DEST);
    uint32_t a1 = A_CURSOR_SAVE_BUF;
    for (int row = 0; row < 16; row++) {
        for (int i = 0; i < 4; i++) {
            wr32(img + a0, be32(img + a1));
            a0 += 4;
            a1 += 4;
        }
        a0 += 0x90;
    }
}
