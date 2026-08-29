/* part_g q21: Function to add two matrices. */
#include <stdio.h>

#define N 10

void addMatrix(int a[][N], int b[][N], int r[][N], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            r[i][j] = a[i][j] + b[i][j];
}

int main(void) {
    int rows, cols;
    printf("Enter rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2) return 1;
    int a[N][N], b[N][N], res[N][N];
    printf("Enter first matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) if (scanf("%d", &a[i][j]) != 1) return 1;
    printf("Enter second matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) if (scanf("%d", &b[i][j]) != 1) return 1;
    addMatrix(a, b, res, rows, cols);
    printf("Sum matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
