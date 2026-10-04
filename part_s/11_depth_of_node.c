/* part_s/q11.c
 * Find the depth of a given node (root depth = 0) in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int depth(Node *t, int key, int d) {
    if (!t) return -1;
    if (t->data == key) return d;
    int left = depth(t->left, key, d + 1);
    if (left != -1) return left;
    return depth(t->right, key, d + 1);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    int key = 5;
    int d = depth(root, key, 0);
    printf("Depth of node %d = %d\n", key, d);
    return 0;
}
