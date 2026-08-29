/*
 * part_o / q20.c
 * Doubly Linked List - Compare two lists.
 * Reads two lists and reports whether they are equal (same length
 * and same values in the same order).
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

int compare(Node *a, Node *b) {
    while (a && b) {
        if (a->data != b->data) return 0;
        a = a->next; b = b->next;
    }
    return a == NULL && b == NULL;
}

int main(void) {
    int n1, n2;
    if (scanf("%d", &n1) != 1) return 0;
    Node *a = build(n1);
    if (scanf("%d", &n2) != 1) return 0;
    Node *b = build(n2);
    printf(compare(a, b) ? "Lists are equal\n" : "Lists are not equal\n");
    while (a) { Node *t = a->next; free(a); a = t; }
    while (b) { Node *t = b->next; free(b); b = t; }
    return 0;
}
