/* q40.c - Check whether a square matrix is symmetric.
 * Concept: A matrix is symmetric when A == transpose(A), i.e.
 *          A[i][j] == A[j][i] for every i and j.  Only square
 *          matrices can be symmetric.
 * Compile: gcc q40.c -o q40
 */
#include <stdio.h>

#define MAXN 10

int main(void)
{
    int a[MAXN][MAXN];
    int n, i, j, symmetric = 1;

    printf("Enter order n of the square matrix (1-%d): ", MAXN);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN) {
        printf("Invalid order.\n");
        return 1;
    }

    printf("Enter elements of the matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%6d", a[i][j]);
        printf("\n");
    }

    for (i = 0; i < n && symmetric; i++)
        for (j = i + 1; j < n; j++)
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                printf("Mismatch: a[%d][%d]=%d but a[%d][%d]=%d\n",
                       i, j, a[i][j], j, i, a[j][i]);
                break;
            }

    if (symmetric)
        printf("The matrix IS symmetric.\n");
    else
        printf("The matrix is NOT symmetric.\n");

    return 0;
}
