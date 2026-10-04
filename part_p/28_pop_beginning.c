/*
 * part_p / q28.c
 * Stack Using Linked List - Pop from beginning (head).
 * Builds the stack then pops once and prints the removed value.
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

int main(void) {
    Node *top = NULL;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&top, x); }
    int v = pop(&top);
    if (v != -1) printf("Popped %d\n", v);
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
