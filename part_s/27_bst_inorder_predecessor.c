/* part_s/q27.c
 * Find the inorder predecessor of a given key in a BST.
 * Predecessor = largest value smaller than key (previous in inorder).
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

Node* predecessor(Node *root, int key) {
    Node *pred = NULL, *t = root;
    while (t) {
        if (key <= t->data) t = t->left;
        else { pred = t; t = t->right; }
    }
    return pred; /* NULL if none */
}

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    int key = 60;
    Node *p = predecessor(root, key);
    printf("Inorder predecessor of %d = ", key);
    if (p) printf("%d\n", p->data);
    else printf("(none)\n");
    return 0;
}
