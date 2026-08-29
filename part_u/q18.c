/* part_u/q18.c — Incorrect malloc() size calculation
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * int main(void) {
 *     int n = 5;
 *     int *p = malloc(n);   // BUG: n bytes, not n*sizeof(int); too small
 *     for (int i = 0; i < n; i++) p[i] = i;
 *     printf("%d\n", p[n-1]);
 *     free(p);
 *     return 0;
 * }
 *
 * ERROR: malloc(n) allocates n bytes, but an int array of n needs n*sizeof(int).
 * FIX: Allocate n * sizeof(int).
 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n = 5;
    int *p = malloc(n * sizeof(int));
    if (!p) return 1;
    for (int i = 0; i < n; i++) p[i] = i;
    printf("%d\n", p[n-1]);
    free(p);
    return 0;
}
