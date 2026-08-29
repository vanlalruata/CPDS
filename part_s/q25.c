/* part_s/q25.c
 * Find the minimum value in a BST (leftmost node).
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

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 10, 60};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    Node *t = root;
    while (t->left) t = t->left;
    printf("Minimum in BST = %d\n", t->data);
    return 0;
}
