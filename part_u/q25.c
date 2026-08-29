/* part_u/q25.c — Incorrect linked-list deletion
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * struct N { int d; struct N *next; };
 * int main(void) {
 *     struct N *a = malloc(sizeof(struct N));
 *     struct N *b = malloc(sizeof(struct N));
 *     a->d = 1; a->next = b; b->d = 2; b->next = NULL;
 *     // delete b:
 *     free(b);              // BUG: a->next still points to freed b (dangling)
 *     printf("%d\n", a->next->d);   // UB
 *     return 0;
 * }
 *
 * ERROR: After freeing b, a->next still references it (dangling pointer).
 * FIX: Relink a->next = b->next before freeing b.
 */
#include <stdio.h>
#include <stdlib.h>
struct N { int d; struct N *next; };
int main(void) {
    struct N *a = malloc(sizeof(struct N));
    struct N *b = malloc(sizeof(struct N));
    a->d = 1; a->next = b; b->d = 2; b->next = NULL;
    a->next = b->next;   /* relink before free */
    free(b);
    printf("next is null? %d\n", a->next == NULL);
    free(a);
    return 0;
}
