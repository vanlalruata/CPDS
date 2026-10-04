/* part_g q23: Function to transpose a matrix. */
#include <stdio.h>

#define N 10

void transpose(int a[][N], int r[][N], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            r[j][i] = a[i][j];
}

int main(void) {
    int rows, cols;
    printf("Enter rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2) return 1;
    int a[N][N], t[N][N];
    printf("Enter matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) if (scanf("%d", &a[i][j]) != 1) return 1;
    transpose(a, t, rows, cols);
    printf("Transpose:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) printf("%d ", t[i][j]);
        printf("\n");
    }
    return 0;
}
