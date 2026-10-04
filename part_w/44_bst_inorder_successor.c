/* q44: Inorder successor of a given key in BST. */
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
static int bst_successor(struct Node *r, int key) {
    int succ = -1;
    while (r) {
        if (key < r->data) { succ = r->data; r = r->left; }
        else r = r->right;
    }
    return succ;
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));
    struct Node *root = NULL;
    for (int i = 0; i < n; ++i) root = bst_insert(root, vals[i]);
    int keys[] = {40, 50, 60, 80};
    int m = (int)(sizeof(keys) / sizeof(keys[0]));
    for (int i = 0; i < m; ++i) {
        int s = bst_successor(root, keys[i]);
        printf("Successor of %d = %s\n", keys[i], s < 0 ? "none" : "");
        if (s >= 0) printf("  -> %d\n", s);
    }
    free_tree(root);
    return 0;
}