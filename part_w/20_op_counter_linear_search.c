/* q20: Instrumented linear search counting comparisons; best/avg/worst. */
#include <stdio.h>

long cmps;

int search(const int *a, int n, int key) {
    cmps = 0;
    for (int i = 0; i < n; ++i) {
        cmps++;
        if (a[i] == key) return i;
    }
    return -1;
}

int main(void) {
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = (int)(sizeof(a) / sizeof(a[0]));

    search(a, n, a[0]);          printf("Best (first)  -> %ld comparisons\n", cmps);
    search(a, n, a[n / 2]);      printf("Avg  (middle) -> %ld comparisons (n/2=%d)\n", cmps, n / 2);
    search(a, n, a[n - 1]);      printf("Worst (last)  -> %ld comparisons\n", cmps);
    search(a, n, 999);           printf("Worst-absent  -> %ld comparisons\n", cmps);
    return 0;
}