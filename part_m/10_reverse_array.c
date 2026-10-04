/* part_m/q10.c
 * REVERSE AN ARRAY
 *
 * ALGORITHM STEPS:
 * 1. Use two pointers lo=0, hi=n-1.
 * 2. Swap a[lo] and a[hi]; move lo++ and hi-- until they cross.
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    for (int lo = 0, hi = n - 1; lo < hi; lo++, hi--) {
        int t = a[lo]; a[lo] = a[hi]; a[hi] = t;
    }
    printf("Reversed: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
