/* part_u/q11.c — Incorrect argument passing
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * void swap(int a, int b) {     // BUG: pass-by-value; changes are local
 *     int t = a; a = b; b = t;
 * }
 * int main(void) {
 *     int x = 1, y = 2;
 *     swap(x, y);
 *     printf("%d %d\n", x, y);   // still 1 2
 *     return 0;
 * }
 *
 * ERROR: C is pass-by-value; swapping copies does not affect the callers' variables.
 * FIX: Pass pointers (addresses) and dereference them inside swap.
 */
#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
int main(void) {
    int x = 1, y = 2;
    swap(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}
