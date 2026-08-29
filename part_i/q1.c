/* q1.c - Declare an integer pointer and print the address of a variable.
 * Concept: A pointer stores a memory address.  &x gives the address of
 *          x; print addresses with the %p format and a (void *) cast.
 * Compile: gcc q1.c -o q1
 */
#include <stdio.h>

int main(void)
{
    int x;
    int *p;                 /* p is a pointer to int */

    printf("Enter an integer: ");
    if (scanf("%d", &x) != 1) { printf("Invalid input.\n"); return 1; }

    p = &x;                 /* store the address of x in p */

    printf("Value of x            : %d\n", x);
    printf("Address of x (&x)     : %p\n", (void *) &x);
    printf("Value stored in p     : %p\n", (void *) p);
    printf("Address of p itself   : %p\n", (void *) &p);
    printf("Value pointed to (*p) : %d\n", *p);

    return 0;
}
