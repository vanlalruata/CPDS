/* part_j / q27: Identify and correct double-free.
   WRONG version frees the same pointer twice:
       free(p);
       free(p);   // undefined behavior: double-free
   CORRECT version frees once and sets pointer to NULL; freeing NULL is safe. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = (int *)malloc(sizeof(int));
    if (!p) return 1;
    free(p);
    p = NULL;        /* prevents double-free */
    /* freeing NULL is explicitly safe in C */
    free(p);         /* CORRECT: this is a no-op */
    return 0;
}
