/* part_s/q8.c
 * Count leaf nodes (nodes with no children) in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int countLeaves(Node *t) {
    if (!t) return 0;
    if (!t->left && !t->right) return 1;
    return countLeaves(t->left) + countLeaves(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Leaf nodes = %d\n", countLeaves(root));
    return 0;
}
