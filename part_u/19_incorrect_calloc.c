/* part_u/q19.c — Incorrect calloc() usage
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * int main(void) {
 *     int *p = calloc(5, 1);   // BUG: 5 elements of 1 byte, not sizeof(int)
 *     for (int i = 0; i < 5; i++) p[i] = i * 100;
 *     printf("%d\n", p[4]);
 *     free(p);
 *     return 0;
 * }
 *
 * ERROR: calloc(count, size) — second argument must be sizeof(int), not 1.
 * FIX: calloc(5, sizeof(int)).
 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *p = calloc(5, sizeof(int));
    if (!p) return 1;
    for (int i = 0; i < 5; i++) p[i] = i * 100;
    printf("%d\n", p[4]);
    free(p);
    return 0;
}
