/* part_u/q20.c — Unsafe realloc() usage (reassign without temp)
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * int main(void) {
 *     int *p = malloc(sizeof(int) * 2);
 *     p[0] = 1; p[1] = 2;
 *     p = realloc(p, sizeof(int) * 4);  // BUG: if realloc fails, p=NULL and old lost
 *     printf("%d\n", p[0]);
 *     free(p);
 *     return 0;
 * }
 *
 * ERROR: Assigning realloc directly to p leaks memory (and loses data) on failure.
 * FIX: Use a temporary pointer; only assign when realloc succeeds.
 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *p = malloc(sizeof(int) * 2);
    if (!p) return 1;
    p[0] = 1; p[1] = 2;
    int *tmp = realloc(p, sizeof(int) * 4);
    if (!tmp) { free(p); return 1; }
    p = tmp;
    printf("%d\n", p[0]);
    free(p);
    return 0;
}
