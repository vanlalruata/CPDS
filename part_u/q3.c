/* part_u/q3.c — Uninitialized variable
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int sum;
 *     for (int i = 1; i <= 5; i++)
 *         sum = sum + i;   // BUG: sum is uninitialized -> UB
 *     printf("%d\n", sum);
 *     return 0;
 * }
 *
 * ERROR: 'sum' is never initialized before use; its value is indeterminate.
 * FIX: Initialize sum = 0 before accumulating.
 */
#include <stdio.h>
int main(void) {
    int sum = 0;
    for (int i = 1; i <= 5; i++)
        sum = sum + i;
    printf("%d\n", sum);
    return 0;
}
