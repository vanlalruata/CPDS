/* part_u/q24.c — Incorrect linked-list insertion
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * struct N { int d; struct N *next; };
 * int main(void) {
 *     struct N *head = NULL;
 *     struct N *nd = malloc(sizeof(struct N));
 *     nd->d = 10;
 *     head = nd;            // BUG: forgets to set next and loses prior list
 *     printf("%d\n", head->d);
 *     return 0;
 * }
 *
 * ERROR: New node's next must be set; here it is uninitialized (UB) and a prior
 *        list would be lost. Proper prepend: nd->next = head; head = nd;
 * FIX: Set nd->next = head before reassigning head.
 */
#include <stdio.h>
#include <stdlib.h>
struct N { int d; struct N *next; };
int main(void) {
    struct N *head = NULL;
    struct N *nd = malloc(sizeof(struct N));
    nd->d = 10;
    nd->next = head;
    head = nd;
    printf("%d\n", head->d);
    free(head);
    return 0;
}
