/*
 * Program: q18.c
 * Dynamically allocates a 2D integer matrix (rows x cols) using an array of
 * row pointers plus individual row allocations. Reads values, displays them,
 * then frees row-by-row before freeing the row pointer array.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;
    printf("Enter rows and cols: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "Invalid dimensions\n");
        return 1;
    }

    int **mat = malloc((size_t)rows * sizeof(int *));
    if (mat == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        mat[i] = malloc((size_t)cols * sizeof(int));
        if (mat[i] == NULL) {
            fprintf(stderr, "row malloc failed\n");
            for (int k = 0; k < i; k++) free(mat[k]);
            free(mat);
            return 1;
        }
    }

    printf("Enter %d x %d integers:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &mat[i][j]) != 1) {
                fprintf(stderr, "Invalid input\n");
                for (int k = 0; k < rows; k++) free(mat[k]);
                free(mat);
                return 1;
            }
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}