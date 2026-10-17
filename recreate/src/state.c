/* state.c — small state helpers.
 *
 * FUN_000172ba @ 0x172ba: clear the byte pointed to by *(0x1a806) and the word at 0x1acaa.
 */
#include <stdint.h>

#include "machine.h"
#include "addrs.h"

void g_clear_flag(uint8_t *img) {
    uint32_t p = be32(img + A_PTR_1A806);
    if (p < 0x100000u)
        img[p] = 0;
    wr16(img + A_W_1ACAA, 0);
}

/* FUN_00015192 @ 0x15192: limpia el bit 7 del byte 1 de cada una de las 41 entradas de
 * 5 bytes en 0x1aa72, y el flag 0x1acd3. */
void g_fun_15192(uint8_t *img) {
    uint32_t a0 = 0x1aa72;
    for (int i = 0; i < 0x29; i++) {           /* move.w #$28,d0; dbf -> 41 iteraciones */
        img[a0 + 1] &= 0x7f;
        a0 += 5;
    }
    img[0x1acd3] = 0;
}

/* FUN_00014a98 @ 0x14a98: fija el origen de recorte ($19700/$19702) y el puntero del
 * sprite de cursor ($199ca) a partir de la tabla 0x196dc (stride 4) y 0x1949c (stride 64),
 * indexadas por D0. */
void g_fun_14a98(uint8_t *img, uint32_t a0, uint32_t d0) {
    (void)a0;
    d0 = (d0 << 2) & 0xffffffffu;
    uint32_t p = 0x196dc + d0;
    wr16(img + 0x19700, be16(img + p));
    wr16(img + 0x19702, be16(img + p + 2));
    d0 = (d0 << 4) & 0xffffffffu;
    wr32(img + 0x199ca, 0x1949c + d0);
}

/* FUN_00014bdc @ 0x14bdc: recorre 0x3f entradas de 6 bytes en 0x1a8f0 y cambia el byte
 * 0x81 por 0x80. */
void g_fun_14bdc(uint8_t *img) {
    uint32_t a0 = 0x1a8f0;
    for (int i = 0; i < 0x3f; i++) {
        if (img[a0] == 0x81)
            img[a0] = 0x80;
        a0 += 6;
    }
}
