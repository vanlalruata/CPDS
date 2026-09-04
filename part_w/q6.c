/* q6: Bubble sort counts of comparisons and swaps for best/avg/worst. */
#include <stdio.h>
#include <stdlib.h>

void bubble(int *a, int n, long *cmp, long *swp) {
    *cmp = *swp = 0;
    for (int i = 0; i < n - 1; ++i) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; ++j) {
            (*cmp)++;
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                (*swp)++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void print_arr(const int *a, int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int sorted[]   = {1, 2, 3, 4, 5, 6, 7, 8};
    int average[]  = {4, 1, 7, 3, 8, 2, 6, 5};
    int reverse[]  = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = 8;
    long cmp, swp;

    bubble(sorted, n, &cmp, &swp);
    printf("Best (sorted):    cmp=%ld, swp=%ld\n", cmp, swp);

    bubble(average, n, &cmp, &swp);
    printf("Average:          cmp=%ld, swp=%ld\n", cmp, swp);

    bubble(reverse, n, &cmp, &swp);
    printf("Worst (reversed): cmp=%ld, swp=%ld\n", cmp, swp);

    printf("\nBest O(n) with early exit, Avg/Worst O(n^2).\n");
    return 0;
}