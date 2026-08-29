/* part_m/q9.c
 * INSERTION SORT
 *
 * ALGORITHM STEPS:
 * 1. For i from 1 to n-1, take a[i] as key.
 * 2. Shift all larger elements in a[0..i-1] one position right.
 * 3. Insert key into its correct position.
 *
 * TIME COMPLEXITY: O(n^2)  (worst/average; O(n) best when nearly sorted)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {12, 11, 13, 5, 6};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
