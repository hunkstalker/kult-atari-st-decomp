/* misc.c — envoltorios y entradas alternativas pequenas (varias familias).
 *
 * 0x1104a setup del blit de texto; 0x12324 GEMDOS Cnecin; 0x12fea cae en 0x1222e;
 * 0x127f0 save enmascarado + blit de texto; y entradas que solo avanzan A6 y caen
 * en su cuerpo real (0x16512->0x16514, 0x16554->0x16556, 0x16576->0x16582,
 * 0x18d26->0x18d28) o limpian globals (0x17472).
 */
#include <stdint.h>

#include "machine.h"
#include "os.h"
#include "addrs.h"

void g_text_blit_fwd(uint8_t *img, uint32_t a0, uint32_t a1, uint32_t a3,
                     uint32_t d2w, uint32_t d3w, uint32_t d7w);
void g_fun_127fa(uint8_t *img, uint32_t a0, uint32_t d2, uint32_t d3, uint32_t d7);
void g_fun_16514(uint8_t *img);
void g_fun_16556(uint8_t *img);
void g_fun_16582(uint8_t *img);
void g_fun_18d28(uint8_t *img);
void g_fun_1222e(uint8_t *img, uint32_t a6, uint32_t *a6_out);

/* FUN_0001104a @ 0x1104a: fija a3 = *(0x1a534) y cae en el blit de texto (0x11050). */
void g_fun_1104a(uint8_t *img, uint32_t a0, uint32_t a1, uint32_t d2, uint32_t d3,
                 uint32_t d7) {
    g_text_blit_fwd(img, a0, a1, be32(img + A_DAT_1A534), d2, d3, d7);
}

/* FUN_000127f0 @ 0x127f0: 0x127fa (save enmascarado) y 0x1104a (blit de texto); el
 * 0x127fa preserva D2/D3/D7/A0/A1, asi que el segundo ve los mismos argumentos. */
void g_fun_127f0(uint8_t *img, uint32_t a0, uint32_t a1, uint32_t d2, uint32_t d3,
                 uint32_t d7) {
    g_fun_127fa(img, a0, d2, d3, d7);
    g_fun_1104a(img, a0, a1, d2, d3, d7);
}

/* FUN_00012324 @ 0x12324: GEMDOS Cnecin (trap #1/$8); devuelve la tecla en D0. */
uint32_t g_fun_12324(uint8_t *img) {
    uint32_t key = 0;
    os_cnecin(img, &key);
    return key;
}

/* FUN_00012fea @ 0x12fea: cae en 0x1222e (icono A6[1]). */
uint32_t g_fun_12fea(uint8_t *img, uint32_t a6) {
    uint32_t a6o;
    g_fun_1222e(img, a6, &a6o);
    return a6o;
}

/* Avanzan A6 y caen en el cuerpo real. */
uint32_t g_fun_16512(uint8_t *img, uint32_t a6) { g_fun_16514(img); return a6 + 1; }
uint32_t g_fun_16554(uint8_t *img, uint32_t a6) { g_fun_16556(img); return a6 + 1; }
uint32_t g_fun_16576(uint8_t *img, uint32_t a6) { g_fun_16582(img); return a6 + 1; }
uint32_t g_fun_18d26(uint8_t *img, uint32_t a6) { g_fun_18d28(img); return a6 + 1; }

/* FUN_00017472 @ 0x17472: limpia 0x1aa8b y 0x1acae. */
void g_fun_17472(uint8_t *img) {
    img[0x1aa8b] = 0;
    wr16(img + 0x1acae, 0);
}
