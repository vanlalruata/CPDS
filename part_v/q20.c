/*
 * Program: q20.c
 * Demonstrates the safe pattern of calling free() and then assigning the
 * pointer to NULL so that any subsequent accidental dereference is prevented.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    *p = 42;
    printf("Before free: *p = %d\n", *p);

    free(p);
    p = NULL;

    if (p == NULL) {
        printf("After free: p is NULL (safe)\n");
    } else {
        printf("After free: *p = %d (UNSAFE - dangling)\n", *p);
    }

    return 0;
}