/* part_t/q23.c — BST Student Records (roll number keys)
 * Operations: Insert, Search, Delete, Inorder, Preorder, Postorder
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int roll;
    char name[50];
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int roll, char *name) {
    if (!root) {
        struct Node *n = malloc(sizeof(struct Node));
        n->roll = roll; strcpy(n->name, name); n->left = n->right = NULL; return n;
    }
    if (roll < root->roll) root->left = insert(root->left, roll, name);
    else root->right = insert(root->right, roll, name);
    return root;
}

struct Node *search(struct Node *root, int roll) {
    while (root) {
        if (root->roll == roll) return root;
        root = (roll < root->roll) ? root->left : root->right;
    }
    return NULL;
}

struct Node *minNode(struct Node *root) { while (root->left) root = root->left; return root; }

struct Node *delete(struct Node *root, int roll) {
    if (!root) return NULL;
    if (roll < root->roll) root->left = delete(root->left, roll);
    else if (roll > root->roll) root->right = delete(root->right, roll);
    else {
        if (!root->left) { struct Node *t = root->right; free(root); return t; }
        if (!root->right) { struct Node *t = root->left; free(root); return t; }
        struct Node *tmp = minNode(root->right);
        root->roll = tmp->roll; strcpy(root->name, tmp->name);
        root->right = delete(root->right, tmp->roll);
    }
    return root;
}

void inorder(struct Node *root) { if (root) { inorder(root->left); printf("%d %s\n", root->roll, root->name); inorder(root->right); } }
void preorder(struct Node *root) { if (root) { printf("%d %s\n", root->roll, root->name); preorder(root->left); preorder(root->right); } }
void postorder(struct Node *root) { if (root) { postorder(root->left); postorder(root->right); printf("%d %s\n", root->roll, root->name); } }

int main(void) {
    struct Node *root = NULL; int ch, roll; char name[50];
    do {
        printf("\n1.Insert 2.Search 3.Delete 4.Inorder 5.Preorder 6.Postorder 7.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("roll name: "); scanf("%d %49s", &roll, name); root = insert(root, roll, name); break;
            case 2: printf("roll: "); scanf("%d", &roll); { struct Node *f = search(root, roll); printf(f ? "Found %s\n" : "Not found\n", f ? f->name : ""); } break;
            case 3: printf("roll: "); scanf("%d", &roll); root = delete(root, roll); break;
            case 4: inorder(root); break;
            case 5: preorder(root); break;
            case 6: postorder(root); break;
        }
    } while (ch != 7);
    return 0;
}
