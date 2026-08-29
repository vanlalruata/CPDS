/* part_j / q18: Increase the size of a dynamically allocated array using realloc(). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = (int *)malloc(3 * sizeof(int));
    if (!arr) return 1;
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    printf("Before realloc: %d %d %d\n", arr[0], arr[1], arr[2]);

    int *tmp = (int *)realloc(arr, 5 * sizeof(int));
    if (!tmp) { free(arr); return 1; }
    arr = tmp;
    arr[3] = 4; arr[4] = 5;
    printf("After realloc (grow): %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    free(arr);
    return 0;
}
