/*
 * part_o / q19.c
 * Doubly Linked List - Merge two lists.
 * Reads size n1 and n1 values, then size n2 and n2 values; appends
 * the second list to the end of the first and displays the result.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* build(int n) {
    Node *h = NULL, *t = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = t; nn->next = NULL;
        if (!h) h = nn; else t->next = nn;
        t = nn;
    }
    return h;
}

Node* merge(Node *a, Node *b) {
    if (!a) return b;
    Node *t = a;
    while (t->next) t = t->next;
    t->next = b;
    if (b) b->prev = t;
    return a;
}

int main(void) {
    int n1, n2;
    if (scanf("%d", &n1) != 1) return 0;
    Node *a = build(n1);
    if (scanf("%d", &n2) != 1) return 0;
    Node *b = build(n2);
    a = merge(a, b);
    for (Node *c = a; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (a) { Node *t = a->next; free(a); a = t; }
    return 0;
}
