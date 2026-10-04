/*
 * part_p / q32.c
 * Stack Using Linked List - Reverse a stack (linked-list based).
 * Simply reverses the singly linked list that represents the stack,
 * because reversing the links also reverses the LIFO order.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = *top; *top = nn;
}
Node* reverseList(Node *top) {
    Node *prev = NULL, *cur = top;
    while (cur) { Node *nxt = cur->next; cur->next = prev; prev = cur; cur = nxt; }
    return prev;
}

int main(void) {
    Node *top = NULL;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&top, x); }
    top = reverseList(top);
    printf("Reversed: ");
    for (Node *c = top; c; c = c->next) printf("%d ", c->data);
    printf("\n");
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
