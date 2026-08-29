/*
 * part_p / q29.c
 * Stack Using Linked List - Peek (top element without removing).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = *top; *top = nn;
}
int peek(Node *top) {
    if (!top) { printf("Empty\n"); return -1; }
    return top->data;
}

int main(void) {
    Node *top = NULL;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&top, x); }
    int v = peek(top);
    if (v != -1) printf("Top = %d\n", v);
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
