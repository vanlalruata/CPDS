/* q19: Growth-rates table for log2(n), n, n log2(n), n^2, 2^n. */
#include <stdio.h>
#include <math.h>

int main(void) {
    int ns[] = {10, 20, 30, 40};
    int m = (int)(sizeof(ns) / sizeof(ns[0]));
    printf("%6s %12s %12s %16s %16s %20s\n",
           "n", "log2(n)", "n", "n*log2(n)", "n^2", "2^n");
    for (int i = 0; i < m; ++i) {
        int n = ns[i];
        double lg = log2((double)n);
        double nl = n * lg;
        double n2 = (double)n * n;
        double two_n = pow(2.0, (double)n);
        printf("%6d %12.4f %12d %16.4f %16.0f %20.3e\n",
               n, lg, n, nl, n2, two_n);
    }
    printf("\nNote 2^n explodes: at n=40 it is over 1 trillion.\n");
    return 0;
}