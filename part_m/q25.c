/* part_m/q25.c
 * ANALYZE THREE NESTED LOOPS
 *
 * ALGORITHM STEPS:
 * 1. Three loops i, j, k each from 0..n-1.
 * 2. Inner body executes n * n * n times.
 *
 * TIME COMPLEXITY: O(n^3)  (three nested loops over n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int n;
    long long count = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)              /* O(n) */
        for (int j = 0; j < n; j++)          /* O(n) */
            for (int k = 0; k < n; k++)      /* O(n) => n^3 */
                count++;
    printf("Count = %lld  (three nested loops => O(n^3))\n", count);
    return 0;
}
