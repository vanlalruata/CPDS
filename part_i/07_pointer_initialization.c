/* q7.c - Pointer initialization.
 * Concept: A pointer must be made to point somewhere valid before it is
 *          dereferenced.  Ways to initialize: to NULL, to the address
 *          of a variable, or to an array name (which decays to &a[0]).
 * Compile: gcc q7.c -o q7
 */
#include <stdio.h>

int main(void)
{
    int a, arr[3];
    int *p1 = NULL;       /* 1. safe "points to nothing" state */
    int *p2;              /* uninitialized - must not dereference yet */
    int *p3;

    printf("Enter a value for a: ");
    if (scanf("%d", &a) != 1) { printf("Invalid input.\n"); return 1; }

    printf("Enter 3 array elements: ");
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

    printf("\np1 initialized to NULL : %p (is NULL? %s)\n",
           (void *) p1, p1 == NULL ? "yes" : "no");

    p2 = &a;              /* 2. initialize with an address */
    printf("p2 = &a  -> *p2 = %d\n", *p2);

    p3 = arr;             /* 3. array name decays to a pointer */
    printf("p3 = arr -> *p3 = %d, p3[1] = %d, p3[2] = %d\n",
           *p3, p3[1], p3[2]);

    p1 = &arr[2];         /* re-point a pointer any time */
    printf("p1 = &arr[2] -> *p1 = %d\n", *p1);

    return 0;
}
