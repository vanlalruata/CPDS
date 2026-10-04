/* q33: Height of a binary tree (edges-based: single node has height 0). */
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
static int height(struct Node *r) {
    if (!r) return -1;
    int hl = height(r->left), hr = height(r->right);
    return 1 + (hl > hr ? hl : hr);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    struct Node *root =
        mk(1, mk(2, mk(4, NULL, NULL), mk(5, NULL, NULL)),
              mk(3, NULL, mk(6, NULL, NULL)));
    printf("Height = %d\n", height(root));
    free_tree(root);
    return 0;
}