/* q34: Depth of a given node (distance from root). */
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
static int depth(struct Node *r, int v, int d) {
    if (!r) return -1;
    if (r->data == v) return d;
    int l = depth(r->left, v, d + 1);
    return (l != -1) ? l : depth(r->right, v, d + 1);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    struct Node *root =
        mk(1, mk(2, mk(4, NULL, NULL), mk(5, NULL, NULL)),
              mk(3, NULL, mk(6, NULL, NULL)));
    int targets[] = {1, 2, 3, 4, 5, 6, 99};
    int m = (int)(sizeof(targets) / sizeof(targets[0]));
    for (int i = 0; i < m; ++i) {
        int d = depth(root, targets[i], 0);
        printf("Depth of %d = %s\n", targets[i], d >= 0 ? "found" : "not found");
        if (d >= 0) printf("  -> %d\n", d);
    }
    free_tree(root);
    return 0;
}