/* q28.c - Search an array using pointers.
 * Concept: The search function returns a POINTER to the matching
 *          element, or NULL when the key is absent (the same idea used
 *          by library functions such as strchr).
 * Compile: gcc q28.c -o q28
 */
#include <stdio.h>

#define MAX 50

/* returns pointer to the first element equal to key, else NULL */
static int *search(int *a, int n, int key)
{
    int *p;
    for (p = a; p < a + n; p++)
        if (*p == key)
            return p;
    return NULL;
}

int main(void)
{
    int a[MAX];
    int n, i, key;
    int *found;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", a + i);

    printf("Enter key to search: ");
    if (scanf("%d", &key) != 1) { printf("Invalid input.\n"); return 1; }

    found = search(a, n, key);

    if (found != NULL)
        printf("Key %d found at index %ld (address %p).\n",
               key, (long) (found - a), (void *) found);
    else
        printf("Key %d not found (function returned NULL).\n", key);

    return 0;
}
