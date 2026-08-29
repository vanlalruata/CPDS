/* part_s/q3.c
 * Preorder traversal of a binary tree (Root, Left, Right).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

void preorder(Node *t) {
    if (!t) return;
    printf("%d ", t->data);
    preorder(t->left);
    preorder(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    return 0;
}
