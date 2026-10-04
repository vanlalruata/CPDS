/*
 * Program: q14.c
 * Allocates an integer array with calloc to demonstrate zero-initialization,
 * then prints the values before freeing.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *arr = calloc((size_t)n, sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "calloc failed\n");
        return 1;
    }

    printf("calloc zero-initialized values:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}