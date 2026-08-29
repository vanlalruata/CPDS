/* part_j / q12: Reverse a dynamically allocated array in place. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, tmp;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n / 2; i++) {
        tmp = arr[i]; arr[i] = arr[n - 1 - i]; arr[n - 1 - i] = tmp;
    }
    printf("Reversed: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
