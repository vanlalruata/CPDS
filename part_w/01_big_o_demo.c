/* q1: Big-O definition and demonstration with f(n)=3n+2.
   Prints formal definition and verifies f(n) <= c*g(n)=4n for n>=2. */
#include <stdio.h>

int main(void) {
    printf("Big-O (upper bound): f(n) = O(g(n)) if there exist c>0 and n0 such that\n");
    printf("                    0 <= f(n) <= c*g(n) for all n >= n0.\n\n");

    printf("Example: f(n) = 3n + 2,  g(n) = n,  choose c = 4, n0 = 2\n");
    printf("Check f(n) <= 4n for n = 2..10:\n");
    printf("%4s %10s %10s %8s\n", "n", "f(n)=3n+2", "c*g(n)=4n", "holds?");
    for (int n = 2; n <= 10; ++n) {
        int f = 3 * n + 2;
        int cg = 4 * n;
        printf("%4d %10d %10d %8s\n", n, f, cg, (f <= cg) ? "yes" : "no");
    }
    printf("\nTherefore 3n+2 = O(n).\n");
    return 0;
}