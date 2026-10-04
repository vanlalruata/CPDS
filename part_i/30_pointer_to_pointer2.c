/* q30.c - Pointer to pointer used with a function.
 * Concept: To change a pointer itself inside a function you must pass
 *          the address of that pointer (int **).  Here a function
 *          re-points the caller's pointer to the largest element.
 * Compile: gcc q30.c -o q30
 */
#include <stdio.h>

#define MAX 50

/* makes *pp point to the maximum element of the array */
static void pointToMax(int *a, int n, int **pp)
{
    int *p, *best = a;
    for (p = a + 1; p < a + n; p++)
        if (*p > *best)
            best = p;
    *pp = best;              /* modify the caller's pointer */
}

int main(void)
{
    int a[MAX];
    int n, i;
    int  *p  = NULL;
    int **pp = &p;

    printf("Enter number of elements (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) { printf("Invalid size.\n"); return 1; }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) scanf("%d", a + i);

    printf("\nBefore call: p = %p\n", (void *) p);

    pointToMax(a, n, pp);      /* pp holds the address of p */

    printf("After  call: p = %p\n", (void *) p);
    printf("*p   = %d  (maximum element)\n", *p);
    printf("**pp = %d  (same value through two levels)\n", **pp);
    printf("Index of maximum = %ld\n", (long) (p - a));

    return 0;
}
