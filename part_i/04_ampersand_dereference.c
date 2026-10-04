/* q4.c - Demonstrate the address-of (&) and indirection (*) operators.
 * Concept: & and * are inverse operations:  *(&x) is x  and, for a
 *          pointer p pointing to x,  &(*p) is p.
 * Compile: gcc q4.c -o q4
 */
#include <stdio.h>

int main(void)
{
    int x;
    int *p;

    printf("Enter an integer x: ");
    if (scanf("%d", &x) != 1) { printf("Invalid input.\n"); return 1; }

    p = &x;

    printf("\n--- & operator (address of) ---\n");
    printf("&x = %p   (address of x)\n", (void *) &x);
    printf("&p = %p   (address of the pointer itself)\n", (void *) &p);

    printf("\n--- * operator (value at address) ---\n");
    printf("x      = %d\n", x);
    printf("*p     = %d   (same as x)\n", *p);
    printf("*(&x)  = %d   (star cancels ampersand)\n", *(&x));
    printf("&(*p)  = %p   (same as p)\n", (void *) &(*p));

    printf("\n--- writing through * ---\n");
    *p = x * 2;
    printf("after *p = x*2 : x = %d\n", x);

    return 0;
}
