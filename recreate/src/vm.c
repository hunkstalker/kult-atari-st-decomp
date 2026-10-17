/* vm.c — core script-VM helpers.
 *
 * FUN_00012950 @ 0x12950: skip D1 byte-length entries from A4 ([u8 len][data], len
 * includes itself), then A5 = entry+1 and A4 = entry + *entry. Reads only; the two
 * outputs are the updated A4 and A5.
 *
 * FUN_00013f56 @ 0x13f56: set 0x1a49e = D0, walk the ARPLA text table at 0x24982 to
 * the D1th entry, then run FUN_00014138 over its 3-byte entries up to the end marker.
 * FUN_00013f4c @ 0x13f4c is the entry that seeds D0 = 0 and D1 from A6[1].
 */
#include <stdint.h>

#include "machine.h"
#include "addrs.h"

void g_fun_14138(uint8_t *img, uint32_t a6);

void g_walk_entry(uint8_t *img, uint32_t a4, uint32_t d1, uint32_t *a4o, uint32_t *a5o) {
    uint32_t n = d1 & 0xffff;
    if (n != 0) {
        n = (n - 1) & 0xffff;
        do {
            a4 += img[a4];
            n = (n - 1) & 0xffff;
        } while (n != 0xffff);
    }
    *a5o = a4 + 1;
    *a4o = a4 + img[a4];
}

void g_fun_13f56(uint8_t *img, uint32_t a6, uint32_t d0, uint32_t d1) {
    (void)a6;
    wr16(img + A_DAT_1A49E, d0 & 0xffff);
    uint32_t a4o, a5o;
    g_walk_entry(img, 0x24982, (d1 - 1) & 0xffff, &a4o, &a5o);
    wr32(img + A_DAT_1A4B2, a4o);
    for (uint32_t p = a5o; p != a4o; p += 3)
        g_fun_14138(img, p);
}

void g_fun_13f4c(uint8_t *img, uint32_t a6) {
    uint32_t d1 = img[a6 + 1] & 0xff;
    g_fun_13f56(img, a6 + 2, 0, d1);
}
