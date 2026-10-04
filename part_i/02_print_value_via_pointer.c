/* q2.c - Print the value of a variable using a pointer.
 * Concept: The indirection (dereference) operator * fetches the value
 *          kept at the address held by the pointer.
 * Compile: gcc q2.c -o q2
 */
#include <stdio.h>

int main(void)
{
    int num;
    int *ptr;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) { printf("Invalid input.\n"); return 1; }

    ptr = &num;

    printf("Direct access  : num = %d\n", num);
    printf("Via pointer    : *ptr = %d\n", *ptr);
    printf("Both refer to the same memory location %p\n", (void *) ptr);

    return 0;
}
