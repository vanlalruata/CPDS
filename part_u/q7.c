/* part_u/q7.c — Incorrect use of continue
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int i = 0;
 *     while (i < 5) {
 *         if (i % 2 == 0)
 *             continue;     // BUG: skips i++ so loop never advances -> infinite
 *         printf("%d ", i);
 *         i++;
 *     }
 *     return 0;
 * }
 *
 * ERROR: 'continue' jumps to loop test before i++ executes, causing an infinite loop.
 * FIX: Increment the counter before continue (or use a for loop).
 */
#include <stdio.h>
int main(void) {
    int i = 0;
    while (i < 5) {
        i++;
        if ((i - 1) % 2 == 0) continue;
        printf("%d ", i - 1);
    }
    printf("\n");
    return 0;
}
