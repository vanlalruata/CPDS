/* part_m/q20.c
 * FIND AN ELEMENT IN A SORTED ARRAY (binary search variant)
 *
 * ALGORITHM STEPS:
 * 1. Use binary search on a sorted array.
 * 2. Return index if found, else -1.
 *
 * TIME COMPLEXITY: O(log n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(a)/sizeof(a[0]);
    int key, low = 0, high = n - 1, mid, found = -1;
    printf("Enter element to find in sorted array: ");
    scanf("%d", &key);
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) { found = mid; break; }
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    printf(found != -1 ? "Found at index %d\n" : "Not found\n", found);
    return 0;
}
