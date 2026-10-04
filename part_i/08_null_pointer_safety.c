/* q8.c - Demonstrate a NULL pointer safely.
 * Concept: NULL means "points to no object".  Dereferencing a NULL
 *          pointer is undefined behaviour (usually a crash), so always
 *          test  if (p != NULL)  before using it.
 * Compile: gcc q8.c -o q8
 */
#include <stdio.h>

int main(void)
{
    int value;
    int *p = NULL;
    int choice;

    printf("Enter an integer value: ");
    if (scanf("%d", &value) != 1) { printf("Invalid input.\n"); return 1; }

    printf("p is NULL at the moment: %p\n", (void *) p);
    if (p == NULL)
        printf("Safe check: p is NULL, so *p is NOT accessed.\n");

    printf("\nAssign the address of value to p? (1 = yes, 0 = no): ");
    if (scanf("%d", &choice) != 1) choice = 0;

    if (choice == 1)
        p = &value;

    /* the guarded access - this is the safe pattern */
    if (p != NULL)
        printf("p now points to a valid int, *p = %d\n", *p);
    else
        printf("p is still NULL - dereferencing skipped (no crash).\n");

    return 0;
}
