/* q46: kth largest element in BST using reverse inorder. */
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
static int kth_largest(struct Node *r, int *counter, int k, int *result) {
    if (!r) return 0;
    if (kth_largest(r->right, counter, k, result)) return 1;
    (*counter)++;
    if (*counter == k) { *result = r->data; return 1; }
    return kth_largest(r->left, counter, k, result);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));
    struct Node *root = NULL;
    for (int i = 0; i < n; ++i) root = bst_insert(root, vals[i]);
    for (int k = 1; k <= n; ++k) {
        int c = 0, res = -1;
        kth_largest(root, &c, k, &res);
        printf("k=%d largest = %d\n", k, res);
    }
    free_tree(root);
    return 0;
}