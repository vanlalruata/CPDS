/* q37.c - Subtraction of two matrices.
 * Concept: Same order required; C[i][j] = A[i][j] - B[i][j].
 * Compile: gcc q37.c -o q37
 */
#include <stdio.h>

#define MAXR 10
#define MAXC 10

int main(void)
{
    int a[MAXR][MAXC], b[MAXR][MAXC], c[MAXR][MAXC];
    int r, col, i, j;

    printf("Enter rows and columns (1-%d, 1-%d): ", MAXR, MAXC);
    if (scanf("%d %d", &r, &col) != 2 ||
        r < 1 || r > MAXR || col < 1 || col > MAXC) {
        printf("Invalid order.\n");
        return 1;
    }

    printf("Enter elements of matrix A (%d x %d):\n", r, col);
    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of matrix B (%d x %d):\n", r, col);
    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < col; j++)
            c[i][j] = a[i][j] - b[i][j];

    printf("Difference matrix (A - B):\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < col; j++)
            printf("%6d", c[i][j]);
        printf("\n");
    }

    return 0;
}
