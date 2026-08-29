/* part_m/q21.c
 * COMPARE LINEAR AND BINARY SEARCH (print comparison counts)
 *
 * ALGORITHM STEPS:
 * 1. Build a sorted array.
 * 2. Run linear search counting each element comparison.
 * 3. Run binary search counting each midpoint comparison.
 * 4. Print both counts.
 *
 * LINEAR  SEARCH TIME COMPLEXITY: O(n)
 * BINARY  SEARCH TIME COMPLEXITY: O(log n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(a)/sizeof(a[0]);
    int key = 13;
    int lin_cmp = 0, bin_cmp = 0, found = -1;

    /* linear search */
    for (int i = 0; i < n; i++) {
        lin_cmp++;
        if (a[i] == key) { found = i; break; }
    }

    /* binary search */
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        bin_cmp++;
        if (a[mid] == key) { found = mid; break; }
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    printf("Searching for %d (found at index %d)\n", key, found);
    printf("Linear search comparisons : %d\n", lin_cmp);
    printf("Binary search comparisons : %d\n", bin_cmp);
    return 0;
}
