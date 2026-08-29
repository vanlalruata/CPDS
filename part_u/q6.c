/* part_u/q6.c — Incorrect use of break
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     for (int i = 0; i < 5; i++) {
 *         if (i == 2)
 *             break;        // BUG: intended to skip i==2, but break exits loop
 *         printf("%d ", i);
 *     }
 *     return 0;
 * }
 * (Expected output: 0 1 3 4)
 *
 * ERROR: 'break' terminates the whole loop; to skip one iteration use 'continue'.
 * FIX: Replace break with continue for the skip behaviour.
 */
#include <stdio.h>
int main(void) {
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
