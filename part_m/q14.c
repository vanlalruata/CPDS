/* part_m/q14.c
 * MATRIX TRANSPOSE
 *
 * ALGORITHM STEPS:
 * 1. Read an r x c matrix A.
 * 2. For each i,j set T[j][i] = A[i][j].
 * 3. Print transpose T (c x r).
 *
 * TIME COMPLEXITY: O(r * c) = O(n^2) for square matrix
 * AUXILIARY SPACE: O(r * c)
 */
#include <stdio.h>

#define MAX 10

int main(void) {
    int r, c;
    int A[MAX][MAX], T[MAX][MAX];
    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);
    printf("Enter matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &A[i][j]);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) T[j][i] = A[i][j];
    printf("Transpose:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) printf("%d ", T[i][j]);
        printf("\n");
    }
    return 0;
}
