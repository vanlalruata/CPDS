/* part_u/q14.c — NULL pointer dereference
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * int main(void) {
 *     int *p = NULL;        // BUG: not allocated
 *     *p = 5;               // dereferencing NULL -> crash
 *     printf("%d\n", *p);
 *     return 0;
 * }
 *
 * ERROR: Dereferencing a NULL pointer is undefined behaviour (segfault).
 * FIX: Allocate memory (malloc) before writing through the pointer.
 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *p = malloc(sizeof(int));
    if (!p) return 1;
    *p = 5;
    printf("%d\n", *p);
    free(p);
    return 0;
}
