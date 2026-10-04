/* q20.c - Find the minimum element using pointers.
 * Concept: Same as the maximum, but the pointer follows the smallest
 *          value.  pmin - a gives its index.
 * Compile: gcc q20.c -o q20
 */
#include <stdio.h>
#include <stddef.h>

#define MAX 50

int main(void)
{
    int a[MAX];
    int n, i;
    int *p, *pmin;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", a + i);

    pmin = a;
    for (p = a + 1; p < a + n; p++)
        if (*p < *pmin)
            pmin = p;

    printf("Array   : ");
    for (p = a; p < a + n; p++) printf("%d ", *p);
    printf("\nMinimum = %d\n", *pmin);
    printf("Index   = %ld (address %p)\n", (long) (pmin - a), (void *) pmin);

    return 0;
}
