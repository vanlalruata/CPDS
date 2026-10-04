/* part_s/q22.c
 * Insert a node into a BST (user-driven).
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
    int n, v;
    printf("How many values? "); scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &v); root = insert(root, v); }
    printf("BST inorder: "); inorder(root); printf("\n");
    return 0;
}
