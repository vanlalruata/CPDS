/*
 * part_o / q13.c
 * Doubly Linked List - Count nodes.
 * Reads n values and prints the total number of nodes.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

int count(Node *head) {
    int c = 0;
    for (Node *p = head; p; p = p->next) c++;
    return c;
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
    printf("Count = %d\n", count(head));
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
