/* part_m/q16.c
 * FACTORIAL USING RECURSION
 *
 * ALGORITHM STEPS:
 * 1. fact(n) = n * fact(n-1) with base case fact(0)=1.
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(n)  (recursion call stack depth)
 */
#include <stdio.h>

unsigned long long fact(int n) {
    if (n == 0) return 1;
    return (unsigned long long)n * fact(n - 1);
}

int main(void) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d! = %llu\n", n, fact(n));
    return 0;
}
