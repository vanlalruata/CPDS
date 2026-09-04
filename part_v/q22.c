/*
 * Program: q22.c
 * Identifies and corrects a use-after-free. The buggy version accesses a
 * pointer after it has been freed; the corrected version NULLs the pointer
 * before reuse or reallocates fresh storage.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * BUGGY VERSION (do not use):
 *
 *   int *p = malloc(sizeof(int));
 *   *p = 10;
 *   free(p);
 *   printf("%d\n", *p);   // <-- use-after-free: undefined behavior
 */

int main(void) {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }
    *p = 10;
    printf("Before free: *p = %d\n", *p);

    free(p);
    p = NULL;

    if (p == NULL) {
        printf("Pointer is NULL after free; not accessing it.\n");
    }

    int *q = malloc(sizeof(int));
    if (q == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }
    *q = 20;
    printf("Fresh allocation: *q = %d\n", *q);

    free(q);
    q = NULL;
    return 0;
}