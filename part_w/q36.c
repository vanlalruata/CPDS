/* q36: Search for an element in a binary tree. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
static struct Node *mk(int v, struct Node *l, struct Node *r) {
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = l; n->right = r; return n;
}
static struct Node *search(struct Node *r, int v) {
    if (!r) return NULL;
    if (r->data == v) return r;
    struct Node *f = search(r->left, v);
    return f ? f : search(r->right, v);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    struct Node *root =
        mk(10, mk(5, mk(3, NULL, NULL), mk(7, NULL, NULL)),
              mk(20, mk(15, NULL, NULL), mk(25, NULL, NULL)));
    int keys[] = {7, 25, 100};
    int m = (int)(sizeof(keys) / sizeof(keys[0]));
    for (int i = 0; i < m; ++i) {
        struct Node *r = search(root, keys[i]);
        printf("Search %d: %s\n", keys[i], r ? "found" : "not found");
    }
    free_tree(root);
    return 0;
}