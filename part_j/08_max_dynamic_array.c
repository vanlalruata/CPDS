/* part_j / q8: Maximum of a dynamically allocated array. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n, i, max;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    max = INT_MIN;
    for (i = 0; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    printf("Maximum = %d\n", max);
    free(arr);
    return 0;
}
