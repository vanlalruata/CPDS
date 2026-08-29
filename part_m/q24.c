/* part_m/q24.c
 * ANALYZE NESTED LOOPS (compute i*j)
 *
 * ALGORITHM STEPS:
 * 1. Outer loop i from 0..n-1, inner loop j from 0..n-1.
 * 2. Each inner iteration does O(1) work.
 * 3. Total iterations = n * n.
 *
 * TIME COMPLEXITY: O(n^2)  (two nested loops over n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int n;
    long long total = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)          /* O(n) */
        for (int j = 0; j < n; j++)      /* O(n) inside => n*n */
            total += (long long)i * j;
    printf("Total = %lld  (nested loops => O(n^2))\n", total);
    return 0;
}
