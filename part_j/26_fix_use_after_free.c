/* part_j / q26: Identify and correct use-after-free.
   WRONG version accesses memory after free():
       int *p = malloc(sizeof(int));
       free(p);
       *p = 5;     // undefined behavior: use-after-free
   CORRECT version below does not use memory after freeing it. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = (int *)malloc(sizeof(int));
    if (!p) return 1;
    *p = 5;
    printf("Value = %d\n", *p);
    free(p);
    p = NULL;
    /* CORRECT: do not dereference p after free */
    return 0;
}
