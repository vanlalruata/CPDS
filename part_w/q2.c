/* q2: Big-Omega (lower bound) definition and demonstration with f(n)=3n+2.
   Shows f(n) >= c*g(n) = 2n for all n >= 0. */
#include <stdio.h>

int main(void) {
    printf("Big-Omega (lower bound): f(n) = Omega(g(n)) if there exist c>0 and n0\n");
    printf("                        such that 0 <= c*g(n) <= f(n) for all n >= n0.\n\n");

    printf("Example: f(n) = 3n + 2,  g(n) = n,  choose c = 2, n0 = 0\n");
    printf("Check 2n <= 3n+2 for n = 0..10:\n");
    printf("%4s %10s %10s %8s\n", "n", "c*g(n)=2n", "f(n)=3n+2", "holds?");
    for (int n = 0; n <= 10; ++n) {
        int cg = 2 * n;
        int f = 3 * n + 2;
        printf("%4d %10d %10d %8s\n", n, cg, f, (cg <= f) ? "yes" : "no");
    }
    printf("\nTherefore 3n+2 = Omega(n).\n");
    return 0;
}