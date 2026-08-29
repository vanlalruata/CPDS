/* part_m/q3.c
 * MAXIMUM IN AN ARRAY
 *
 * ALGORITHM STEPS:
 * 1. Assume a[0] is maximum.
 * 2. Traverse the array; if a[i] > max, update max.
 * 3. Output max.
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {4, 9, 2, 7, 1, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    printf("Maximum element: %d\n", max);
    return 0;
}
