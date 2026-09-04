/* q23: Tree terminology demo on a small built tree. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

static struct Node *mk(int v, struct Node *l, struct Node *r) {
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = l; n->right = r;
    return n;
}

static void free_tree(struct Node *r) {
    if (!r) return;
    free_tree(r->left); free_tree(r->right); free(r);
}

static int count_nodes(struct Node *r) {
    return r ? 1 + count_nodes(r->left) + count_nodes(r->right) : 0;
}
static int count_leaves(struct Node *r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    return count_leaves(r->left) + count_leaves(r->right);
}
static int count_internal(struct Node *r) {
    if (!r) return 0;
    int kids = (r->left ? 1 : 0) + (r->right ? 1 : 0);
    int sub = count_internal(r->left) + count_internal(r->right);
    return sub + (kids >= 1 ? 1 : 0);
}
static int height(struct Node *r) {
    if (!r) return -1;
    int hl = height(r->left), hr = height(r->right);
    return 1 + (hl > hr ? hl : hr);
}
static int depth_of(struct Node *r, int v, int d) {
    if (!r) return -1;
    if (r->data == v) return d;
    int l = depth_of(r->left, v, d + 1);
    return (l != -1) ? l : depth_of(r->right, v, d + 1);
}
static int sum_edges(struct Node *r) {
    return r ? count_nodes(r) - 1 : 0;
}

int main(void) {
    /* Tree:
           1
          / \
         2   3
        / \   \
       4   5   6
    */
    struct Node *root =
        mk(1,
            mk(2, mk(4, NULL, NULL), mk(5, NULL, NULL)),
            mk(3, NULL, mk(6, NULL, NULL)));

    printf("Root: %d\n", root->data);
    printf("Total nodes:    %d\n", count_nodes(root));
    printf("Internal nodes: %d\n", count_internal(root));
    printf("Leaves:         %d\n", count_leaves(root));
    printf("Edges (nodes-1):%d\n", sum_edges(root));
    printf("Depth of 1: %d, depth of 5: %d, depth of 6: %d\n",
           depth_of(root, 1, 0), depth_of(root, 5, 0), depth_of(root, 6, 0));
    printf("Height of tree: %d\n", height(root));
    printf("Subtree rooted at 2 has %d nodes; rooted at 3 has %d nodes.\n",
           count_nodes(root->left), count_nodes(root->right));

    free_tree(root);
    return 0;
}