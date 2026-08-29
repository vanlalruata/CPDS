/* part_m/q23.c
 * ANALYZE A SINGLE LOOP (sum 1..n)
 *
 * ALGORITHM STEPS:
 * 1. Loop i from 1 to n, adding i to sum.
 * 2. The loop body executes n times -> linear growth.
 *
 * TIME COMPLEXITY: O(n)  (single loop over n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int n;
    long long sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) /* executes n times -> O(n) */
        sum += i;
    printf("Sum 1..%d = %lld  (single loop => O(n))\n", n, sum);
    return 0;
}
