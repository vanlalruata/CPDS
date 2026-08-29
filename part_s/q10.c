/* part_s/q10.c
 * Find the height of a binary tree (number of edges on longest path).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int height(Node *t) {
    if (!t) return -1; /* height in edges; use 0 for height in nodes */
    int l = height(t->left), r = height(t->right);
    return 1 + (l > r ? l : r);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    root->left->left->left = make(6);
    printf("Height (edges) = %d\n", height(root));
    return 0;
}
