/* part_s/q6.c
 * Level-order traversal of a binary tree using a queue (array based).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *left, *right; } Node;

Node* make(int d) { Node* n = malloc(sizeof(Node)); n->data = d; n->left = n->right = NULL; return n; }

void levelOrder(Node *root) {
    if (!root) return;
    Node *q[100]; int f = 0, r = 0;
    q[r++] = root;
    while (f < r) {
        Node *t = q[f++];
        printf("%d ", t->data);
        if (t->left) q[r++] = t->left;
        if (t->right) q[r++] = t->right;
    }
}

int main() {
    Node *root = make(1);
    root->left = make(2); root->right = make(3);
    root->left->left = make(4); root->left->right = make(5);
    root->right->right = make(6);
    printf("Level order: ");
    levelOrder(root);
    printf("\n");
    return 0;
}
