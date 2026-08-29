/* part_j / q7: Sum of a dynamically allocated array. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, sum = 0;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
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
