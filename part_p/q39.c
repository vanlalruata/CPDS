/*
 * part_p / q39.c
 * Stack Using Linked List - Recursive function via an EXPLICIT stack.
 * Demonstrates how recursion (here: printing numbers 1..n then n..1,
 * i.e. entering/leaving phases) can be simulated with an explicit
 * stack instead of the call stack.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int n; struct Node *next; } Node;

void push(Node **top, int x) { Node *nn = (Node*)malloc(sizeof(Node)); nn->n = x; nn->next = *top; *top = nn; }
int pop(Node **top) { if (!*top) return -1; Node *t = *top; int v = t->n; *top = t->next; free(t); return v; }

int main(void) {
    Node *st = NULL;
    int n;
    if (scanf("%d", &n) != 1) return 0;
    /* "recursive" downward phase: push n, n-1, ..., 1 */
    for (int i = n; i >= 1; i--) push(&st, i);
    printf("Entering phase: ");
    while (st) printf("%d ", pop(&st));
    /* symmetric upward phase using the call order */
    for (int i = 1; i <= n; i++) push(&st, i);
    printf("\nLeaving phase: ");
    while (st) printf("%d ", pop(&st));
    printf("\n");
    return 0;
}
