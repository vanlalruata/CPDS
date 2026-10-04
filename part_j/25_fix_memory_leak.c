/* part_j / q25: Identify and correct a memory leak.
   WRONG version (leaks memory by reassigning pointer before freeing):
       int *p = malloc(sizeof(int));
       p = malloc(sizeof(int));   // old block lost -> leak
       free(p);
   CORRECT version below frees the first block before reassigning. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = (int *)malloc(sizeof(int));
    if (!p) return 1;
    /* CORRECT: free the old block before losing the reference */
    free(p);
    p = (int *)malloc(sizeof(int));
    if (!p) return 1;
    *p = 7;
    printf("Value = %d\n", *p);
    free(p);
    p = NULL;
    return 0;
}
