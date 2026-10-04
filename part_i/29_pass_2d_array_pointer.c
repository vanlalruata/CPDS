/* q29.c - Pass a 2D array to a function using pointers.
 * Concept: A 2D array is stored row-major, i.e. as one flat block.
 *          Two common ways to receive it are
 *            (a) int (*m)[COLS]   - pointer to a row, and
 *            (b) int *flat        - treat it as a 1D block, using
 *                                   flat[i * cols + j].
 * Compile: gcc q29.c -o q29
 */
#include <stdio.h>

#define COLS 10
#define ROWS 10

/* (a) pointer to an array of COLS ints */
static void printMatrix(int (*m)[COLS], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%6d", m[i][j]);      /* same as *(*(m + i) + j) */
        printf("\n");
    }
}

/* (b) flat pointer view of the same memory */
static long sumMatrix(const int *flat, int rows, int cols)
{
    long sum = 0;
    int i;
    for (i = 0; i < rows * cols; i++)
        sum += flat[i];
    return sum;
}

int main(void)
{
    int m[ROWS][COLS];
    int rows, cols, i, j;

    printf("Enter rows and columns (1-%d each): ", ROWS);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > ROWS || cols < 1 || cols > COLS) {
        printf("Invalid order.\n");
        return 1;
    }

    printf("Enter %d elements row by row:\n", rows * cols);
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &m[i][j]);

    printf("\nMatrix printed through int (*m)[%d]:\n", COLS);
    printMatrix(m, rows, cols);

    /* note: valid only when the logical size equals the declared size
       for the row stride, so we sum row by row for correctness */
    {
        long total = 0;
        for (i = 0; i < rows; i++)
            total += sumMatrix(&m[i][0], 1, cols);
        printf("\nSum of all elements (flat pointer view) = %ld\n", total);
    }

    printf("Element m[0][0] via **: %d\n", **m);
    return 0;
}
