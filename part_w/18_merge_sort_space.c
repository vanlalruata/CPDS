/* q18: Merge sort uses O(n) extra (auxiliary) space. */
#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int lo, int mid, int hi) {
    int n1 = mid - lo + 1, n2 = hi - mid;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; ++i) L[i] = a[lo + i];
    for (int j = 0; j < n2; ++j) R[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = lo;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    free(L); free(R);
}

void msort(int *a, int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        msort(a, lo, mid); msort(a, mid + 1, hi); merge(a, lo, mid, hi);
    }
}

int main(void) {
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    size_t before = sizeof(a);
    printf("Input array occupies %zu bytes.\n", before);
    printf("During merge, two temporary buffers of total size n are allocated.\n");
    printf("Auxiliary space used per merge call = O(n).\n");
    msort(a, 0, n - 1);
    printf("Sorted: "); for (int i = 0; i < n; ++i) printf("%d ", a[i]); printf("\n");
    printf("Memory note: merge sort time O(n log n), auxiliary space O(n).\n");
    return 0;
}