/* part_s/q18.c
 * Find the number of nodes at a given level (root is level 0).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int nodesAtLevel(Node *t, int target, int cur) {
    if (!t) return 0;
    if (cur == target) return 1;
    return nodesAtLevel(t->left, target, cur + 1) + nodesAtLevel(t->right, target, cur + 1);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    root->right->right = make(6);
    int level = 2;
    printf("Nodes at level %d = %d\n", level, nodesAtLevel(root, level, 0));
    return 0;
}
