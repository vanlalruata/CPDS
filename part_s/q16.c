/* part_s/q16.c
 * Count nodes that have exactly two children in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int countTwoChildren(Node *t) {
    if (!t) return 0;
    int c = (t->left && t->right) ? 1 : 0;
    return c + countTwoChildren(t->left) + countTwoChildren(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3); /* root has two children */
    root->left->left = make(4); root->left->right = make(5); /* 2 has two children */
    printf("Nodes with two children = %d\n", countTwoChildren(root));
    return 0;
}
