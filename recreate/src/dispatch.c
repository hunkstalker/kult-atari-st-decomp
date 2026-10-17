/* dispatch.c — el despacho de comandos y la VM de bytes del script.
 *
 * run_command @ 0x103a8 / run_command_keep_sp @ 0x103ae: leen `the_command`
 * ($1a50e) y despachan por su nibble alto:
 *   0x0   -> a6 = TEMPL(0x1d402) + comando, y FUN_00010630 (VM de bytes)
 *   0xa/b -> handler de la tabla cmd_jump_table (0x19eca, 144 entradas)
 *   0x9   -> caja de texto (0x10440)  [pendiente]
 *   0xf/otro -> walk_entry(TEMPL, (cmd&0x3ff)-1), $1a4e0 = fin, FUN_00010630
 *
 * FUN_00010630 @ 0x10630: VM que lee bytes de a6 y ejecuta el handler de la tabla
 * 0x19f62 mientras el byte esté en 1..0x6a y a6 no haya llegado a $1a4e0.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "machine.h"
#include "addrs.h"

void  g_walk_entry(uint8_t *img, uint32_t a4, uint32_t d1, uint32_t *a4o, uint32_t *a5o);
void  g_fun_121c4(uint8_t *img);      /* copy_screen (byte handler 68 / cmd 105) */
void  g_fun_11014(uint8_t *img);      /* rts (byte/cmd handler) */
void  g_fun_141dc(uint8_t *img, uint32_t a6);
void  g_fun_141ea(uint8_t *img, uint32_t a6);
void  g_fun_13f4c(uint8_t *img, uint32_t a6);
void  g_fun_159d2(uint8_t *img, uint32_t a6);
void  g_fun_162ce(uint8_t *img, uint32_t a6);
void  g_fun_10440(uint8_t *img, uint32_t the_command);
void  g_clear_flag(uint8_t *img);
void  g_fun_15588(uint8_t *img);
void  g_fun_155b8(uint8_t *img);
uint32_t g_fun_104f4(uint8_t *img, uint32_t a6);
uint32_t g_fun_10668(uint8_t *img, uint32_t a6);
void  g_fun_186ee(uint8_t *img);
void  g_fun_17472(uint8_t *img);
uint32_t g_fun_11f64(uint8_t *img, uint32_t a6);
uint32_t g_fun_11f98(uint8_t *img, uint32_t a6);
uint32_t g_fun_11f02(uint8_t *img, uint32_t a6);
uint32_t g_fun_11f2e(uint8_t *img, uint32_t a6);
uint32_t g_fun_134da(uint8_t *img, uint32_t a6);
uint32_t g_fun_1042c(uint8_t *img, uint32_t a6);
uint32_t g_fun_12076(uint8_t *img, uint32_t a6);
uint32_t g_fun_12044(uint8_t *img, uint32_t a6);
uint32_t g_fun_11fd8(uint8_t *img, uint32_t a6);
uint32_t g_fun_1200a(uint8_t *img, uint32_t a6);
uint32_t g_fun_13474(uint8_t *img, uint32_t a6);
uint32_t g_fun_12e08(uint8_t *img, uint32_t a6);
uint32_t g_fun_12fea(uint8_t *img, uint32_t a6);
void     g_fun_1222e(uint8_t *img, uint32_t a6, uint32_t *a6_out);
void     g_fun_12368(uint8_t *img, uint32_t *a6);
uint32_t g_fun_121fa(uint8_t *img, uint32_t a6);
void     g_fun_1232e(uint8_t *img, uint32_t *a6);
uint32_t g_fun_1228a(uint8_t *img, uint32_t a6);
void     g_fun_1350c(uint8_t *img, uint32_t *a6);
void     g_fun_13522(uint8_t *img, uint32_t *a6);
void     g_fun_13552(uint8_t *img, uint32_t *a6);
void     g_fun_16088(uint8_t *img, uint32_t *a6);
void     g_fun_160aa(uint8_t *img, uint32_t *a6);
void     g_fun_12384(uint8_t *img, uint32_t *a6);
uint32_t g_fun_12ea2(uint8_t *img, uint32_t a6);
void     g_fun_162d8(uint8_t *img);
void     g_fun_18c8e(uint8_t *img, uint32_t *a6);
void     g_fun_18cb2(uint8_t *img, uint32_t *a6);

/* Un handler de byte de la VM (tabla 0x19f62): recibe a6 y devuelve el a6 nuevo.
 * El avance de A6 es el neto del handler original (los `addq`/push-pop), dato que
 * no modela la firma C, así que se codifica aquí. Solo los reconstruidos. */
uint32_t g_fun_14ac6(uint8_t *img, uint32_t a6);
uint32_t g_fun_14bfa(uint8_t *img, uint32_t a6);
void g_fun_17930(uint8_t *img, uint32_t a6);
uint32_t g_fun_179a2(uint8_t *img, uint32_t a6);
uint32_t g_fun_132aa(uint8_t *img, uint32_t a6);
uint32_t g_fun_132ec(uint8_t *img, uint32_t a6);
uint32_t g_fun_1332e(uint8_t *img, uint32_t a6);
uint32_t g_fun_12f28(uint8_t *img, uint32_t a6);
uint32_t g_fun_13740(uint8_t *img, uint32_t a6);
uint32_t g_fun_13702(uint8_t *img, uint32_t a6);
uint32_t g_fun_1780c(uint8_t *img, uint32_t a6);
uint32_t g_fun_1816e(uint8_t *img, uint32_t a6);
void g_fun_168a0(uint8_t *img, uint32_t a6);
uint32_t g_fun_16dec(uint8_t *img, uint32_t a6);
uint32_t g_fun_13490(uint8_t *img, uint32_t a6);
uint32_t g_fun_134b2(uint8_t *img, uint32_t a6);
uint32_t g_fun_138a6(uint8_t *img, uint32_t a6);
uint32_t g_fun_1442c(uint8_t *img, uint32_t a6);
uint32_t g_fun_1842c(uint8_t *img, uint32_t a6);
void g_fun_1687e(uint8_t *img, uint32_t a6);
uint32_t g_fun_167aa(uint8_t *img, uint32_t a6);
uint32_t g_fun_10b52(uint8_t *img, uint32_t a6);
uint32_t g_fun_1224e(uint8_t *img, uint32_t a6);
uint32_t g_fun_12240(uint8_t *img, uint32_t a6);
uint32_t g_fun_178cc(uint8_t *img, uint32_t a6);
uint32_t g_fun_17a1a(uint8_t *img, uint32_t a6);
uint32_t g_fun_17ca4(uint8_t *img, uint32_t a6);
uint32_t g_fun_176c0(uint8_t *img, uint32_t a6);
void g_fun_14602(uint8_t *img, uint32_t a6);
uint32_t g_fun_10dfa(uint8_t *img, uint32_t a6);
void g_fun_141f4(uint8_t *img, uint32_t a6);
void g_fun_14246(uint8_t *img, uint32_t a6);
uint32_t g_fun_15888(uint8_t *img, uint32_t a6);
uint32_t g_fun_12ce4(uint8_t *img, uint32_t a6);
uint32_t g_fun_13f2a(uint8_t *img, uint32_t a6);
uint32_t g_fun_1460a(uint8_t *img, uint32_t a6);
uint32_t g_fun_146d0(uint8_t *img, uint32_t a6);
uint32_t g_fun_16b9c(uint8_t *img, uint32_t a6);
uint32_t g_fun_16d78(uint8_t *img, uint32_t a6);
uint32_t g_fun_16ce2(uint8_t *img, uint32_t a6);
uint32_t g_fun_16ca6(uint8_t *img, uint32_t a6);
uint32_t g_fun_16d3c(uint8_t *img, uint32_t a6);
void g_fun_16dba(uint8_t *img);
uint32_t g_fun_18128(uint8_t *img, uint32_t a6);
uint32_t g_fun_16576(uint8_t *img, uint32_t a6);
void g_fun_10390(uint8_t *img, uint32_t a6);
uint32_t g_fun_184d6(uint8_t *img, uint32_t a6);
uint32_t g_fun_184cc(uint8_t *img, uint32_t a6);
uint32_t g_fun_1851a(uint8_t *img, uint32_t a6);
uint32_t g_fun_149da(uint8_t *img, uint32_t a6);
uint32_t g_fun_16512(uint8_t *img, uint32_t a6);
uint32_t g_fun_186b6(uint8_t *img, uint32_t a6);
uint32_t g_fun_1857a(uint8_t *img, uint32_t a6);
uint32_t g_fun_1881e(uint8_t *img, uint32_t a6);
uint32_t g_fun_18890(uint8_t *img, uint32_t a6);
uint32_t g_fun_18888(uint8_t *img, uint32_t a6);
uint32_t g_fun_16554(uint8_t *img, uint32_t a6);
uint32_t g_fun_18a98(uint8_t *img, uint32_t a6);
uint32_t g_fun_17c42(uint8_t *img, uint32_t a6);
void g_fun_168d4(uint8_t *img, uint32_t a6);
uint32_t g_fun_14ee8(uint8_t *img, uint32_t a6);
uint32_t g_fun_18cfc(uint8_t *img, uint32_t a6);
uint32_t g_fun_18d26(uint8_t *img, uint32_t a6);
uint32_t g_fun_16c48(uint8_t *img, uint32_t a6);
uint32_t g_fun_16c00(uint8_t *img, uint32_t a6);
uint32_t g_fun_18e06(uint8_t *img, uint32_t a6);
uint32_t g_fun_18f6e(uint8_t *img, uint32_t a6);
void g_fun_18fa2(uint8_t *img, uint32_t *a6);

/* Prototipos de los comandos de la tabla 0x19eca que aun no estaban declarados
 * aqui (las firmas salen de sus definiciones). */
void g_fun_14d90(uint8_t *img, uint32_t a6);
uint32_t g_fun_14e66(uint8_t *img, uint32_t a6);
void g_fun_14d76(uint8_t *img, uint32_t a6);
uint32_t g_fun_189aa(uint8_t *img, uint32_t a6);
uint32_t g_fun_15530(uint8_t *img, uint32_t a6);
uint32_t g_fun_155dc(uint8_t *img);
void g_fun_19312(uint8_t *img);
uint32_t g_fun_14f5e(uint8_t *img, uint32_t a6);
uint32_t g_fun_14f74(uint8_t *img, uint32_t a6);
uint32_t g_fun_15052(uint8_t *img, uint32_t a6);
uint32_t g_fun_150ae(uint8_t *img, uint32_t a6);
uint32_t g_fun_151b0(uint8_t *img, uint32_t a6);
uint32_t g_fun_152ee(uint8_t *img, uint32_t a6);
uint32_t g_fun_15382(uint8_t *img, uint32_t a6);
uint32_t g_fun_15428(uint8_t *img, uint32_t a6);
void g_fun_169b4(uint8_t *img);
void g_fun_16a20(uint8_t *img);
void g_fun_171b4(uint8_t *img);
uint32_t g_fun_171fa(uint8_t *img, uint32_t a6);
void g_fun_17678(uint8_t *img);
uint32_t g_fun_175f6(uint8_t *img, uint32_t a6);
void g_fun_1817a(uint8_t *img);
uint32_t g_fun_185e6(uint8_t *img, uint32_t a6);
uint32_t g_fun_1870a(uint8_t *img, uint32_t a6);
void g_fun_173ae(uint8_t *img);
uint32_t g_fun_173f2(uint8_t *img, uint32_t a6);
uint32_t g_fun_16902(uint8_t *img, uint32_t a6);
void g_fun_169ac(uint8_t *img);
void g_fun_1699c(uint8_t *img);
void g_fun_169a4(uint8_t *img);
uint32_t g_fun_15594(uint8_t *img);
uint32_t g_fun_155c4(uint8_t *img);

static uint32_t byte_handler(uint32_t b, uint8_t *img, uint32_t a6) {
    uint32_t n;
    switch (b) {
    case 5:  return g_fun_11f64(img, a6);
    case 6:  return g_fun_11f98(img, a6);
    case 7:  return g_fun_11f02(img, a6);
    case 8:  return g_fun_11f2e(img, a6);
    case 9:  return g_fun_134da(img, a6);
    case 15: g_fun_11014(img); return a6;                    /* 0x11014: rts (no avanza) */
    case 17: g_fun_141dc(img, a6); return addr_add(a6, 4);   /* 0x141dc: +1, blit, +3 */
    case 18: return g_fun_104f4(img, a6);
    case 19: g_fun_13f4c(img, a6); return addr_add(a6, 2);   /* 0x13f4c: d1=a6[1], a6+=2 */
    case 20: return g_fun_1042c(img, a6);
    case 21: return g_fun_1780c(img, a6);
    case 25: return g_fun_12076(img, a6);
    case 26: return g_fun_12044(img, a6);
    case 27: return g_fun_11fd8(img, a6);
    case 28: return g_fun_1200a(img, a6);
    case 29: return g_fun_13474(img, a6);
    case 32: return g_fun_12e08(img, a6);
    case 33: return g_fun_12fea(img, a6);
    case 35:
    case 63: g_fun_1222e(img, a6, &n); return n;
    case 36: n = a6; g_fun_12368(img, &n); return n;
    case 42: return g_fun_121fa(img, a6);
    case 43: n = a6; g_fun_1232e(img, &n); return n;
    case 46: return g_fun_1228a(img, a6);
    case 51: n = a6; g_fun_1350c(img, &n); return n;
    case 52: n = a6; g_fun_13522(img, &n); return n;
    case 53: n = a6; g_fun_13552(img, &n); return n;
    case 56: g_fun_159d2(img, a6); return addr_add(a6, 4);   /* 0x159d2: push a6+4, pop al final */
    case 59: n = a6; g_fun_16088(img, &n); return n;
    case 60: n = a6; g_fun_160aa(img, &n); return n;
    case 64: n = a6; g_fun_12384(img, &n); return n;
    case 68: g_fun_121c4(img);     return addr_add(a6, 1);   /* 0x121c4: addq.l #1,a6 + copy_screen */
    case 84: return g_fun_12ea2(img, a6);
    case 90: g_fun_162d8(img); return addr_add(a6, 1);       /* 0x162d8: addq.l #1,a6 */
    case 92: n = a6; g_fun_18c8e(img, &n); return n;
    case 93: n = a6; g_fun_18cb2(img, &n); return n;
    case 94: g_fun_162ce(img, a6); return addr_add(a6, 2);   /* 0x162ce: d0=a6[1], a6+=2 */
    case 103: return g_fun_10668(img, a6);
    case 95: g_fun_141ea(img, a6); return addr_add(a6, 4);   /* 0x141ea: +1, blit, +3 */
    /* Resto de la tabla 0x19f62 (byte b -> base + long[b-1]). Cableado completo
     * para que el arranque nativo recorra los guiones; los 48 handlers con
     * firma uint32_t devuelven su A6, y el avance de los void sale del
     * desensamblado. Los wipes devuelven el A6 real (16dbc hace addq.l #1,a6):
     * 69 -> +1 (16dbc x2 con subq -1 en medio), 70-73/102 -> +1, 101 -> +2
     * (16dbc + el addq de 16c6c). */
    case 1: return g_fun_14ac6(img, a6);
    case 2: return g_fun_14bfa(img, a6);
    case 3: g_fun_17930(img, a6); return addr_add(a6, 2);
    case 4: return g_fun_179a2(img, a6);
    case 10: return g_fun_132aa(img, a6);
    case 11: return g_fun_132ec(img, a6);
    case 12: return g_fun_1332e(img, a6);
    case 13: return g_fun_12f28(img, a6);
    case 14: return g_fun_13740(img, a6);
    case 16: return g_fun_13702(img, a6);
    case 22: return g_fun_1816e(img, a6);
    case 23: g_fun_168a0(img, a6); return addr_add(a6, 2);
    case 24: return g_fun_16dec(img, a6);
    case 30: return g_fun_13490(img, a6);
    case 31: return g_fun_134b2(img, a6);
    case 34: return g_fun_138a6(img, a6);
    case 37: return g_fun_1442c(img, a6);
    case 38: return g_fun_1842c(img, a6);
    case 39: g_fun_1687e(img, a6); return addr_add(a6, 2);
    case 40: return g_fun_167aa(img, a6);
    case 41: return g_fun_10b52(img, a6);
    case 44: return g_fun_1224e(img, a6);
    case 45: return g_fun_12240(img, a6);
    case 47: return g_fun_178cc(img, a6);
    case 48: return g_fun_17a1a(img, a6);
    case 49: return g_fun_17ca4(img, a6);
    case 50: return g_fun_176c0(img, a6);
    case 54: g_fun_14602(img, a6); return addr_add(a6, 2);
    case 55: return g_fun_10dfa(img, a6);
    case 57: g_fun_141f4(img, a6); return addr_add(a6, 2);
    case 58: g_fun_14246(img, a6); return addr_add(a6, 2);
    case 61: return g_fun_15888(img, a6);
    case 62: return g_fun_12ce4(img, a6);
    case 65: return g_fun_13f2a(img, a6);
    case 66: return g_fun_1460a(img, a6);
    case 67: return g_fun_146d0(img, a6);
    case 69: return g_fun_16b9c(img, a6);
    case 70: return g_fun_16d78(img, a6);
    case 71: return g_fun_16ce2(img, a6);
    case 72: return g_fun_16ca6(img, a6);
    case 73: return g_fun_16d3c(img, a6);
    case 74: g_fun_16dba(img); return a6;
    case 75: return g_fun_18128(img, a6);
    case 76: return g_fun_16576(img, a6);
    case 77: g_fun_10390(img, a6); return addr_add(a6, 1);
    case 78: return g_fun_184d6(img, a6);
    case 79: return g_fun_184cc(img, a6);
    case 80: return g_fun_1851a(img, a6);
    case 81: return g_fun_149da(img, a6);
    case 82: return g_fun_16512(img, a6);
    case 83: return g_fun_186b6(img, a6);
    case 85: return g_fun_1857a(img, a6);
    case 86: return g_fun_1881e(img, a6);
    case 87: return g_fun_18890(img, a6);
    case 88: return g_fun_18888(img, a6);
    case 89: return g_fun_16554(img, a6);
    case 91: return g_fun_18a98(img, a6);
    case 96: return g_fun_17c42(img, a6);
    case 97: g_fun_168d4(img, a6); return addr_add(a6, 2);
    case 98: return g_fun_14ee8(img, a6);
    case 99: return g_fun_18cfc(img, a6);
    case 100: return g_fun_18d26(img, a6);
    case 101: return g_fun_16c48(img, a6);
    case 102: return g_fun_16c00(img, a6);
    case 104: return g_fun_18e06(img, a6);
    case 105: return g_fun_18f6e(img, a6);
    case 106: n = a6; g_fun_18fa2(img, &n); return n;
    default: return a6;
    }
}

uint32_t g_fun_10630(uint8_t *img, uint32_t a6) {
    for (;;) {
        uint32_t b = img[a6];
        if (a6 == be32(img + A_SCRIPT_END)) return a6;
        if (b >= 0x6b || b == 0) return a6;
        a6 = byte_handler(b, img, a6);
    }
}

/* FUN_000104f4 @ 0x104f4 (byte 18): the_command = word inline (a6[1..2]), walk_entry
 * con (templ, cmd-1) y devuelve A5 (el nuevo stream). */
uint32_t g_fun_104f4(uint8_t *img, uint32_t a6) {
    uint32_t d1 = ((uint32_t)img[a6 + 2] << 8) | img[a6 + 1];
    wr16(img + A_THE_COMMAND, d1 & 0xffff);
    uint32_t a4o, a5o;
    g_walk_entry(img, A_TEMPL_DATA, (d1 - 1) & 0xffff, &a4o, &a5o);
    wr32(img + A_SCRIPT_END, a4o);
    return a5o;
}

/* Handler de comando de la tabla 0x19eca. Solo los reconstruidos y sin A6
 * implicito (los de la cola compartida con 0x19f62 se invocan por el VM de bytes). */
void kult_dbg_cmd(uint32_t cmd, int implemented);

static int cmd_implemented(uint32_t idx) { return idx <= 143; }  /* tabla completa */

/* Comandos 0xa000/0xb000 de la tabla 0x19eca. */
static void cmd_handler(uint8_t *img, uint32_t idx, uint32_t a6) {
    kult_dbg_cmd((idx + 1) | 0xa000, cmd_implemented(idx));
    switch (idx) {
    case 21: g_clear_flag(img); break;   /* 0x172ba */
    case 0: (void)g_fun_14d90(img, a6); break;
    case 1: (void)g_fun_14e66(img, a6); break;
    case 2: (void)g_fun_14d76(img, a6); break;
    case 3: (void)g_fun_189aa(img, a6); break;
    case 4: (void)g_fun_15530(img, a6); break;
    case 5: g_fun_15588(img); break;
    case 6: g_fun_155b8(img); break;
    case 7: g_fun_155dc(img); break;
    case 8: g_fun_19312(img); break;
    case 9: (void)g_fun_14f5e(img, a6); break;
    case 10: (void)g_fun_14f74(img, a6); break;
    case 11: (void)g_fun_15052(img, a6); break;
    case 12: (void)g_fun_150ae(img, a6); break;
    case 13: (void)g_fun_151b0(img, a6); break;
    case 14: (void)g_fun_152ee(img, a6); break;
    case 15: (void)g_fun_15382(img, a6); break;
    case 16: (void)g_fun_15428(img, a6); break;
    case 17: g_fun_169b4(img); break;
    case 18: g_fun_16a20(img); break;
    case 19: g_fun_171b4(img); break;
    case 20: (void)g_fun_171fa(img, a6); break;
    case 22: (void)g_fun_178cc(img, a6); break;
    case 23: g_fun_17678(img); break;
    case 24: (void)g_fun_175f6(img, a6); break;
    case 25: g_fun_1817a(img); break;
    case 26: (void)g_fun_185e6(img, a6); break;
    case 27: g_fun_186ee(img); break;
    case 28: (void)g_fun_1870a(img, a6); break;
    case 29: g_fun_173ae(img); break;
    case 30: (void)g_fun_173f2(img, a6); break;
    case 31: g_fun_17472(img); break;
    case 32: (void)g_fun_16902(img, a6); break;
    case 33: g_fun_169ac(img); break;
    case 34: g_fun_1699c(img); break;
    case 35: g_fun_169a4(img); break;
    case 36: g_fun_15594(img); break;
    case 37: g_fun_155c4(img); break;
    case 38: (void)g_fun_14ac6(img, a6); break;
    case 39: (void)g_fun_14bfa(img, a6); break;
    case 40: (void)g_fun_17930(img, a6); break;
    case 41: (void)g_fun_179a2(img, a6); break;
    case 42: (void)g_fun_11f64(img, a6); break;
    case 43: (void)g_fun_11f98(img, a6); break;
    case 44: (void)g_fun_11f02(img, a6); break;
    case 45: (void)g_fun_11f2e(img, a6); break;
    case 46: (void)g_fun_134da(img, a6); break;
    case 47: (void)g_fun_132aa(img, a6); break;
    case 48: (void)g_fun_132ec(img, a6); break;
    case 49: (void)g_fun_1332e(img, a6); break;
    case 50: (void)g_fun_12f28(img, a6); break;
    case 51: (void)g_fun_13740(img, a6); break;
    case 52: g_fun_11014(img); break;
    case 53: (void)g_fun_13702(img, a6); break;
    case 54: (void)g_fun_141dc(img, a6); break;
    case 55: (void)g_fun_104f4(img, a6); break;
    case 56: (void)g_fun_13f4c(img, a6); break;
    case 57: (void)g_fun_1042c(img, a6); break;
    case 58: (void)g_fun_1780c(img, a6); break;
    case 59: (void)g_fun_1816e(img, a6); break;
    case 60: (void)g_fun_168a0(img, a6); break;
    case 61: (void)g_fun_16dec(img, a6); break;
    case 62: (void)g_fun_12076(img, a6); break;
    case 63: (void)g_fun_12044(img, a6); break;
    case 64: (void)g_fun_11fd8(img, a6); break;
    case 65: (void)g_fun_1200a(img, a6); break;
    case 66: (void)g_fun_13474(img, a6); break;
    case 67: (void)g_fun_13490(img, a6); break;
    case 68: (void)g_fun_134b2(img, a6); break;
    case 69: (void)g_fun_12e08(img, a6); break;
    case 70: (void)g_fun_12fea(img, a6); break;
    case 71: (void)g_fun_138a6(img, a6); break;
    case 72: { uint32_t o; g_fun_1222e(img, a6, &o); } break;
    case 73: { uint32_t n = a6; g_fun_12368(img, &n); } break;
    case 74: (void)g_fun_1442c(img, a6); break;
    case 75: (void)g_fun_1842c(img, a6); break;
    case 76: (void)g_fun_1687e(img, a6); break;
    case 77: (void)g_fun_167aa(img, a6); break;
    case 78: (void)g_fun_10b52(img, a6); break;
    case 79: (void)g_fun_121fa(img, a6); break;
    case 80: { uint32_t n = a6; g_fun_1232e(img, &n); } break;
    case 81: (void)g_fun_1224e(img, a6); break;
    case 82: (void)g_fun_12240(img, a6); break;
    case 83: (void)g_fun_1228a(img, a6); break;
    case 84: (void)g_fun_178cc(img, a6); break;
    case 85: (void)g_fun_17a1a(img, a6); break;
    case 86: (void)g_fun_17ca4(img, a6); break;
    case 87: (void)g_fun_176c0(img, a6); break;
    case 88: { uint32_t n = a6; g_fun_1350c(img, &n); } break;
    case 89: { uint32_t n = a6; g_fun_13522(img, &n); } break;
    case 90: { uint32_t n = a6; g_fun_13552(img, &n); } break;
    case 91: (void)g_fun_14602(img, a6); break;
    case 92: (void)g_fun_10dfa(img, a6); break;
    case 93: (void)g_fun_159d2(img, a6); break;
    case 94: (void)g_fun_141f4(img, a6); break;
    case 95: (void)g_fun_14246(img, a6); break;
    case 96: { uint32_t n = a6; g_fun_16088(img, &n); } break;
    case 97: { uint32_t n = a6; g_fun_160aa(img, &n); } break;
    case 98: (void)g_fun_15888(img, a6); break;
    case 99: (void)g_fun_12ce4(img, a6); break;
    case 100: { uint32_t o; g_fun_1222e(img, a6, &o); } break;
    case 101: { uint32_t n = a6; g_fun_12384(img, &n); } break;
    case 102: (void)g_fun_13f2a(img, a6); break;
    case 103: (void)g_fun_1460a(img, a6); break;
    case 104: (void)g_fun_146d0(img, a6); break;
    case 105: g_fun_121c4(img); break;
    case 106: (void)g_fun_16b9c(img, a6); break;
    case 107: (void)g_fun_16d78(img, a6); break;
    case 108: (void)g_fun_16ce2(img, a6); break;
    case 109: (void)g_fun_16ca6(img, a6); break;
    case 110: (void)g_fun_16d3c(img, a6); break;
    case 111: g_fun_16dba(img); break;
    case 112: (void)g_fun_18128(img, a6); break;
    case 113: (void)g_fun_16576(img, a6); break;
    case 114: (void)g_fun_10390(img, a6); break;
    case 115: (void)g_fun_184d6(img, a6); break;
    case 116: (void)g_fun_184cc(img, a6); break;
    case 117: (void)g_fun_1851a(img, a6); break;
    case 118: (void)g_fun_149da(img, a6); break;
    case 119: (void)g_fun_16512(img, a6); break;
    case 120: (void)g_fun_186b6(img, a6); break;
    case 121: (void)g_fun_12ea2(img, a6); break;
    case 122: (void)g_fun_1857a(img, a6); break;
    case 123: (void)g_fun_1881e(img, a6); break;
    case 124: (void)g_fun_18890(img, a6); break;
    case 125: (void)g_fun_18888(img, a6); break;
    case 126: (void)g_fun_16554(img, a6); break;
    case 127: g_fun_162d8(img); break;
    case 128: (void)g_fun_18a98(img, a6); break;
    case 129: { uint32_t n = a6; g_fun_18c8e(img, &n); } break;
    case 130: { uint32_t n = a6; g_fun_18cb2(img, &n); } break;
    case 131: (void)g_fun_162ce(img, a6); break;
    case 132: (void)g_fun_141ea(img, a6); break;
    case 133: (void)g_fun_17c42(img, a6); break;
    case 134: (void)g_fun_168d4(img, a6); break;
    case 135: (void)g_fun_14ee8(img, a6); break;
    case 136: (void)g_fun_18cfc(img, a6); break;
    case 137: (void)g_fun_18d26(img, a6); break;
    case 138: (void)g_fun_16c48(img, a6); break;
    case 139: (void)g_fun_16c00(img, a6); break;
    case 140: (void)g_fun_10668(img, a6); break;
    case 141: (void)g_fun_18e06(img, a6); break;
    case 142: (void)g_fun_18f6e(img, a6); break;
    case 143: { uint32_t n = a6; g_fun_18fa2(img, &n); } break;
    default: break;
    }
}

/* Traza de diagnostico (KULT_DBG_CMDS=1): que comandos 0xa/b pide el guion y
 * si el port tiene handler para ellos. No altera la imagen. */
void kult_dbg_cmd(uint32_t cmd, int implemented) {
    static int on = -1;
    if (on < 0) on = getenv("KULT_DBG_CMDS") != 0;
    if (on)
        fprintf(stderr, "[cmd] %04x idx=%u %s\n", (unsigned)(cmd & 0xffff),
                (unsigned)(cmd & 0x3ff) - 1, implemented ? "ok" : "SIN HANDLER");
}

void g_run_command_keep_sp(uint8_t *img, uint32_t a6) {
    uint32_t d1 = be16(img + A_THE_COMMAND);
    if (getenv("KULT_DBG_RUN"))
        fprintf(stderr, "[run] cmd=%04x a6=%05x\n", (unsigned)d1, (unsigned)a6);
    if (d1 == 0) return;
    uint32_t d2 = d1 & 0xf000;
    if (d2 == 0x0000) {
        g_fun_10630(img, A_TEMPL_DATA + d1);
    } else if (d2 == 0xa000 || d2 == 0xb000) {
        cmd_handler(img, (d1 & 0x3ff) - 1, a6);
    } else if (d2 == 0x9000) {
        g_fun_10440(img, d1);                        /* caja de texto */
    } else {
        uint32_t a4o, a5o;
        g_walk_entry(img, A_TEMPL_DATA, (d1 & 0x3ff) - 1, &a4o, &a5o);
        wr32(img + A_SCRIPT_END, a4o);
        g_fun_10630(img, a5o);
    }
}

/* FUN_00010390 @ 0x10390: handler de byte que lee un word de a6[1..2], lo marca con el
 * nibble 0xf000 (comando de plantilla) y salta al despacho. */
void g_fun_10390(uint8_t *img, uint32_t a6) {
    uint32_t d1 = ((img[a6 + 2] << 8) | img[a6 + 1]) | 0xf000;
    wr16(img + A_THE_COMMAND, d1 & 0xffff);
    g_run_command_keep_sp(img, a6);
}

/* FUN_000186ee @ 0x186ee: reproduce la paleta 0x10, lanza el comando 0x916b (caja de
 * texto) por el despacho y restaura la paleta actual. */
void g_fun_162e2(uint8_t *img, uint32_t d0);
void g_fun_162da(uint8_t *img);
void g_fun_186ee(uint8_t *img) {
    g_fun_162e2(img, 0x10);
    wr16(img + A_THE_COMMAND, 0x916b);
    g_run_command_keep_sp(img, 0);
    g_fun_162da(img);
}
