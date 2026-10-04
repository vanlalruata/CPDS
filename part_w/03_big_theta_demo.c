/* q3: Big-Theta (tight bound) definition and demonstration with f(n)=3n+2.
   Shows c1*n <= 3n+2 <= c2*n with c1=3, c2=4. */
#include <stdio.h>

int main(void) {
    printf("Big-Theta (tight bound): f(n) = Theta(g(n)) if there exist c1>0, c2>0, n0\n");
    printf("                       such that c1*g(n) <= f(n) <= c2*g(n) for all n>=n0.\n\n");

    printf("Example: f(n) = 3n + 2,  g(n) = n,  choose c1 = 3, c2 = 4, n0 = 2\n");
    printf("%4s %10s %10s %10s\n", "n", "c1*n=3n", "f(n)=3n+2", "c2*n=4n");
    for (int n = 2; n <= 10; ++n) {
        int c1n = 3 * n;
        int f = 3 * n + 2;
        int c2n = 4 * n;
        printf("%4d %10d %10d %10d\n", n, c1n, f, c2n);
    }
    printf("\nBoth bounds hold, so 3n+2 = Theta(n).\n");
    return 0;
}