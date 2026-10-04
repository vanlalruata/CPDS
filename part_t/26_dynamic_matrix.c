/* part_t/q26.c — Dynamic Matrix (dynamic allocation m x n)
 * Operations: input, display, transpose, addition
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int m, n, i, j;
    printf("Rows and cols: "); scanf("%d %d", &m, &n);
    int (*a)[n] = malloc(m * sizeof(*a));
    int (*b)[n] = malloc(m * sizeof(*b));
    int (*t)[m] = malloc(n * sizeof(*t));
    int (*sum)[n] = malloc(m * sizeof(*sum));
    printf("Enter matrix A:\n");
    for (i = 0; i < m; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
    printf("Enter matrix B:\n");
    for (i = 0; i < m; i++) for (j = 0; j < n; j++) scanf("%d", &b[i][j]);
    for (i = 0; i < m; i++) for (j = 0; j < n; j++) { sum[i][j] = a[i][j] + b[i][j]; t[j][i] = a[i][j]; }
    printf("A+B:\n");
    for (i = 0; i < m; i++) { for (j = 0; j < n; j++) printf("%d ", sum[i][j]); printf("\n"); }
    printf("Transpose of A:\n");
    for (i = 0; i < n; i++) { for (j = 0; j < m; j++) printf("%d ", t[i][j]); printf("\n"); }
    free(a); free(b); free(t); free(sum);
    return 0;
}
