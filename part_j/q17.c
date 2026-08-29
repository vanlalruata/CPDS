/* part_j / q17: Dynamically allocated matrix using calloc() (rows * cols). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c, i, j;
    printf("Enter rows and cols: ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) return 1;
    int *mat = (int *)calloc((size_t)r * (size_t)c, sizeof(int));
    if (!mat) return 1;
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i * c + j]);
    printf("Matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", mat[i * c + j]);
        printf("\n");
    }
    free(mat);
    return 0;
}
