/* part_g q22: Function to multiply two matrices. */
#include <stdio.h>

#define N 10

void mulMatrix(int a[][N], int b[][N], int r[][N], int row, int col, int inner) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            r[i][j] = 0;
            for (int k = 0; k < inner; k++)
                r[i][j] += a[i][k] * b[k][j];
        }
}

int main(void) {
    int r1, c1, c2;
    printf("Enter rows and cols of A (cols of A = rows of B): ");
    if (scanf("%d %d", &r1, &c1) != 2) return 1;
    printf("Enter cols of B: ");
    if (scanf("%d", &c2) != 1) return 1;
    int a[N][N], b[N][N], res[N][N];
    printf("Enter matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) if (scanf("%d", &a[i][j]) != 1) return 1;
    printf("Enter matrix B:\n");
    for (int i = 0; i < c1; i++)
        for (int j = 0; j < c2; j++) if (scanf("%d", &b[i][j]) != 1) return 1;
    mulMatrix(a, b, res, r1, c2, c1);
    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
