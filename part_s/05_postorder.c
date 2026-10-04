/* part_s/q5.c
 * Postorder traversal of a binary tree (Left, Right, Root).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

void postorder(Node *t) {
    if (!t) return;
    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->data);
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
