/* part_m/q1.c
 * LINEAR SEARCH
 *
 * ALGORITHM STEPS:
 * 1. Traverse the array from index 0 to n-1.
 * 2. Compare each element with the target key.
 * 3. If found, return the index; else return -1 after the loop.
 *
 * TIME COMPLEXITY: O(n)  (worst/average; O(1) best when first element)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {5, 8, 2, 10, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int key, i, found = -1;

    printf("Array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\nEnter key to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) { found = i; break; }
    }

    if (found != -1) printf("Found %d at index %d\n", key, found);
    else printf("%d not found\n", key);
    return 0;
}
