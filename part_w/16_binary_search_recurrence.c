/* q16: Recursive binary search; T(n)=T(n/2)+c; counts comparisons. */
#include <stdio.h>

long bs_cmp;

int bsearch_rec(const int *a, int lo, int hi, int key, int *idx) {
    if (lo > hi) { *idx = -1; return 0; }
    int m = lo + (hi - lo) / 2;
    bs_cmp++;
    if (a[m] == key) { *idx = m; return 1; }
    if (a[m] < key) return bsearch_rec(a, m + 1, hi, key, idx);
    return bsearch_rec(a, lo, m - 1, key, idx);
}

int main(void) {
    int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int idx;

    bs_cmp = 0; bsearch_rec(a, 0, n - 1, 23, &idx);
    printf("Find 23:  idx=%d, comparisons=%ld\n", idx, bs_cmp);

    bs_cmp = 0; bsearch_rec(a, 0, n - 1, 2, &idx);
    printf("Find 2:   idx=%d, comparisons=%ld\n", idx, bs_cmp);

    bs_cmp = 0; bsearch_rec(a, 0, n - 1, 91, &idx);
    printf("Find 91:  idx=%d, comparisons=%ld\n", idx, bs_cmp);

    bs_cmp = 0; bsearch_rec(a, 0, n - 1, 1, &idx);
    printf("Find 1:   idx=%d, comparisons=%ld\n", idx, bs_cmp);

    printf("\nRecurrence T(n)=T(n/2)+c => Theta(log n).\n");
    return 0;
}