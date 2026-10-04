/* part_j / q28: Identify and correct invalid memory access.
   WRONG version writes beyond allocated bounds:
       int *p = malloc(3 * sizeof(int));
       p[5] = 10;   // out-of-bounds: invalid memory access
   CORRECT version stays within the allocated size. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    int *p = (int *)malloc(3 * sizeof(int));
    if (!p) return 1;
    /* CORRECT: only indices 0..2 are valid */
    for (i = 0; i < 3; i++) p[i] = i + 1;
    for (i = 0; i < 3; i++) printf("p[%d] = %d\n", i, p[i]);
    free(p);
    return 0;
}
