/* part_t/q25.c — Tree Traversal Comparison
 * Displays Preorder, Inorder, Postorder, Level order of a binary tree.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int d) { struct Node *n = malloc(sizeof(struct Node)); n->data = d; n->left = n->right = NULL; return n; }

void preorder(struct Node *r) { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void inorder(struct Node *r) { if (r) { inorder(r->left); printf("%d ", r->data); inorder(r->right); } }
void postorder(struct Node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

/* simple level order using an array queue */
void levelOrder(struct Node *root) {
    if (!root) return;
    struct Node *q[100]; int f = 0, r = 0; q[r++] = root;
    while (f < r) {
        struct Node *n = q[f++]; printf("%d ", n->data);
        if (n->left) q[r++] = n->left;
        if (n->right) q[r++] = n->right;
    }
}

int main(void) {
    /* build tree:        1
                        /   \
                       2     3
                      / \   /
                     4   5 6
    */
    struct Node *root = newNode(1);
    root->left = newNode(2); root->right = newNode(3);
    root->left->left = newNode(4); root->left->right = newNode(5);
    root->right->left = newNode(6);
    printf("Preorder:   "); preorder(root); printf("\n");
    printf("Inorder:    "); inorder(root); printf("\n");
    printf("Postorder:  "); postorder(root); printf("\n");
    printf("Levelorder: "); levelOrder(root); printf("\n");
    return 0;
}
