/* q37: Mirror image of a binary tree (swap left/right recursively). */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
static struct Node *mk(int v, struct Node *l, struct Node *r) {
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = l; n->right = r; return n;
}
static void inorder(struct Node *r) {
    if (!r) return; inorder(r->left); printf("%d ", r->data); inorder(r->right);
}
static void mirror(struct Node *r) {
    if (!r) return;
    struct Node *t = r->left; r->left = r->right; r->right = t;
    mirror(r->left); mirror(r->right);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    struct Node *root =
        mk(1, mk(2, mk(4, NULL, NULL), mk(5, NULL, NULL)),
              mk(3, NULL, mk(6, NULL, NULL)));
    printf("Inorder original: "); inorder(root); printf("\n");
    mirror(root);
    printf("Inorder mirrored: "); inorder(root); printf("\n");
    free_tree(root);
    return 0;
}