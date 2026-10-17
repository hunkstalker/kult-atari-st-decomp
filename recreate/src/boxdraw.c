/* boxdraw.c — primitivas de dibujo de la caja de texto.
 *
 * FUN_00012ffa @ 0x12ffa: corre horizontal de D3+1 píxeles en (D0, D1) con color D2
 * (un bit por plano) sobre screen_ptr_a. El layout es de grupos de 8 bytes por 16 px
 * ([palabra plano0][plano1][plano2][plano3]); el bit dentro del grupo baja 15..0 y el
 * grupo avanza 8 bytes al desbordar. Preserva D0/D1/D6/D7.
 * FUN_00013216 @ 0x13216: la misma idea pero vertical: el bit es fijo y a0 avanza 0xa0
 * (una fila) por píxel.
 * FUN_000130a4 @ 0x130a4: copia una corre horizontal del buffer trasero (screen_ptr_b)
 * al delantero (screen_ptr_a); FUN_00013162 @ 0x13162 es la variante vertical (a += 0xa0).
 */
#include <stdint.h>

#include "machine.h"
#include "addrs.h"

uint32_t g_screen_offset_raw(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t *d7out);

void g_fun_12ffa(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3) {
    wr32(img + A_SCREEN_DRAW_BASE, 0);
    uint32_t d7;
    uint32_t a0 = g_screen_offset_raw(img, d0, d1, &d7);
    a0 -= be32(img + A_SCREEN_DRAW_BASE);
    uint32_t bit = (15 - (d7 & 0xf)) & 0xffff;
    d3 = (d3 - 1) & 0xffff;
    for (;;) {
        for (uint32_t p = 0; p < 4; p++) {
            uint32_t v = be16(img + a0 + p * 2);
            if (d2 & (1u << p))
                v |= (1u << bit);
            else
                v &= ~(1u << bit);
            wr16(img + a0 + p * 2, v & 0xffff);
        }
        if (bit != 0)
            bit = (bit - 1) & 0xffff;
        else {
            a0 += 8;
            bit = 0xf;
        }
        d3 = (d3 - 1) & 0xffff;
        if (d3 == 0xffff)
            break;
    }
}

void g_fun_13216(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3) {
    wr32(img + A_SCREEN_DRAW_BASE, 0);
    uint32_t d7;
    uint32_t a0 = g_screen_offset_raw(img, d0, d1, &d7);
    a0 -= be32(img + A_SCREEN_DRAW_BASE);
    uint32_t bit = (15 - (d7 & 0xf)) & 0xffff;
    d3 = (d3 - 1) & 0xffff;
    for (;;) {
        for (uint32_t p = 0; p < 4; p++) {
            uint32_t v = be16(img + a0 + p * 2);
            if (d2 & (1u << p))
                v |= (1u << bit);
            else
                v &= ~(1u << bit);
            wr16(img + a0 + p * 2, v & 0xffff);
        }
        a0 += 0xa0;
        d3 = (d3 - 1) & 0xffff;
        if (d3 == 0xffff)
            break;
    }
}

/* Copia el bit de color de cada plano desde screen_ptr_b a screen_ptr_a. `step` es el
 * avance de fila/pixel (8 = grupo de 16 px, 0xa0 = una fila). */
static void copy_run(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t d3,
                     uint32_t step, int wrap_bit) {
    uint32_t off = ((d0 & 0xfff0) >> 1) + (d1 & 0xffff) * 0xa0u;
    uint32_t a0 = be32(img + A_SCREEN_PTR_A) + off;
    uint32_t a1 = be32(img + A_SCREEN_PTR_B) + off;
    uint32_t bit = (15 - (d0 & 0xf)) & 0xffff;
    d3 = (d3 - 1) & 0xffff;
    for (;;) {
        for (uint32_t p = 0; p < 4; p++) {
            uint32_t v = be16(img + a0 + p * 2);
            uint32_t b = be16(img + a1 + p * 2);
            if (b & (1u << bit))
                v |= (1u << bit);
            else
                v &= ~(1u << bit);
            wr16(img + a0 + p * 2, v & 0xffff);
        }
        if (wrap_bit && bit != 0)
            bit = (bit - 1) & 0xffff;
        else {
            a0 += step;
            a1 += step;
            if (wrap_bit) bit = 0xf;
        }
        d3 = (d3 - 1) & 0xffff;
        if (d3 == 0xffff) break;
    }
}

void g_fun_130a4(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t d3) {
    copy_run(img, d0, d1, d3, 8, 1);
}

void g_fun_13162(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t d3) {
    copy_run(img, d0, d1, d3, 0xa0, 0);
}

/* Variantes con draw base fijo 0x8000: FUN_00012fee @ 0x12fee (línea H) y
 * FUN_0001320a @ 0x1320a (línea V). Igual que 0x12ffa/0x13216 pero fijan
 * $(0x1a46a) = 0x8000 antes del bucle (que resta esa base a a0). */
void g_fun_12fee(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3) {
    wr32(img + A_SCREEN_DRAW_BASE, 0x8000);
    uint32_t d7;
    uint32_t a0 = g_screen_offset_raw(img, d0, d1, &d7);
    a0 -= be32(img + A_SCREEN_DRAW_BASE);
    uint32_t bit = (15 - (d7 & 0xf)) & 0xffff;
    d3 = (d3 - 1) & 0xffff;
    for (;;) {
        for (uint32_t p = 0; p < 4; p++) {
            uint32_t v = be16(img + a0 + p * 2);
            if (d2 & (1u << p)) v |= (1u << bit); else v &= ~(1u << bit);
            wr16(img + a0 + p * 2, v & 0xffff);
        }
        if (bit != 0) bit = (bit - 1) & 0xffff;
        else { a0 += 8; bit = 0xf; }
        d3 = (d3 - 1) & 0xffff;
        if (d3 == 0xffff) break;
    }
}

void g_fun_1320a(uint8_t *img, uint32_t d0, uint32_t d1, uint32_t d2, uint32_t d3) {
    wr32(img + A_SCREEN_DRAW_BASE, 0x8000);
    uint32_t d7;
    uint32_t a0 = g_screen_offset_raw(img, d0, d1, &d7);
    a0 -= be32(img + A_SCREEN_DRAW_BASE);
    uint32_t bit = (15 - (d7 & 0xf)) & 0xffff;
    d3 = (d3 - 1) & 0xffff;
    for (;;) {
        for (uint32_t p = 0; p < 4; p++) {
            uint32_t v = be16(img + a0 + p * 2);
            if (d2 & (1u << p)) v |= (1u << bit); else v &= ~(1u << bit);
            wr16(img + a0 + p * 2, v & 0xffff);
        }
        a0 += 0xa0;
        d3 = (d3 - 1) & 0xffff;
        if (d3 == 0xffff) break;
    }
}
