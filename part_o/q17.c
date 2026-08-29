/*
 * part_o / q17.c
 * Doubly Linked List - Sort the list.
 * Reads n values and sorts the list in ascending order using
 * an insertion sort (or bubble sort on data) because swapping data
 * keeps the prev/next links intact.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* sortList(Node *head) {
    if (!head) return NULL;
    Node *i;
    for (i = head; i; i = i->next) {
        Node *j = i->next;
        for (; j; j = j->next)
            if (i->data > j->data) {
                int t = i->data; i->data = j->data; j->data = t;
            }
    }
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
    head = sortList(head);
    for (Node *c = head; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (head) { Node *t = head->next; free(head); head = t; }
    return 0;
}
