/* part_s/q30.c
 * Display a BST using preorder, inorder and postorder traversals,
 * and include a bonus check: is this binary tree a valid BST?
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }
Node* insert(Node *r, int d) {
    if (!r) return make(d);
    if (d < r->data) r->left = insert(r->left, d);
    else r->right = insert(r->right, d);
    return r;
}

void preorder(Node *t)  { if (!t) return; printf("%d ", t->data); preorder(t->left); preorder(t->right); }
void inorder(Node *t)   { if (!t) return; inorder(t->left); printf("%d ", t->data); inorder(t->right); }
void postorder(Node *t) { if (!t) return; postorder(t->left); postorder(t->right); printf("%d ", t->data); }

int isBST(Node *t, int min, int max) {
    if (!t) return 1;
    if (t->data <= min || t->data >= max) return 0;
    return isBST(t->left, min, t->data) && isBST(t->right, t->data, max);
}

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    printf("Preorder : "); preorder(root); printf("\n");
    printf("Inorder  : "); inorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    printf("Is this a valid BST? %s\n", isBST(root, -2147483648, 2147483647) ? "YES" : "NO");
    return 0;
}
