/*
 * Program: q16.c
 * Uses realloc to grow an array from size 3 to size 6 and verifies that
 * the original three values are preserved across the reallocation.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = malloc(3 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("Before realloc (size 3):\n");
    for (int i = 0; i < 3; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    int *tmp = realloc(arr, 6 * sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "realloc failed\n");
        free(arr);
        return 1;
    }
    arr = tmp;

    for (int i = 3; i < 6; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("\nAfter realloc (size 6):\n");
    for (int i = 0; i < 6; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}