/*
 * Program: q23.c
 * Identifies and corrects a double-free. The buggy version calls free()
 * twice on the same pointer; the corrected version sets the pointer to NULL
 * after free so the second free becomes a safe no-op.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * BUGGY VERSION (do not use):
 *
 *   int *p = malloc(sizeof(int));
 *   free(p);
 *   free(p);   // <-- double-free: undefined behavior, may crash
 */

int main(void) {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }
    *p = 99;

    free(p);
    p = NULL;

    free(p);
    printf("Double-free guarded by NULL assignment completed safely.\n");

    return 0;
}