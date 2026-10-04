/*
 * part_p / q26.c
 * Stack Using Linked List - implement with a singly linked list,
 * pushing new nodes at the head (so head == top). Menu:
 * 1=push x 2=pop 3=display 0=exit.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = *top; *top = nn;
}
int pop(Node **top) {
    if (!*top) { printf("Underflow\n"); return -1; }
    Node *t = *top; int v = t->data; *top = t->next; free(t); return v;
}
void display(Node *top) {
    for (Node *c = top; c; c = c->next) printf("%d ", c->data);
    printf("\n");
}

int main(void) {
    Node *top = NULL;
    int ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) { if (scanf("%d", &x) == 1) push(&top, x); }
        else if (ch == 2) { int v = pop(&top); if (v != -1) printf("Popped %d\n", v); }
        else if (ch == 3) display(top);
    }
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
