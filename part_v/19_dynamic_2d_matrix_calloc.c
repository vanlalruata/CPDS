/*
 * Program: q19.c
 * Dynamically allocates a 2D matrix with calloc, reads values, displays the
 * matrix, computes and prints its transpose, then frees the memory.
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

    int **mat = calloc((size_t)rows, sizeof(int *));
    if (mat == NULL) {
        fprintf(stderr, "calloc failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        mat[i] = calloc((size_t)cols, sizeof(int));
        if (mat[i] == NULL) {
            fprintf(stderr, "row calloc failed\n");
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

    printf("\nOriginal matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose:\n");
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
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