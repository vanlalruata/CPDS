/* part_v/q6.c — Matrix addition */
#include <stdio.h>

int main(void) {
    int r, c, i, j;
    printf("Rows and cols: ");
    scanf("%d %d", &r, &c);
    int a[50][50], b[50][50], sum[50][50];
    printf("Enter matrix A:\n");
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) scanf("%d", &a[i][j]);
    printf("Enter matrix B:\n");
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) scanf("%d", &b[i][j]);
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) sum[i][j] = a[i][j] + b[i][j];
    printf("Sum:\n");
    for (i = 0; i < r; i++) { for (j = 0; j < c; j++) printf("%d ", sum[i][j]); printf("\n"); }
    return 0;
}
