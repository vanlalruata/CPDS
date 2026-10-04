/*
 * part_o / q12.c
 * Doubly Linked List - Search for an element.
 * Reads n values, then a key; prints its 1-based position or "Not found".
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

void search(Node *head, int key) {
    int pos = 1;
    for (Node *c = head; c; c = c->next, pos++)
        if (c->data == key) { printf("Found at position %d\n", pos); return; }
    printf("Not found\n");
}

int main(void) {
    int n, key;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int v; if (scanf("%d", &v) != 1) break;
        Node *nn = (Node*)malloc(sizeof(Node));
        nn->data = v; nn->prev = tail; nn->next = NULL;
        if (!head) head = nn; else tail->next = nn;
        tail = nn;
    }
    if (scanf("%d", &key) == 1) search(head, key);
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
