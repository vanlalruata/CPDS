/* part_s/q4.c
 * Inorder traversal of a binary tree (Left, Root, Right).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

void inorder(Node *t) {
    if (!t) return;
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    return 0;
}
