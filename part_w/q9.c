/* q9: Single for-loop summing 1..N. Computes sum and states complexity. */
#include <stdio.h>

int main(void) {
    int N;
    printf("Enter N: ");
    if (scanf("%d", &N) != 1 || N < 0) return 0;

    long sum = 0;
    int ops = 0;
    for (int i = 1; i <= N; ++i) {
        sum += i;
        ops++;
    }
    printf("Sum 1..%d = %ld (loop iterations = %d)\n", N, sum, ops);
    printf("Time complexity: O(n), Auxiliary space: O(1).\n");
    return 0;
}