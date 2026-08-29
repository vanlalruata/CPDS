/* q22.c - Maximum and minimum using pointer parameters.
 * Concept: A function cannot return two values, but it can write both
 *          results into memory supplied by the caller through pointers.
 * Compile: gcc q22.c -o q22
 */
#include <stdio.h>

#define MAX 50

static void findMinMax(const int *a, int n, int *min, int *max)
{
    int i;
    *min = *max = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
}

int main(void)
{
    int a[MAX];
    int n, i, mn, mx;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    findMinMax(a, n, &mn, &mx);

    printf("Minimum = %d\n", mn);
    printf("Maximum = %d\n", mx);
    printf("Range   = %d\n", mx - mn);

    return 0;
}
