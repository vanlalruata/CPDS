/* part_s/q24.c
 * Delete a node from a BST handling 0, 1 and 2 children.
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
void inorder(Node *t) { if (!t) return; inorder(t->left); printf("%d ", t->data); inorder(t->right); }

Node* minNode(Node *t) { while (t->left) t = t->left; return t; }

Node* delete(Node *r, int key) {
    if (!r) return NULL;
    if (key < r->data) r->left = delete(r->left, key);
    else if (key > r->data) r->right = delete(r->right, key);
    else {
        if (!r->left) { Node *t = r->right; free(r); return t; } /* 0/1 right child */
        if (!r->right) { Node *t = r->left; free(r); return t; } /* 1 left child */
        Node *succ = minNode(r->right); /* 2 children */
        r->data = succ->data;
        r->right = delete(r->right, succ->data);
    }
    return r;
}

int main() {
    Node *root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insert(root, vals[i]);
    root = delete(root, 30); /* has two children */
    root = delete(root, 20); /* leaf */
    root = delete(root, 70); /* one child */
    printf("After deletions: "); inorder(root); printf("\n");
    return 0;
}
