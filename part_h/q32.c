/* q32.c - Binary search on a SORTED array.
 * Concept: Repeatedly halve the search interval: compare the key with
 *          the middle element and discard the impossible half.
 *          Requires sorted data; time complexity O(log n).
 * Compile: gcc q32.c -o q32
 */
#include <stdio.h>

#define MAX 100

static int binarySearch(const int a[], int n, int key, int *steps)
{
    int low = 0, high = n - 1, mid;
    *steps = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;   /* avoids overflow */
        (*steps)++;
        if (a[mid] == key)      return mid;
        else if (a[mid] < key)  low  = mid + 1;
        else                    high = mid - 1;
    }
    return -1;
}

int main(void)
{
    int a[MAX];
    int n, i, key, idx, steps;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d integers in ASCENDING order: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    idx = binarySearch(a, n, key, &steps);

    if (idx >= 0)
        printf("Key %d found at index %d in %d step(s).\n", key, idx, steps);
    else
        printf("Key %d not found (%d step(s)).\n", key, steps);

    return 0;
}
