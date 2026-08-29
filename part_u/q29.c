/* part_u/q29.c — Incorrect tree traversal
 *
 * BUGGY CODE (inorder of a BST that prints root before left — wrong order):
 * void inorder(struct Node *r) {
 *     if (r) {
 *         printf("%d ", r->data);   // BUG: should visit left FIRST
 *         inorder(r->left);
 *         inorder(r->right);
 *     }
 * }
 *
 * ERROR: Printing the root before the left subtree gives preorder, not inorder.
 *        True inorder for a BST must visit: left, root, right (yields sorted order).
 * FIX: Reorder as left, root, right.
 */
#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *left, *right; };
struct Node *mk(int d) { struct Node *n = malloc(sizeof(struct Node)); n->data = d; n->left = n->right = NULL; return n; }
void inorder(struct Node *r) {
    if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); }
}
int main(void) {
    /* tree: 2 -> left 1, right 3 */
    struct Node *root = mk(2); root->left = mk(1); root->right = mk(3);
    inorder(root);   /* correct: 1 2 3 */
    printf("\n");
    return 0;
}
