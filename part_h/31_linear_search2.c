/* q31.c - Linear search implemented as a function.
 * Concept: Sequential search returns the index of the first match or
 *          -1 when the key is absent.  Time complexity O(n).
 * Compile: gcc q31.c -o q31
 */
#include <stdio.h>

#define MAX 100

/* returns index of key, or -1 if not found */
static int linearSearch(const int a[], int n, int key, int *comparisons)
{
    int i;
    *comparisons = 0;
    for (i = 0; i < n; i++) {
        (*comparisons)++;
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main(void)
{
    int a[MAX];
    int n, i, key, idx, cmp;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    idx = linearSearch(a, n, key, &cmp);

    if (idx >= 0)
        printf("Key %d found at index %d after %d comparison(s).\n", key, idx, cmp);
    else
        printf("Key %d not found (%d comparisons).\n", key, cmp);

    return 0;
}
