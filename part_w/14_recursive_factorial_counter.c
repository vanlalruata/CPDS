/* q14: Recursive factorial with operation counter. T(n) = T(n-1) + c. */
#include <stdio.h>

long fact_steps;

long factorial(int n) {
    fact_steps++;
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    int ns[] = {0, 1, 5, 10, 15, 20};
    int m = (int)(sizeof(ns) / sizeof(ns[0]));
    printf("%4s %12s %10s\n", "n", "factorial(n)", "steps");
    for (int i = 0; i < m; ++i) {
        int n = ns[i];
        fact_steps = 0;
        long v = factorial(n);
        printf("%4d %12ld %10ld\n", n, v, fact_steps);
    }
    printf("\nRecurrence T(n)=T(n-1)+c gives T(n)=Theta(n). So O(n) time.\n");
    return 0;
}