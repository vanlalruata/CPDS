/*
 * part_o / q11.c
 * Doubly Linked List - Delete a specified node (by value).
 * Reads n values, then a value; deletes the first node holding it.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* deleteValue(Node *head, int val) {
    Node *c = head;
    while (c && c->data != val) c = c->next;
    if (!c) return head;
    if (c->prev) c->prev->next = c->next; else head = c->next;
    if (c->next) c->next->prev = c->prev;
    free(c);
    return head;
}

int main(void) {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    if (scanf("%d", &val) == 1) head = deleteValue(head, val);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
