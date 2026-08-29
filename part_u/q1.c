/* part_u/q1.c — Off-by-one error in an array loop
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * int main(void) {
 *     int a[5] = {1,2,3,4,5};
 *     int n = 5;
 *     for (int i = 0; i <= n; i++)   // BUG: i<=n goes one past the end
 *         printf("%d ", a[i]);
 *     return 0;
 * }
 *
 * ERROR: Loop condition uses i <= n, causing an out-of-bounds read (UB).
 * FIX: Use i < n so index stays within 0..4.
 */
#include <stdio.h>
int main(void) {
    int a[5] = {1,2,3,4,5};
    int n = 5;
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
