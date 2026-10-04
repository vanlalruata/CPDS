/* part_m/q18.c
 * FIBONACCI USING RECURSION
 *
 * ALGORITHM STEPS:
 * 1. fib(n) = fib(n-1) + fib(n-2), base cases fib(0)=0, fib(1)=1.
 * NOTE: naive recursion is exponential; shown for teaching only.
 *
 * TIME COMPLEXITY: O(2^n)  (exponential, very inefficient)
 * AUXILIARY SPACE: O(n)  (call stack depth)
 */
#include <stdio.h>

long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("fib(%d) = %lld\n", n, fib(n));
    return 0;
}
