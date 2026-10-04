/* q39.c - Transpose of a matrix.
 * Concept: The transpose swaps rows and columns: T[j][i] = A[i][j].
 *          An r x c matrix becomes c x r.
 * Compile: gcc q39.c -o q39
 */
#include <stdio.h>

#define MAXR 10
#define MAXC 10

int main(void)
{
    int a[MAXR][MAXC], t[MAXC][MAXR];
    int r, c, i, j;

    printf("Enter rows and columns (1-%d, 1-%d): ", MAXR, MAXC);
    if (scanf("%d %d", &r, &c) != 2 || r < 1 || r > MAXR || c < 1 || c > MAXC) {
        printf("Invalid order.\n");
        return 1;
    }

    printf("Enter elements of the matrix (%d x %d):\n", r, c);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("Original matrix (%d x %d):\n", r, c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) printf("%6d", a[i][j]);
        printf("\n");
    }

    printf("Transpose (%d x %d):\n", c, r);
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) printf("%6d", t[i][j]);
        printf("\n");
    }

    return 0;
}
