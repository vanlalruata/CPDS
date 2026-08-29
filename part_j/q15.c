/* part_j / q15: Compare malloc() vs calloc() experimentally.
   malloc leaves garbage; calloc zeroes memory. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    int *m = (int *)malloc(5 * sizeof(int));
    int *c = (int *)calloc(5, sizeof(int));
    if (!m || !c) return 1;
    printf("malloc (uninitialized garbage): ");
    for (i = 0; i < 5; i++) printf("%d ", m[i]);
    printf("\ncalloc (zeroed):              ");
    for (i = 0; i < 5; i++) printf("%d ", c[i]);
    printf("\n");
    free(m);
    free(c);
    return 0;
}
