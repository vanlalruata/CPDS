/* part_j / q4: Allocate an array of floats using malloc(). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    printf("Enter number of floats: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }
    float *arr = (float *)malloc((size_t)n * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d floats:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    printf("You entered: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
