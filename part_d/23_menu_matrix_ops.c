/* q23.c - Menu-driven matrix operations (add, multiply, transpose)
   Fixed 2x2 matrices for simplicity. */
#include <stdio.h>

int main(void) {
    int choice, i, j, k;
    int a[2][2], b[2][2], c[2][2];
    printf("Enter first 2x2 matrix:\n");
    for (i = 0; i < 2; i++) for (j = 0; j < 2; j++) scanf("%d", &a[i][j]);
    printf("Enter second 2x2 matrix:\n");
    for (i = 0; i < 2; i++) for (j = 0; j < 2; j++) scanf("%d", &b[i][j]);
    do {
        printf("\n1. Add\n2. Multiply\n3. Transpose(A)\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                for (i = 0; i < 2; i++) for (j = 0; j < 2; j++) c[i][j] = a[i][j] + b[i][j];
                break;
            case 2:
                for (i = 0; i < 2; i++) for (j = 0; j < 2; j++) {
                    c[i][j] = 0;
                    for (k = 0; k < 2; k++) c[i][j] += a[i][k] * b[k][j];
                }
                break;
            case 3:
                for (i = 0; i < 2; i++) for (j = 0; j < 2; j++) c[i][j] = a[j][i];
                break;
            case 4: break;
            default: printf("Invalid\n");
        }
        if (choice >= 1 && choice <= 3) {
            printf("Result:\n");
            for (i = 0; i < 2; i++) { for (j = 0; j < 2; j++) printf("%d ", c[i][j]); printf("\n"); }
        }
    } while (choice != 4);
    return 0;
}
