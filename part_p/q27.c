/*
 * part_p / q27.c
 * Stack Using Linked List - Push at beginning (head).
 * Reads n integers and pushes each at the head of the list.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = *top; *top = nn;
}

int main(void) {
    Node *top = NULL;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&top, x); }
    printf("Stack: ");
    for (Node *c = top; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
