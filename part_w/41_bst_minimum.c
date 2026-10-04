/* q41: Minimum value in BST (leftmost node). */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
static struct Node *mk(int v) {
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = n->right = NULL; return n;
}
static struct Node *bst_insert(struct Node *r, int v) {
    if (!r) return mk(v);
    if (v < r->data) r->left = bst_insert(r->left, v);
    else if (v > r->data) r->right = bst_insert(r->right, v);
    return r;
}
static int bst_min(struct Node *r) {
    if (!r) return 0;
    while (r->left) r = r->left;
    return r->data;
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 10};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));
    struct Node *root = NULL;
    for (int i = 0; i < n; ++i) root = bst_insert(root, vals[i]);
    printf("Min value = %d\n", bst_min(root));
    free_tree(root);
    return 0;
}