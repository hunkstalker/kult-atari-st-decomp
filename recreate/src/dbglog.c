/* dbglog.c — logger de diagnostico compartido por los cores.
 *
 * Escribe al fichero indicado por la variable de entorno KULT_FRAMES (ruta
 * absoluta o relativa al CWD). Si no esta definida, no escribe nada. Solo se
 * usa en trazas de diagnostico del motor nativo; el diferencial no la activa.
 */
#include <stdio.h>
#include <stdlib.h>

FILE *kult_dbgfile(void) {
    static FILE *f = (FILE *)-1;
    if (f == (FILE *)-1) {
        const char *p = getenv("KULT_FRAMES");
        f = (p && *p) ? fopen(p, "w") : NULL;
    }
    return f;
}
