/* q40: BST delete handling no child, one child, two children (inorder successor). */
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
static struct Node *min_node(struct Node *r) {
    while (r && r->left) r = r->left;
    return r;
}
static struct Node *bst_delete(struct Node *r, int v) {
    if (!r) return NULL;
    if (v < r->data) r->left = bst_delete(r->left, v);
    else if (v > r->data) r->right = bst_delete(r->right, v);
    else {
        if (!r->left && !r->right) { free(r); return NULL; }
        if (!r->left) { struct Node *t = r->right; free(r); return t; }
        if (!r->right) { struct Node *t = r->left;  free(r); return t; }
        struct Node *s = min_node(r->right);
        r->data = s->data;
        r->right = bst_delete(r->right, s->data);
    }
    return r;
}
static void inorder(struct Node *r) {
    if (!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));
    struct Node *root = NULL;
    for (int i = 0; i < n; ++i) root = bst_insert(root, vals[i]);

    printf("Original: "); inorder(root); printf("\n");
    root = bst_delete(root, 20); printf("Delete leaf 20:    "); inorder(root); printf("\n");
    root = bst_delete(root, 30); printf("Delete 1-child 30: "); inorder(root); printf("\n");
    root = bst_delete(root, 50); printf("Delete 2-child 50: "); inorder(root); printf("\n");
    free_tree(root);
    return 0;
}