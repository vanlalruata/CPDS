/* q33.c - Compare linear search and binary search.
 * Concept: Both searches run on the same sorted array and the number of
 *          comparisons is printed, showing that binary search needs far
 *          fewer steps: O(n) versus O(log n).
 * Compile: gcc q33.c -o q33
 */
#include <stdio.h>

#define MAX 100

static int linearSearch(const int a[], int n, int key, int *cmp)
{
    int i;
    *cmp = 0;
    for (i = 0; i < n; i++) {
        (*cmp)++;
        if (a[i] == key) return i;
    }
    return -1;
}

static int binarySearch(const int a[], int n, int key, int *cmp)
{
    int low = 0, high = n - 1, mid;
    *cmp = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        (*cmp)++;
        if (a[mid] == key)     return mid;
        else if (a[mid] < key) low  = mid + 1;
        else                   high = mid - 1;
    }
    return -1;
}

int main(void)
{
    int a[MAX];
    int n, i, key;
    int li, bi, lc, bc;

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

    li = linearSearch(a, n, key, &lc);
    bi = binarySearch(a, n, key, &bc);

    printf("\n%-16s %-10s %s\n", "Method", "Index", "Comparisons");
    printf("%-16s %-10d %d\n", "Linear search", li, lc);
    printf("%-16s %-10d %d\n", "Binary search", bi, bc);

    printf("\n(index -1 means the key is not present)\n");
    if (bc < lc)
        printf("Binary search used %d fewer comparison(s).\n", lc - bc);
    else if (bc > lc)
        printf("Linear search used %d fewer comparison(s) for this key.\n", bc - lc);
    else
        printf("Both methods used the same number of comparisons.\n");

    return 0;
}
