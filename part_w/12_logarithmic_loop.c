/* q12: Loop while(n>0){cnt++; n/=2;} Counts iterations; states O(log n). */
#include <stdio.h>
#include <math.h>

int log_count(long n) {
    int cnt = 0;
    while (n > 0) { cnt++; n /= 2; }
    return cnt;
}

int main(void) {
    long tests[] = {1, 2, 3, 10, 100, 1000, 1000000L, 1000000000L};
    int m = (int)(sizeof(tests) / sizeof(tests[0]));
    printf("%12s %8s %10s\n", "n", "count", "log2(n)~");
    for (int i = 0; i < m; ++i) {
        long n = tests[i];
        int c = log_count(n);
        printf("%12ld %8d %10.2f\n", n, c, log2((double)n));
    }
    printf("\nTime complexity: O(log n).\n");
    return 0;
}