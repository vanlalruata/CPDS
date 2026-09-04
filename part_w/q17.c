/* q17: Bubble sort is in-place (O(1) extra space). Prints memory note. */
#include <stdio.h>
#include <stdlib.h>

void bubble_inplace(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main(void) {
    int a[] = {5, 1, 4, 2, 8, 0, 3};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    void *extra = malloc(1);
    printf("Auxiliary allocations before sort: %s\n", extra ? "yes (tiny bookkeeping only)" : "no");
    bubble_inplace(a, n);
    free(extra);
    printf("Sorted: "); for (int i = 0; i < n; ++i) printf("%d ", a[i]); printf("\n");
    printf("Memory note: bubble sort uses only a few scalar variables;\n");
    printf("auxiliary space = O(1). The array itself is sorted in place.\n");
    return 0;
}