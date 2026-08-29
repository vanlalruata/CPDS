/* part_u/q23.c — Incorrect . versus -> usage
 *
 * BUGGY CODE:
 * #include <stdio.h>
 * #include <stdlib.h>
 * struct Node { int data; struct Node *next; };
 * int main(void) {
 *     struct Node *n = malloc(sizeof(struct Node));
 *     n.data = 10;          // BUG: n is a pointer; must use n->data
 *     printf("%d\n", n->data);
 *     free(n);
 *     return 0;
 * }
 *
 * ERROR: For a pointer to struct, member access uses '->', not '.'.
 * FIX: Use n->data = 10;
 */
#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
int main(void) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = 10;
    printf("%d\n", n->data);
    free(n);
    return 0;
}
