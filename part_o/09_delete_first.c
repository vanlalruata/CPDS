/*
 * part_o / q9.c
 * Doubly Linked List - Delete first node.
 * Reads n values and removes the head node.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* deleteFirst(Node *head) {
    if (!head) return NULL;
    Node *t = head->next;
    if (t) t->prev = NULL;
    free(head);
    return t;
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
    head = deleteFirst(head);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
