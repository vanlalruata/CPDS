/* q10.c - Pointer to a pointer (double pointer).
 * Concept: int **pp stores the address of an int *.  **pp reaches the
 *          original value through two levels of indirection.
 * Compile: gcc q10.c -o q10
 */
#include <stdio.h>

int main(void)
{
    int x;
    int  *p;
    int **pp;

    printf("Enter an integer: ");
    if (scanf("%d", &x) != 1) { printf("Invalid input.\n"); return 1; }

    p  = &x;
    pp = &p;

    printf("\nx   = %d           at address %p\n", x, (void *) &x);
    printf("p   = %p   at address %p\n", (void *) p,  (void *) &p);
    printf("pp  = %p   at address %p\n", (void *) pp, (void *) &pp);

    printf("\nOne level  : *p   = %d\n", *p);
    printf("Two levels : **pp = %d\n", **pp);
    printf("*pp equals p ? %s\n", (*pp == p) ? "yes" : "no");

    **pp = x + 5;            /* modify x through two levels */
    printf("\nAfter **pp = x + 5 : x = %d\n", x);

    return 0;
}
