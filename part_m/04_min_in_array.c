/* part_m/q4.c
 * MINIMUM IN AN ARRAY
 *
 * ALGORITHM STEPS:
 * 1. Assume a[0] is minimum.
 * 2. Traverse array; if a[i] < min, update min.
 * 3. Output min.
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {4, 9, 2, 7, 1, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    printf("Minimum element: %d\n", min);
    return 0;
}
