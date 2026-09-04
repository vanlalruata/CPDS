/* q5: Binary search best/avg/worst comparison counts on sample inputs. */
#include <stdio.h>

long bscmp;

int binary_search(const int *a, int n, int key, int *found_index) {
    int l = 0, r = n - 1;
    bscmp = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        bscmp++;
        if (a[m] == key) { *found_index = m; return 1; }
        if (a[m] < key) l = m + 1; else r = m - 1;
    }
    *found_index = -1;
    return 0;
}

int main(void) {
    int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int idx;

    printf("Sorted array of size %d. Best=1, Avg~log2(n), Worst~floor(log2(n))+1.\n\n", n);

    binary_search(a, n, a[0], &idx);
    printf("First element (best):  index=%d, comparisons=%ld\n", idx, bscmp);

    binary_search(a, n, a[n / 2], &idx);
    printf("Middle element (best): index=%d, comparisons=%ld\n", idx, bscmp);

    binary_search(a, n, a[n - 1], &idx);
    printf("Last element:          index=%d, comparisons=%ld\n", idx, bscmp);

    binary_search(a, n, 99, &idx);
    printf("Not found (worst):     index=%d, comparisons=%ld\n", idx, bscmp);

    return 0;
}