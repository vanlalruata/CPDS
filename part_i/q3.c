/* q3.c - Modify a variable using a pointer.
 * Concept: Writing through a pointer (*ptr = value) changes the
 *          original variable, because the pointer holds its address.
 * Compile: gcc q3.c -o q3
 */
#include <stdio.h>

int main(void)
{
    int num, newValue;
    int *ptr = NULL;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) { printf("Invalid input.\n"); return 1; }

    ptr = &num;
    printf("Before: num = %d\n", num);

    printf("Enter a new value: ");
    if (scanf("%d", &newValue) != 1) { printf("Invalid input.\n"); return 1; }

    *ptr = newValue;                 /* modifies num indirectly */
    printf("After  *ptr = %d  ->  num = %d\n", newValue, num);

    *ptr += 10;                      /* arithmetic through a pointer */
    printf("After  *ptr += 10 ->  num = %d\n", num);

    return 0;
}
