/* part_m/q5.c
 * SUM OF AN ARRAY
 *
 * ALGORITHM STEPS:
 * 1. Initialize sum = 0.
 * 2. Traverse array, adding each element to sum.
 * 3. Output sum.
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    printf("Sum = %d\n", sum);
    return 0;
}
