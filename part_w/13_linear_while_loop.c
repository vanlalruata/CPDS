/* q13: Linear while loop (find first occurrence by traversal). O(n). */
#include <stdio.h>

int main(void) {
    int a[] = {5, 12, 7, 3, 19, 8, 11};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int key;
    printf("Array: "); for (int i = 0; i < n; ++i) printf("%d ", a[i]); printf("\n");
    printf("Enter key: ");
    if (scanf("%d", &key) != 1) return 0;

    int i = 0, steps = 0;
    while (i < n && a[i] != key) { steps++; i++; }
    if (i < n) printf("Found at index %d in %d steps\n", i, steps + 1);
    else       printf("Not found after %d steps\n", steps);

    printf("Time: O(n), Space: O(1).\n");
    return 0;
}