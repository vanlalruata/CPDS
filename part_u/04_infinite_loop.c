/* part_u/q4.c — Infinite loop
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int i = 0;
 *     while (i < 5) {           // BUG: i is never incremented
 *         printf("%d ", i);
 *     }
 *     return 0;
 * }
 *
 * ERROR: Loop body never changes the condition; 'i' stays 0 forever.
 * FIX: Increment i inside the loop.
 */
#include <stdio.h>
int main(void) {
    int i = 0;
    while (i < 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
    return 0;
}
