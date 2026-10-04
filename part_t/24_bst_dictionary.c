/* part_t/q24.c — BST Dictionary (words)
 * Operations: Insert, Search, Delete, Display alphabetically (inorder)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, char *w) {
    if (!root) {
        struct Node *n = malloc(sizeof(struct Node)); strcpy(n->word, w);
        n->left = n->right = NULL; return n;
    }
    int c = strcmp(w, root->word);
    if (c < 0) root->left = insert(root->left, w);
    else if (c > 0) root->right = insert(root->right, w);
    return root;
}

int search(struct Node *root, char *w) {
    while (root) {
        int c = strcmp(w, root->word);
        if (c == 0) return 1;
        root = (c < 0) ? root->left : root->right;
    }
    return 0;
}

struct Node *minNode(struct Node *root) { while (root->left) root = root->left; return root; }

struct Node *delete(struct Node *root, char *w) {
    if (!root) return NULL;
    int c = strcmp(w, root->word);
    if (c < 0) root->left = delete(root->left, w);
    else if (c > 0) root->right = delete(root->right, w);
    else {
        if (!root->left) { struct Node *t = root->right; free(root); return t; }
        if (!root->right) { struct Node *t = root->left; free(root); return t; }
        struct Node *tmp = minNode(root->right); strcpy(root->word, tmp->word);
        root->right = delete(root->right, tmp->word);
    }
    return root;
}

void inorder(struct Node *root) { if (root) { inorder(root->left); printf("%s\n", root->word); inorder(root->right); } }

int main(void) {
    struct Node *root = NULL; int ch; char w[50];
    do {
        printf("\n1.Insert 2.Search 3.Delete 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("word: "); scanf("%49s", w); root = insert(root, w); break;
            case 2: printf("word: "); scanf("%49s", w); printf(search(root, w) ? "Found\n" : "Not found\n"); break;
            case 3: printf("word: "); scanf("%49s", w); root = delete(root, w); break;
            case 4: inorder(root); break;
        }
    } while (ch != 5);
    return 0;
}
