/* part_u/q13.c — Incorrect dereferencing
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int x = 10, y = 20;
 *     int *p = &x;
 *     p = &y;          // BUG: assigns to p instead of *p
 *     printf("%d\n", x);   // x stays 10, not 20
 *     return 0;
 * }
 * (Intent: set x to y's value via pointer)
 *
 * ERROR: Writing "p = &y" reassigns the pointer rather than changing x. To modify
 *        the pointed-to value you must dereference: *p = y.
 * FIX: Use *p = y to store through the pointer.
 */
#include <stdio.h>
int main(void) {
    int x = 10, y = 20;
    int *p = &x;
    *p = y;
    printf("%d\n", x);
    return 0;
}
