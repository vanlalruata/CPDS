/* part_u/q16.c — Memory leak
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * int main(void) {
 *     int *p = malloc(sizeof(int) * 100);
 *     p[0] = 5;
 *     printf("%d\n", p[0]);
 *     return 0;            // BUG: never free(p) -> memory leak
 * }
 *
 * ERROR: Allocated memory is not freed; the program loses the only reference.
 * FIX: Call free(p) before returning.
 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *p = malloc(sizeof(int) * 100);
    if (!p) return 1;
    p[0] = 5;
    printf("%d\n", p[0]);
    free(p);
    return 0;
}
