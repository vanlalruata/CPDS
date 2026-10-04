/*
 * Program: q17.c
 * Uses realloc to shrink an integer array from size 10 down to size 5 and
 * demonstrates that the first five elements remain accessible.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = malloc(10 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    printf("Before realloc (size 10):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *tmp = realloc(arr, 5 * sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "realloc failed\n");
        free(arr);
        return 1;
    }
    arr = tmp;

    printf("\nAfter realloc (size 5):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}