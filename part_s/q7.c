/* part_s/q7.c
 * Count total nodes in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int countNodes(Node *t) {
    if (!t) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Total nodes = %d\n", countNodes(root));
    return 0;
}
