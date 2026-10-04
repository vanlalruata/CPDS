/* q8: Quicksort with Lomuto partition; counts comparisons for best/avg/worst. */
#include <stdio.h>

long qs_cmp;

void swap_i(int *a, int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
}

int partition(int *a, int lo, int hi) {
    int pivot = a[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        qs_cmp++;
        if (a[j] <= pivot) {
            i++;
            swap_i(a, i, j);
        }
    }
    swap_i(a, i + 1, hi);
    return i + 1;
}

void quicksort(int *a, int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quicksort(a, lo, p - 1);
        quicksort(a, p + 1, hi);
    }
}

void run(const char *label, int *a, int n) {
    qs_cmp = 0;
    quicksort(a, 0, n - 1);
    printf("%-25s n=%d, comparisons=%ld\n", label, n, qs_cmp);
}

int main(void) {
    int best[]   = {4, 1, 3, 2, 6, 5, 7, 8};
    int avg[]    = {4, 1, 7, 3, 8, 2, 6, 5};
    int worst[]  = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("Lomuto partition quicksort comparison counts:\n");
    run("Best (balanced-ish)", best, 8);
    run("Average (random)",    avg,  8);
    run("Worst (sorted input)", worst, 8);

    printf("\nNote: With last-element pivot, already-sorted input causes O(n^2).\n");
    return 0;
}