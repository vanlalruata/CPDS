/* q25.c - Calculate x^n without pow() (handles non-negative n) */
#include <stdio.h>

int main(void) {
    double x, res = 1;
    int n;
    printf("Enter x and n: ");
    scanf("%lf %d", &x, &n);
    if (n < 0) { printf("Only non-negative n supported\n"); return 1; }
    for (int i = 1; i <= n; i++) res *= x;
    printf("%.2f^%d = %.2f\n", x, n, res);
    return 0;
}
