/* q29: Level-order traversal using a queue. */
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
static void free_tree(struct Node *r) {
    if (!r) return; free_tree(r->left); free_tree(r->right); free(r);
}

struct Queue {
    struct Node **a;
    int front, rear, cap;
};
static void q_init(struct Queue *q, int cap) {
    q->a = malloc(cap * sizeof *q->a);
    q->front = 0; q->rear = 0; q->cap = cap;
}
static int q_empty(struct Queue *q) { return q->front == q->rear; }
static void q_push(struct Queue *q, struct Node *x) { q->a[q->rear++] = x; }
static struct Node *q_pop(struct Queue *q) { return q->a[q->front++]; }
static void q_free(struct Queue *q) { free(q->a); }

static void level_order(struct Node *root) {
    if (!root) return;
    struct Queue q;
    q_init(&q, 256);
    q_push(&q, root);
    printf("Level-order: ");
    while (!q_empty(&q)) {
        struct Node *n = q_pop(&q);
        printf("%d ", n->data);
        if (n->left)  q_push(&q, n->left);
        if (n->right) q_push(&q, n->right);
    }
    printf("\n");
    q_free(&q);
}

int main(void) {
    struct Node *root =
        mk(1,
            mk(2, mk(4, NULL, NULL), mk(5, NULL, NULL)),
            mk(3, NULL, mk(6, NULL, NULL)));
    level_order(root);
    free_tree(root);
    return 0;
}