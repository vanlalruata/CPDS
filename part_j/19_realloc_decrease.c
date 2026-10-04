/* part_j / q19: Decrease the size of a dynamically allocated array using realloc(). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    int *arr = (int *)malloc(5 * sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < 5; i++) arr[i] = i + 1;
    printf("Before: ");
    for (i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    int *tmp = (int *)realloc(arr, 2 * sizeof(int));
    if (!tmp) { free(arr); return 1; }
    arr = tmp;
    printf("After shrink: ");
    for (i = 0; i < 2; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
