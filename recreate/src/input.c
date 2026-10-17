/* input.c — el paquete IKBD y la espera de frame.
 *
 * FUN_00013686 @ 0x13686: copia 5 bytes de A0 (paquete IKBD) a 0x1a44f..0x1a453.
 * FUN_00013698 @ 0x13698: `wait_frame`. XBIOS Ikbdws(0x19) es no-op en el kit;
 * limpia $1a44f a 0xff y gira hasta que la interrupción del IKBD escriba el paquete.
 * Ese cambio lo modela una escritura programada (`schedule`) en el sitio del compare
 * 0x136b0, y el sondeo lo cuenta `sched_poll8` una vez por iteración (igual que la
 * VBL de 0x13594). Después copia $1a44f -> $1a456 (botones), marca clic en el bit 2
 * si el paquete pide botón 0, fija $1a570 y llama a GEMDOS Crawio(0xff) (trap #1/$6).
 */
#include <stdint.h>

#include "addrs.h"
#include "machine.h"
#include "os.h"
#include "sched.h"

void g_ikbd_handler(uint8_t *img, uint32_t a0) {
    for (int i = 0; i < 5; i++)
        img[A_IKBD_PACKET + i] = img[a0 + i];
}

void g_fun_13698(uint8_t *img) {
    img[A_IKBD_PACKET] = 0xff;                       /* move.b #$ff,$1a44f */
    /* XBIOS Ikbdws (trap #14/$19) es no-op en el kit y el oráculo no lo registra:
     * se omite (no tiene efecto sobre la imagen ni el ledger). */
    while (sched_poll8(img, A_IKBD_PACKET, 0x136b0) == 0xff)
        ;                                            /* espera el paquete del IKBD */

    img[A_INPUT_BUTTONS] = img[A_IKBD_PACKET];       /* $1a44f -> $1a456 */
    uint32_t d0 = 0;
    if (img[A_INPUT_BUTTONS] & 0x01) {               /* btst #0 */
        img[A_INPUT_BUTTONS] |= 0x04;                /* clic */
        d0 = 0xff;
    }
    img[A_SKIP_TRANSITION] = (uint8_t)d0;

    if (os_crawio(img, 0x00ff) != 0)                 /* trap #1/$6: Crawio(0xff) */
        img[A_INPUT_BUTTONS] |= 0x04;                /* hubo movimiento -> clic */
}
