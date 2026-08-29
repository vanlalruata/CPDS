/* part_j / q9: Minimum of a dynamically allocated array. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n, i, min;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    min = INT_MAX;
    for (i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    printf("Minimum = %d\n", min);
    free(arr);
    return 0;
}
