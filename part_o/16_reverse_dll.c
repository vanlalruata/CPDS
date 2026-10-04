/*
 * part_o / q16.c
 * Doubly Linked List - Reverse the list.
 * Reads n values and reverses the doubly linked list in place by
 * swapping prev/next pointers of every node.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* reverse(Node *head) {
    Node *c = head, *tmp = NULL;
    while (c) {
        tmp = c->prev;
        c->prev = c->next;
        c->next = tmp;
        c = c->prev;
    }
    if (tmp) head = tmp->prev;
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
    head = reverse(head);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
