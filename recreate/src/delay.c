/* delay.c — retardo por ciclos de CPU del original.
 *
 * Los bucles `dbf` que solo consumen tiempo (reveal pixelado, etc.) se
 * transcriben como llamadas a `g_cpu_delay(iteraciones)`. En el diferencial es
 * un no-op: lo que se compara es el resultado en imagen, no el tiempo. El build
 * nativo lo sustituye (input.c se renombra igual): acumula el retardo y cede
 * frames al frontend para que el efecto se vea paso a paso.
 */
#include <stdint.h>

void g_cpu_delay(uint32_t units) {
    (void)units;
}
