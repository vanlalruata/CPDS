/* q35: Find maximum and minimum element in a binary tree. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};
static struct Node *mk(int v, struct Node *l, struct Node *r) {
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = l; n->right = r; return n;
}
static void extremes(struct Node *r, int *minv, int *maxv) {
    if (!r) return;
    if (r->data < *minv) *minv = r->data;
    if (r->data > *maxv) *maxv = r->data;
    extremes(r->left, minv, maxv); extremes(r->right, minv, maxv);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    struct Node *root =
        mk(10, mk(5, mk(3, NULL, NULL), mk(7, NULL, NULL)),
              mk(20, mk(15, NULL, NULL), mk(25, NULL, NULL)));
    int mn = INT_MAX, mx = INT_MIN;
    extremes(root, &mn, &mx);
    printf("Min = %d, Max = %d\n", mn, mx);
    free_tree(root);
    return 0;
}