/* part_s/q21.c
 * Create a Binary Search Tree (BST) by inserting sample values.
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

void inorder(Node *t) { if (!t) return; inorder(t->left); printf("%d ", t->data); inorder(t->right); }

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    printf("BST created. Inorder (sorted): ");
    inorder(root);
    printf("\n");
    return 0;
}
