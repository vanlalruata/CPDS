/* part_u/q17.c — Double free()
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * int main(void) {
 *     int *p = malloc(sizeof(int));
 *     free(p);
 *     free(p);            // BUG: freeing already-freed memory -> UB/crash
 *     return 0;
 * }
 *
 * ERROR: Freeing the same pointer twice corrupts the heap allocator.
 * FIX: Free once, then set p = NULL to avoid accidental re-free.
 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *p = malloc(sizeof(int));
    if (!p) return 1;
    free(p);
    p = NULL;
    return 0;
}
