/* part_s/q9.c
 * Count internal nodes (nodes with at least one child) in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int countInternal(Node *t) {
    if (!t || (!t->left && !t->right)) return 0;
    return 1 + countInternal(t->left) + countInternal(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Internal nodes = %d\n", countInternal(root));
    return 0;
}
