/*
 * part_o / q1.c
 * Doubly Linked List - Create a doubly linked list.
 * Reads a count n then n integers, builds a doubly linked list,
 * and displays it forward.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* createList(int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = x; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    return head;
}

void freeList(Node *h) {
    while (h) { Node *t = h->next; free(h); h = t; }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = createList(n);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    freeList(head);
    return 0;
}
