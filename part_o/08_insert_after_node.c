/*
 * part_o / q8.c
 * Doubly Linked List - Insert after a node (by value).
 * Reads n values, then 'target' and 'val'; inserts val after the
 * first node containing target.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* insertAfter(Node *head, int target, int x) {
    Node *c = head;
    while (c && c->data != target) c = c->next;
    if (!c) return head;
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->prev = c; nn->next = c->next;
    if (c->next) c->next->prev = nn;
    c->next = nn;
    return head;
}

int main(void) {
    int n, target, x;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    if (scanf("%d%d", &target, &x) == 2) head = insertAfter(head, target, x);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
