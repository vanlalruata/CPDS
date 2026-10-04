/* q38.c - Multiplication of two matrices.
 * Concept: A(m x n) * B(n x p) = C(m x p).  Columns of A must equal
 *          rows of B.  C[i][j] = sum over k of A[i][k] * B[k][j].
 * Compile: gcc q38.c -o q38
 */
#include <stdio.h>

#define MAXD 10

int main(void)
{
    int a[MAXD][MAXD], b[MAXD][MAXD], c[MAXD][MAXD];
    int m, n, p, q, i, j, k;

    printf("Enter rows and columns of A (1-%d each): ", MAXD);
    if (scanf("%d %d", &m, &n) != 2 || m < 1 || m > MAXD || n < 1 || n > MAXD) {
        printf("Invalid order.\n");
        return 1;
    }

    printf("Enter rows and columns of B (1-%d each): ", MAXD);
    if (scanf("%d %d", &p, &q) != 2 || p < 1 || p > MAXD || q < 1 || q > MAXD) {
        printf("Invalid order.\n");
        return 1;
    }

    if (n != p) {
        printf("Multiplication not possible: columns of A (%d) != rows of B (%d).\n", n, p);
        return 1;
    }

    printf("Enter elements of A (%d x %d):\n", m, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of B (%d x %d):\n", p, q);
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Product matrix (%d x %d):\n", m, q);
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++)
            printf("%8d", c[i][j]);
        printf("\n");
    }

    return 0;
}
