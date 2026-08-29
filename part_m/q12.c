/* part_m/q12.c
 * MATRIX ADDITION
 *
 * ALGORITHM STEPS:
 * 1. Read dimensions r x c for two matrices A and B.
 * 2. For each i,j compute C[i][j] = A[i][j] + B[i][j].
 * 3. Print result matrix C.
 *
 * TIME COMPLEXITY: O(r * c) = O(n^2) for n x n matrices
 * AUXILIARY SPACE: O(r * c)
 */
#include <stdio.h>

#define MAX 10

int main(void) {
    int r, c;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);
    printf("Enter matrix A:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &A[i][j]);
    printf("Enter matrix B:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &B[i][j]);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) C[i][j] = A[i][j] + B[i][j];
    printf("Sum matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
