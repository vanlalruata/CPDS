/* part_s/q2.c
 * Represent a binary tree using linked nodes (each node has left/right).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* make(int d) {
    Node* n = malloc(sizeof(Node));
    n->data = d; n->left = n->right = NULL;
    return n;
}

int main() {
    Node *root = make(1);
    root->left = make(2);
    root->right = make(3);
    root->left->left = make(4);
    root->left->right = make(5);
    printf("Structure:\n");
    printf("      %d\n", root->data);
    printf("    /   \\\n");
    printf("   %d     %d\n", root->left->data, root->right->data);
    printf("  / \\\n");
    printf(" %d   %d\n", root->left->left->data, root->left->right->data);
    return 0;
}
