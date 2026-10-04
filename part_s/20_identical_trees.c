/* part_s/q20.c
 * Check whether two binary trees are identical (same shape and data).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

int identical(Node *a, Node *b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    return (a->data == b->data) && identical(a->left, b->left) && identical(a->right, b->right);
}

int main() {
    Node *a = make(1); a->left = make(2); a->right = make(3);
    Node *b = make(1); b->left = make(2); b->right = make(3);
    Node *c = make(1); c->left = make(2); /* different shape */
    printf("a vs b: %s\n", identical(a, b) ? "identical" : "different");
    printf("a vs c: %s\n", identical(a, c) ? "identical" : "different");
    return 0;
}
