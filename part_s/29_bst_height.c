/* part_s/q29.c
 * Find the height of a BST (longest root-to-leaf path, in nodes).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }
Node* insert(Node *r, int d) {
    if (!r) return make(d);
    if (d < r->data) r->left = insert(r->left, d);
    else r->right = insert(r->right, d);
    return r;
}

int height(Node *t) {
    if (!t) return 0;
    int l = height(t->left), r = height(t->right);
    return 1 + (l > r ? l : r);
}

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 10};
    for (int i = 0; i < 8; i++) root = insert(root, vals[i]);
    printf("Height of BST (nodes) = %d\n", height(root));
    return 0;
}
