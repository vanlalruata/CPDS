/* part_j / q23: Demonstrate proper use of free().
   Allocate, use, then free exactly once and only valid pointers. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = (int *)malloc(sizeof(int));
    if (!p) return 1;
    *p = 42;
    printf("Value = %d\n", *p);
    free(p);          /* proper single free */
    p = NULL;         /* good practice: avoid dangling pointer */
    return 0;
}
