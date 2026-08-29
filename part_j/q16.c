/* part_j / q16: Sum of an array allocated using calloc(). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, sum = 0;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)calloc((size_t)n, sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum = %d\n", sum);
    free(arr);
    return 0;
}
