/*
 * part_o / q5.c
 * Doubly Linked List - Insert at end.
 * Reads a list of n integers then a value to append at the tail.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* insertEnd(Node *head, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = NULL;
    if (!head) { nn->prev = NULL; return nn; }
    Node *t = head;
    while (t->next) t = t->next;
    t->next = nn; nn->prev = t;
    return head;
}

int main(void) {
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int v;
        if (scanf("%d", &v) != 1) break;
        head = insertEnd(head, v);
    }
    if (scanf("%d", &x) == 1) head = insertEnd(head, x);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
