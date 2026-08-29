/* part_j / q6: Input and display a dynamically allocated array. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    printf("Enter size: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) return 1;
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array contents:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}
