/* q19.c - Find the maximum element using pointers.
 * Concept: Keep a pointer to the largest element seen so far instead of
 *          a copy of the value; then both value and position are known.
 * Compile: gcc q19.c -o q19
 */
#include <stdio.h>
#include <stddef.h>

#define MAX 50

int main(void)
{
    int a[MAX];
    int n, i;
    int *p, *pmax;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", a + i);

    pmax = a;                          /* assume first is largest */
    for (p = a + 1; p < a + n; p++)
        if (*p > *pmax)
            pmax = p;

    printf("Array   : ");
    for (p = a; p < a + n; p++) printf("%d ", *p);
    printf("\nMaximum = %d\n", *pmax);
    printf("Index   = %ld (address %p)\n", (long) (pmax - a), (void *) pmax);

    return 0;
}
