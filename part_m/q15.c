/* part_m/q15.c
 * FACTORIAL USING ITERATION
 *
 * ALGORITHM STEPS:
 * 1. Initialize result = 1.
 * 2. Loop i from 1 to n, multiplying result *= i.
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int n;
    unsigned long long fact = 1;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) fact *= i;
    printf("%d! = %llu\n", n, fact);
    return 0;
}
