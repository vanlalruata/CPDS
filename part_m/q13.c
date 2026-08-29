/* part_m/q13.c
 * MATRIX MULTIPLICATION
 *
 * ALGORITHM STEPS:
 * 1. Read A (r1 x c1) and B (c1 x c2) so multiplication is valid.
 * 2. For each i,j compute C[i][j] = sum_k A[i][k]*B[k][j].
 * 3. Print result C (r1 x c2).
 *
 * TIME COMPLEXITY: O(r1 * c1 * c2) = O(n^3) for n x n matrices
 * AUXILIARY SPACE: O(r1 * c2)
 */
#include <stdio.h>

#define MAX 10

int main(void) {
    int r1, c1, c2;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};
    printf("Enter rows and cols of A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter cols of B (rows must equal %d): ", c1);
    scanf("%d", &c2);
    printf("Enter matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) scanf("%d", &A[i][j]);
    printf("Enter matrix B:\n");
    for (int i = 0; i < c1; i++)
        for (int j = 0; j < c2; j++) scanf("%d", &B[i][j]);
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
