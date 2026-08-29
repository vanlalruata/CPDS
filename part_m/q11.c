/* part_m/q11.c
 * FIND DUPLICATE ELEMENTS USING NESTED LOOPS
 *
 * ALGORITHM STEPS:
 * 1. For each i, compare a[i] with every a[j] where j>i.
 * 2. If a[i]==a[j], it is a duplicate -> print it (mark visited to avoid repeats).
 *
 * TIME COMPLEXITY: O(n^2)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {1, 2, 3, 2, 4, 3, 5, 1};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Duplicates: ");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                printf("%d ", a[i]);
                break; /* count this value once */
            }
        }
    }
    printf("\n");
    return 0;
}
