/* part_j / q11: Sort a dynamically allocated array (bubble sort ascending). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, j, tmp;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = tmp;
            }
        }
    }
    printf("Sorted: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
