/* part_m/q6.c
 * COUNT OCCURRENCES OF AN ELEMENT
 *
 * ALGORITHM STEPS:
 * 1. Initialize count = 0.
 * 2. Traverse array; if a[i]==key, increment count.
 * 3. Output count.
 *
 * TIME COMPLEXITY: O(n)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

int main(void) {
    int a[] = {2, 5, 2, 8, 2, 9, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int key, count = 0;
    printf("Enter element to count: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++)
        if (a[i] == key) count++;
    printf("%d occurs %d time(s)\n", key, count);
    return 0;
}
