/* q31.c - Dynamically allocate ONE integer with malloc.
 * Concept: malloc(sizeof(int)) reserves memory on the heap and returns
 *          its address.  Always check for NULL and free() when done.
 * Compile: gcc q31.c -o q31
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;

    p = (int *) malloc(sizeof(int));      /* allocate one int */
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Memory allocated at %p (%lu byte(s)).\n",
           (void *) p, (unsigned long) sizeof(int));

    printf("Enter an integer to store there: ");
    if (scanf("%d", p) != 1) {            /* p is already an address */
        printf("Invalid input.\n");
        free(p);
        return 1;
    }

    printf("Value stored  : *p = %d\n", *p);
    *p = *p * *p;
    printf("Its square    : *p = %d\n", *p);

    free(p);                              /* release the memory */
    p = NULL;                             /* avoid a dangling pointer */
    printf("Memory freed and pointer set to NULL.\n");

    return 0;
}
