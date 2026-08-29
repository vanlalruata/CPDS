/* part_s/q15.c
 * Count nodes that have exactly one child in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int countOneChild(Node *t) {
    if (!t) return 0;
    int c = 0;
    if ((t->left && !t->right) || (!t->left && t->right)) c = 1;
    return c + countOneChild(t->left) + countOneChild(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); /* 2 has one child */
    root->right->right = make(5); /* 3 has one child */
    printf("Nodes with exactly one child = %d\n", countOneChild(root));
    return 0;
}
