/*
 * part_o / q6.c
 * Doubly Linked List - Insert at specified position.
 * Reads n values, then 'pos' and 'val' (1-based position).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* insertPos(Node *head, int pos, int x) {
    if (pos <= 1) {
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = x; nn->prev = NULL; nn->next = head;
        if (head) head->prev = nn;
        return nn;
    }
    Node *c = head;
    for (int i = 1; c && i < pos - 1; i++) c = c->next;
    if (!c) return head;
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x;
    nn->prev = c; nn->next = c->next;
    if (c->next) c->next->prev = nn;
    c->next = nn;
    return head;
}

int main(void) {
    int n, pos, x;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    if (scanf("%d%d", &pos, &x) == 2) head = insertPos(head, pos, x);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
