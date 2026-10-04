/* q15: Recursive Fibonacci with global call counter; demonstrates 2^n. */
#include <stdio.h>

long long fib_calls;
long long fib_rec(int n) {
    fib_calls++;
    if (n < 2) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int main(void) {
    int ns[] = {10, 15, 20, 25, 30};
    int m = (int)(sizeof(ns) / sizeof(ns[0]));
    printf("%4s %12s %14s\n", "n", "fib(n)", "calls");
    for (int i = 0; i < m; ++i) {
        int n = ns[i];
        fib_calls = 0;
        long long v = fib_rec(n);
        printf("%4d %12lld %14lld\n", n, v, fib_calls);
    }
    printf("\nExponential growth; T(n)=2*T(n-1)+c => Theta(2^n).\n");
    return 0;
}