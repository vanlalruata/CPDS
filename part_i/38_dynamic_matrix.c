/* q38.c - Dynamically create a matrix using int ** and malloc.
 * Concept: Allocate an array of row pointers, then allocate each row.
 *          m[i][j] then works normally.  Free the rows first, then the
 *          array of pointers (reverse order of allocation).
 * Compile: gcc q38.c -o q38
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **m;
    int rows, cols, i, j;
    long sum = 0;

    printf("Enter rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 1 || cols < 1) {
        printf("Invalid order.\n");
        return 1;
    }

    /* step 1: array of row pointers */
    m = (int **) malloc((size_t) rows * sizeof(int *));
    if (m == NULL) { printf("Allocation failed.\n"); return 1; }

    /* step 2: each row */
    for (i = 0; i < rows; i++) {
        m[i] = (int *) malloc((size_t) cols * sizeof(int));
        if (m[i] == NULL) {
            printf("Allocation failed for row %d.\n", i);
            for (j = 0; j < i; j++) free(m[j]);
            free(m);
            return 1;
        }
    }

    printf("Enter %d elements row by row:\n", rows * cols);
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &m[i][j]);

    printf("\nThe matrix (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%6d", m[i][j]);
            sum += m[i][j];
        }
        printf("\n");
    }
    printf("Sum of all elements = %ld\n", sum);

    /* row sums using pointer notation */
    printf("\nRow sums (using *(*(m + i) + j)):\n");
    for (i = 0; i < rows; i++) {
        long rs = 0;
        for (j = 0; j < cols; j++) rs += *(*(m + i) + j);
        printf("Row %d = %ld\n", i, rs);
    }

    /* step 3: free in reverse order */
    for (i = 0; i < rows; i++) free(m[i]);
    free(m);
    printf("\nAll dynamic memory released.\n");

    return 0;
}
