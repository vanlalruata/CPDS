/* q4: Linear search best/average/worst case comparison counts.
   Runs on a sample array and prints counts. */
#include <stdio.h>

long comparisons;

int linear_search(const int *a, int n, int key, int *found_index) {
    comparisons = 0;
    for (int i = 0; i < n; ++i) {
        comparisons++;
        if (a[i] == key) {
            *found_index = i;
            return 1;
        }
    }
    *found_index = -1;
    return 0;
}

int main(void) {
    int a[] = {11, 22, 33, 44, 55, 66, 77};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int idx;

    printf("Array: ");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n\n");

    linear_search(a, n, 11, &idx);
    printf("Best case (first element): %ld comparisons\n", comparisons);

    linear_search(a, n, 44, &idx);
    printf("Average case (middle):     %ld comparisons (n/2 = %d)\n", comparisons, n / 2);

    linear_search(a, n, 77, &idx);
    printf("Worst-present (last):      %ld comparisons\n", comparisons);

    linear_search(a, n, 99, &idx);
    printf("Worst-absent (not found):  %ld comparisons\n", comparisons);

    printf("\nGeneral: best=1, avg=n/2, worst=n.\n");
    return 0;
}