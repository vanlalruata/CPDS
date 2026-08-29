/* part_g q20: Pass a 2D array to a function and display it. */
#include <stdio.h>

#define COLS 3

void printMatrix(int mat[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main(void) {
    int rows;
    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) return 1;
    int m[100][COLS];
    printf("Enter %d x %d matrix:\n", rows, COLS);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < COLS; j++)
            if (scanf("%d", &m[i][j]) != 1) return 1;
    printf("Matrix:\n");
    printMatrix(m, rows);
    return 0;
}
