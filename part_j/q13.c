/* part_j / q13: Allocate an integer array using calloc().
   calloc() allocates and zeroes memory (nmemb * size). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)calloc((size_t)n, sizeof(int));
    if (!arr) return 1;
    printf("Array (all should be 0): ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
