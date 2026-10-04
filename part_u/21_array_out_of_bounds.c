/* part_u/q21.c — Array out-of-bounds access
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int a[3] = {1, 2, 3};
 *     for (int i = 0; i <= 3; i++)   // BUG: i==3 is out of bounds
 *         printf("%d ", a[i]);
 *     return 0;
 * }
 *
 * ERROR: Array has indices 0..2; accessing a[3] is out-of-bounds (UB).
 * FIX: Loop while i < 3 (i <= n-1).
 */
#include <stdio.h>
int main(void) {
    int a[3] = {1, 2, 3};
    int n = 3;
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
