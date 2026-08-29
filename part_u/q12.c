/* part_u/q12.c — Incorrect pointer declaration
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int x = 10;
 *     int *p = x;     // BUG: assigning an int value to a pointer (should be &x)
 *     printf("%d\n", *p);
 *     return 0;
 * }
 *
 * ERROR: Pointer must hold an address; p = x stores an int as an address (UB).
 * FIX: Assign the address with p = &x.
 */
#include <stdio.h>
int main(void) {
    int x = 10;
    int *p = &x;
    printf("%d\n", *p);
    return 0;
}
