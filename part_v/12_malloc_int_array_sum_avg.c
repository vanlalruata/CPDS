/*
 * Program: q12.c
 * Allocates an integer array with malloc, reads N elements, computes the
 * sum and average, then frees the array.
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

    int *arr = malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    long long sum = 0;
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return 1;
        }
        sum += arr[i];
    }

    double avg = (double)sum / n;
    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", avg);

    free(arr);
    return 0;
}