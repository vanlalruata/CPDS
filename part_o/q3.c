/*
 * part_o / q3.c
 * Doubly Linked List - Display backward.
 * Builds a list, then prints it by first reaching the tail and
 * traversing prev pointers (reverse order).
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

void displayBackward(Node *head) {
    if (!head) { printf("\n"); return; }
    Node *tail = head;
    while (tail->next) tail = tail->next;
    printf("Backward: ");
    for (Node *c = tail; c; c = c->prev) printf("%d ", c->data);
    printf("\n");
}

void freeList(Node *h) {
    while (h) { Node *t = h->next; free(h); h = t; }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = createList(n);
    displayBackward(head);
    freeList(head);
    return 0;
}
