/* q11: Naive n x n matrix multiply with triple nested loop. O(n^3). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter n (try 50): ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int **A = malloc(n * sizeof(int *));
    int **B = malloc(n * sizeof(int *));
    int **C = calloc(n, sizeof(int *));
    for (int i = 0; i < n; ++i) {
        A[i] = malloc(n * sizeof(int));
        B[i] = malloc(n * sizeof(int));
        C[i] = calloc(n, sizeof(int));
        for (int j = 0; j < n; ++j) {
            A[i][j] = (i + j) % 10;
            B[i][j] = (i * 2 + j) % 10;
        }
    }

    long long ops = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
                ops++;
            }

    printf("Multiplications performed = %lld (expected n^3 = %d)\n", ops, n * n * n);
    printf("Sample C[0][0]=%d, C[n-1][n-1]=%d\n", C[0][0], C[n-1][n-1]);
    printf("Time: O(n^3), Space: O(n^2).\n");

    for (int i = 0; i < n; ++i) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);
    return 0;
}