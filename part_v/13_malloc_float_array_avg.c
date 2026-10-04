/*
 * Program: q13.c
 * Allocates a float array with malloc, reads N floating-point values, computes
 * the average, then frees the array.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    float *arr = malloc((size_t)n * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    double sum = 0.0;
    printf("Enter %d floats:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%f", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return 1;
        }
        sum += arr[i];
    }

    printf("Average = %.4f\n", sum / n);

    free(arr);
    return 0;
}