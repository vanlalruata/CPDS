/* q27: Inorder traversal (left, root, right). */
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
    if (!r) return;
    inorder(r->left); printf("%d ", r->data); inorder(r->right);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}
int main(void) {
    struct Node *root =
        mk(1,
            mk(2, mk(4, NULL, NULL), mk(5, NULL, NULL)),
            mk(3, NULL, mk(6, NULL, NULL)));
    printf("Inorder: "); inorder(root); printf("\n");
    free_tree(root);
    return 0;
}