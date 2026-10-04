/* q25: Build a binary tree interactively and display inorder/preorder. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

static struct Node *mk(int v) {
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = n->right = NULL;
    return n;
}
static struct Node *find(struct Node *r, int v) {
    if (!r) return NULL;
    if (r->data == v) return r;
    struct Node *f = find(r->left, v);
    return f ? f : find(r->right, v);
}
static void pre(struct Node *r) {
    if (!r) return;
    printf("%d ", r->data); pre(r->left); pre(r->right);
}
static void in(struct Node *r) {
    if (!r) return;
    in(r->left); printf("%d ", r->data); in(r->right);
}
static void free_tree(struct Node *r) {
    if (!r) return;
    free_tree(r->left); free_tree(r->right); free(r);
}

int main(void) {
    struct Node *root = NULL;
    int choice, val, parent, side;
    while (1) {
        printf("\n1) Insert root  2) Insert left/right  3) Display  4) Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            printf("Value: "); scanf("%d", &val);
            if (!root) { root = mk(val); printf("Root %d created.\n", val); }
            else printf("Root already exists.\n");
        } else if (choice == 2) {
            printf("Parent value and child value: "); scanf("%d %d", &parent, &val);
            printf("Side (0=left,1=right): "); scanf("%d", &side);
            struct Node *p = find(root, parent);
            if (!p) { printf("Parent not found.\n"); continue; }
            if (side == 0 && !p->left) p->left = mk(val);
            else if (side == 1 && !p->right) p->right = mk(val);
            else printf("Slot already occupied or invalid.\n");
        } else if (choice == 3) {
            printf("Preorder: "); pre(root); printf("\nInorder:  "); in(root); printf("\n");
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid.\n");
        }
    }
    free_tree(root);
    return 0;
}