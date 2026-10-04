/* part_j / q3: Allocate an array of integers using malloc().
   Reads n integers into a dynamically allocated array and prints them. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    printf("Enter number of integers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("You entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
