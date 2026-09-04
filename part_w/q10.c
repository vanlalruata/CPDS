/* q10: Two nested loops printing i*j for i,j=1..n. Shows O(n^2) growth. */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    long ops = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ops++;
        }
    }
    printf("Total inner-loop executions = %ld (= n^2 = %d)\n", ops, n * n);
    printf("Sample i*j values (n=%d): ", n);
    int show = n < 4 ? n : 3;
    for (int i = 1; i <= show; ++i)
        for (int j = 1; j <= show; ++j)
            printf("%d ", i * j);
    printf("\nTime: O(n^2), Space: O(1).\n");
    return 0;
}