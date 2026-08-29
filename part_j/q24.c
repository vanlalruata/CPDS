/* part_j / q24: Demonstrate setting a pointer to NULL after free().
   This prevents accidental use of a dangling pointer. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = (int *)malloc(sizeof(int));
    if (!p) return 1;
    *p = 10;
    printf("Before free: %d\n", *p);
    free(p);
    p = NULL;                 /* safe: no dangling pointer */
    if (p == NULL) {
        printf("Pointer is NULL after free (safe).\n");
    }
    return 0;
}
