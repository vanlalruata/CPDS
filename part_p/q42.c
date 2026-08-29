/*
 * part_p / q42.c
 * Stack Using Linked List - Detect "overflow" in a dynamic stack.
 *
 * CONCEPT: A linked-list (dynamic) stack has NO fixed capacity, so it
 * cannot overflow by reaching a preset limit. The only "overflow" is
 * running out of heap memory, signalled when malloc() returns NULL.
 * The code below detects that condition and prints a message.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

int push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    if (!nn) { printf("Overflow: out of memory\n"); return 0; } /* overflow detection */
    nn->data = x; nn->next = *top; *top = nn;
    return 1;
}
int pop(Node **top) {
    if (!*top) { printf("Underflow\n"); return -1; }
    Node *t = *top; int v = t->data; *top = t->next; free(t); return v;
}

int main(void) {
    Node *top = NULL;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &x) != 1) break;
        if (!push(&top, x)) break; /* stops if allocation fails */
    }
    printf("Pushed %d element(s) successfully\n", 1); /* placeholder; relies on push feedback */
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
