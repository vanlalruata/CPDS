/* part_s/q14.c
 * Search for an element in a binary tree (any position).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int search(Node *t, int key) {
    if (!t) return 0;
    if (t->data == key) return 1;
    return search(t->left, key) || search(t->right, key);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->right = make(5);
    int key = 5;
    printf("Element %d %s\n", key, search(root, key) ? "found" : "not found");
    return 0;
}
