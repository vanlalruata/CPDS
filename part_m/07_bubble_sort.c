/* part_m/q7.c
 * BUBBLE SORT
 *
 * ALGORITHM STEPS:
 * 1. Repeat n-1 passes.
 * 2. In each pass, compare adjacent pairs and swap if out of order.
 * 3. Largest element "bubbles" to the end each pass.
 *
 * TIME COMPLEXITY: O(n^2)  (worst/average/best with optimization O(n))
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
        }
    }
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
