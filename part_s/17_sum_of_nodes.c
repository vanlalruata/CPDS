/* part_s/q17.c
 * Calculate the sum of all node values in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int sum(Node *t) {
    if (!t) return 0;
    return t->data + sum(t->left) + sum(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Sum of all nodes = %d\n", sum(root));
    return 0;
}
