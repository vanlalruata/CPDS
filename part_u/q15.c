/* part_u/q15.c — Dangling pointer
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * int *f(void) {
 *     int x = 10;
 *     return &x;            // BUG: returns address of local variable
 * }
 * int main(void) {
 *     int *p = f();
 *     printf("%d\n", *p);  // dangling pointer (x's storage reclaimed)
 *     return 0;
 * }
 *
 * ERROR: Returning the address of a local (stack) variable yields a dangling
 *        pointer once the function returns; dereferencing it is UB.
 * FIX: Allocate with malloc (heap) so the memory persists after return.
 */
#include <stdio.h>
#include <stdlib.h>
int *f(void) {
    int *p = malloc(sizeof(int));
    *p = 10;
    return p;
}
int main(void) {
    int *p = f();
    printf("%d\n", *p);
    free(p);
    return 0;
}
