/*
 * Program: q15.c
 * Experimental comparison of malloc (uninitialized garbage) vs calloc
 * (zero-initialized memory) for an integer array of the same size.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter size of array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *m = malloc((size_t)n * sizeof(int));
    int *c = calloc((size_t)n, sizeof(int));
    if (m == NULL || c == NULL) {
        fprintf(stderr, "allocation failed\n");
        free(m);
        free(c);
        return 1;
    }

    printf("\n--- malloc (uninitialized) values ---\n");
    for (int i = 0; i < n; i++) {
        printf("m[%d] = %d\n", i, m[i]);
    }

    printf("\n--- calloc (zeroed) values ---\n");
    for (int i = 0; i < n; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    free(m);
    free(c);
    return 0;
}