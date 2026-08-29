/* part_m/q2.c
 * BINARY SEARCH (on sorted array)
 *
 * ALGORITHM STEPS:
 * 1. Set low=0, high=n-1.
 * 2. While low <= high, compute mid = (low+high)/2.
 * 3. If a[mid]==key return mid; if a[mid]<key set low=mid+1; else high=mid-1.
 * 4. If loop ends, key is absent -> return -1.
 *
 * TIME COMPLEXITY: O(log n)  (worst/average; O(1) best at mid)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(a)/sizeof(a[0]);
    int key, low = 0, high = n - 1, mid, found = -1;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nEnter key: ");
    scanf("%d", &key);

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) { found = mid; break; }
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    if (found != -1) printf("Found %d at index %d\n", key, found);
    else printf("%d not found\n", key);
    return 0;
}
