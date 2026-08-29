/*
 * part_p / q31.c
 * Stack Using Linked List - Check if empty.
 * Builds the stack (possibly zero elements) then reports empty status.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

int isEmpty(Node *top) { return top == NULL; }
void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = *top; *top = nn;
}

int main(void) {
    Node *top = NULL;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&top, x); }
    printf(isEmpty(top) ? "Stack is empty\n" : "Stack is not empty\n");
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
