/*
 * part_o / q23.c
 * Deque (double-ended queue) using a doubly linked list.
 * Menu (stdin commands): 1=insertFront x, 2=insertRear x,
 * 3=deleteFront, 4=deleteRear, 5=display, 0=exit.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

typedef struct { Node *front, *rear; } Deque;

void insertFront(Deque *d, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->prev = NULL; nn->next = d->front;
    if (d->front) d->front->prev = nn; else d->rear = nn;
    d->front = nn;
}
void insertRear(Deque *d, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = NULL; nn->prev = d->rear;
    if (d->rear) d->rear->next = nn; else d->front = nn;
    d->rear = nn;
}
void deleteFront(Deque *d) {
    if (!d->front) { printf("Deque empty\n"); return; }
    Node *t = d->front; d->front = d->front->next;
    if (d->front) d->front->prev = NULL; else d->rear = NULL;
    free(t);
}
void deleteRear(Deque *d) {
    if (!d->rear) { printf("Deque empty\n"); return; }
    Node *t = d->rear; d->rear = d->rear->prev;
    if (d->rear) d->rear->next = NULL; else d->front = NULL;
    free(t);
}
void display(Deque *d) {
    for (Node *c = d->front; c; c = c->next) printf("%d ", c->data);
    printf("\n");
}

int main(void) {
    Deque d = {NULL, NULL};
    int ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) { if (scanf("%d", &x) == 1) insertFront(&d, x); }
        else if (ch == 2) { if (scanf("%d", &x) == 1) insertRear(&d, x); }
        else if (ch == 3) deleteFront(&d);
        else if (ch == 4) deleteRear(&d);
        else if (ch == 5) display(&d);
    }
    while (d.front) { Node *t = d.front->next; free(d.front); d.front = t; }
    return 0;
}
