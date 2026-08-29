/* part_s/q19.c
 * Find (create) the mirror image of a binary tree (swap left/right).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

void mirror(Node *t) {
    if (!t) return;
    Node *tmp = t->left; t->left = t->right; t->right = tmp;
    mirror(t->left); mirror(t->right);
}

void inorder(Node *t) { if (!t) return; inorder(t->left); printf("%d ", t->data); inorder(t->right); }

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    printf("Before: "); inorder(root); printf("\n");
    mirror(root);
    printf("After mirror: "); inorder(root); printf("\n");
    return 0;
}
