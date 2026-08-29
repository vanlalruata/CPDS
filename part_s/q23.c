/* part_s/q23.c
 * Search for a key in a BST (O(h) average, h = height).
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
int search(Node *t, int key) {
    if (!t) return 0;
    if (t->data == key) return 1;
    return key < t->data ? search(t->left, key) : search(t->right, key);
}

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40};
    for (int i = 0; i < 5; i++) root = insert(root, vals[i]);
    int key = 40;
    printf("Key %d %s in BST\n", key, search(root, key) ? "found" : "not found");
    return 0;
}
