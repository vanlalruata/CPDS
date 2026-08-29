/* part_s/q1.c
 * Create a binary tree (insert-based, level by level via queue).
 * Reads values; -1 means no node. Builds tree using a simple queue.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* newNode(int d) {
    Node* n = malloc(sizeof(Node));
    n->data = d; n->left = n->right = NULL;
    return n;
}

int main() {
    int vals[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8};
    int n = sizeof(vals)/sizeof(vals[0]);
    Node *root = newNode(vals[0]);
    Node *q[100]; int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n) {
        Node *cur = q[f++];
        if (vals[i] != -1) { cur->left = newNode(vals[i]); q[r++] = cur->left; }
        i++;
        if (i < n && vals[i] != -1) { cur->right = newNode(vals[i]); q[r++] = cur->right; }
        i++;
    }
    printf("Binary tree created with root %d.\n", root->data);
    printf("Inorder: ");
    void inorder(Node*);
    inorder(root);
    printf("\n");
    return 0;
}

void inorder(Node *t) {
    if (!t) return;
    inorder(t->left); printf("%d ", t->data); inorder(t->right);
}
