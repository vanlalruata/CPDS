/* q47: Height of BST from sorted vs random input; discussion on performance. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Node {
    int data;
    struct Node *left, *right;
};
static struct Node *mk(int v) {
    struct Node *n = malloc(sizeof *n);
    n->data = v; n->left = n->right = NULL; return n;
}
static struct Node *bst_insert(struct Node *r, int v) {
    if (!r) return mk(v);
    if (v < r->data) r->left = bst_insert(r->left, v);
    else if (v > r->data) r->right = bst_insert(r->right, v);
    return r;
}
static int height(struct Node *r) {
    if (!r) return -1;
    int hl = height(r->left), hr = height(r->right);
    return 1 + (hl > hr ? hl : hr);
}
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}
static void shuffle(int *a, int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int t = a[i]; a[i] = a[j]; a[j] = t;
    }
}

int main(void) {
    int N = 15;
    int *sorted = malloc(N * sizeof(int));
    int *randomized = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) { sorted[i] = i + 1; randomized[i] = i + 1; }
    srand((unsigned)time(NULL));
    shuffle(randomized, N);

    struct Node *sroot = NULL, *rroot = NULL;
    for (int i = 0; i < N; ++i) {
        sroot = bst_insert(sroot, sorted[i]);
        rroot = bst_insert(rroot, randomized[i]);
    }

    printf("N = %d\n", N);
    printf("Height of BST from sorted input: %d (worst-case, ~N-1)\n", height(sroot));
    printf("Height of BST from random input: %d (expected ~log2(N)=%.2f)\n",
           height(rroot), log2((double)N));

    printf("\nDiscussion: search/insert/delete are O(height).\n");
    printf("Balanced BST: O(log n). Skewed (e.g., from sorted input): O(n).\n");

    free_tree(sroot); free_tree(rroot);
    free(sorted); free(randomized);
    return 0;
}