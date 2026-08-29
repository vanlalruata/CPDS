/*
 * part_o / q4.c
 * Doubly Linked List - Insert at beginning.
 * Reads a list of n integers then a value to insert at the front.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* insertBegin(Node *head, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->prev = NULL; nn->next = head;
    if (head) head->prev = nn;
    return nn;
}

int main(void) {
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int v;
        if (scanf("%d", &v) != 1) break;
        head = insertBegin(head, v); /* simple: build then prepend */
    }
    if (scanf("%d", &x) != 1) x = 0;
    /* rebuild order: easier to just insert at front after reading array */
    head = insertBegin(head, x);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
