/*
 * part_p / q37.c
 * Stack Using Linked List - Implement an undo operation.
 * Each action is an integer id. Menu: 1=do x, 2=undo (pop the most
 * recent action), 3=show current top. Undo removes the latest action
 * from the stack.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int act; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->act = x; nn->next = *top; *top = nn;
}
int pop(Node **top) {
    if (!*top) { printf("Nothing to undo\n"); return -1; }
    Node *t = *top; int v = t->act; *top = t->next; free(t); return v;
}

int main(void) {
    Node *top = NULL;
    int ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) { if (scanf("%d", &x) == 1) { push(&top, x); printf("Did %d\n", x); } }
        else if (ch == 2) { int v = pop(&top); if (v != -1) printf("Undo %d\n", v); }
        else if (ch == 3) printf("Current action: %s\n", top ? "active" : "none");
    }
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
