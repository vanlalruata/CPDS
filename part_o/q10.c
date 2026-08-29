/*
 * part_o / q10.c
 * Doubly Linked List - Delete last node.
 * Reads n values and removes the tail node.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* deleteLast(Node *head) {
    if (!head) return NULL;
    if (!head->next) { free(head); return NULL; }
    Node *c = head;
    while (c->next) c = c->next;
    c->prev->next = NULL;
    free(c);
    return head;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    head = deleteLast(head);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
