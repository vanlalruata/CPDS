/* q21: Amortized analysis of dynamic array doubling (append). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n_appends;
    printf("How many appends to simulate (try 1024): ");
    if (scanf("%d", &n_appends) != 1 || n_appends <= 0) return 0;

    int cap = 1;
    int *arr = malloc(cap * sizeof(int));
    long total_copies = 0;
    int size = 0;

    for (int i = 0; i < n_appends; ++i) {
        if (size == cap) {
            cap *= 2;
            int *bigger = realloc(arr, cap * sizeof(int));
            if (!bigger) { free(arr); return 1; }
            arr = bigger;
            total_copies += size;
        }
        arr[size++] = i;
    }
    printf("Appends = %d, final capacity = %d, total element-copies = %ld\n",
           n_appends, cap, total_copies);
    double amortized = (double)total_copies / (double)n_appends;
    printf("Amortized copies per append = %.4f (<= 2, i.e., O(1))\n", amortized);
    free(arr);
    return 0;
}