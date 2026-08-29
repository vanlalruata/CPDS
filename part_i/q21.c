/* q21.c - Swap two numbers using pointers (call by reference).
 * Concept: C passes arguments by value, so a swap function must receive
 *          the ADDRESSES of the variables to change the originals.
 * Compile: gcc q21.c -o q21
 */
#include <stdio.h>

static void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void)
{
    int a, b;

    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) { printf("Invalid input.\n"); return 1; }

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);                  /* pass addresses */
    printf("After  swap: a = %d, b = %d\n", a, b);

    return 0;
}
