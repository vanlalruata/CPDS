/*
 * Program: q11.c
 * Demonstrates allocating a single integer with malloc, reading/printing it,
 * and properly freeing the allocation. Checks the malloc return value.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    printf("Enter an integer: ");
    if (scanf("%d", p) != 1) {
        fprintf(stderr, "Invalid input\n");
        free(p);
        return 1;
    }

    printf("You entered: %d\n", *p);

    free(p);
    p = NULL;
    return 0;
}