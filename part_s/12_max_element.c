/* part_s/q12.c
 * Find the maximum element in a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int maxVal(Node *t) {
    if (!t) return -2147483647;
    int m = t->data;
    int l = maxVal(t->left), r = maxVal(t->right);
    if (l > m) m = l;
    if (r > m) m = r;
    return m;
}

int main() {
    Node *root = make(10);
    root->left = make(20); root->right = make(5);
    root->left->left = make(40); root->left->right = make(15);
    printf("Maximum = %d\n", maxVal(root));
    return 0;
}
