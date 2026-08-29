/* part_s/q28.c
 * Find the inorder successor of a given key in a BST.
 * Successor = smallest value larger than key (next in inorder).
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

Node* successor(Node *root, int key) {
    Node *succ = NULL, *t = root;
    while (t) {
        if (key >= t->data) t = t->right;
        else { succ = t; t = t->left; }
    }
    return succ;
}

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    int key = 50;
    Node *s = successor(root, key);
    printf("Inorder successor of %d = %s", key, s ? "" : "(none)");
    if (s) printf("%d", s->data);
    printf("\n");
    return 0;
}
