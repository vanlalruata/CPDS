/* part_m/q8.c
 * SELECTION SORT
 *
 * ALGORITHM STEPS:
 * 1. For each position i from 0 to n-2:
 * 2.   Find index min_idx of smallest element in a[i..n-1].
 * 3.   Swap a[i] with a[min_idx].
 *
 * TIME COMPLEXITY: O(n^2)  (all cases)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx]) min_idx = j;
        int t = a[i]; a[i] = a[min_idx]; a[min_idx] = t;
    }
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
