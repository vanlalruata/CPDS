/*
 * part_p / q45.c
 * Stack Using Linked List - Stack of dynamically allocated nodes.
 * Full menu-driven stack where every element is a malloc'd node:
 * 1=push x 2=pop 3=peek 4=size 5=display 0=exit.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    if (!nn) { printf("Out of memory\n"); return; }
    nn->data = x; nn->next = *top; *top = nn;
}
int pop(Node **top) {
    if (!*top) { printf("Underflow\n"); return -1; }
    Node *t = *top; int v = t->data; *top = t->next; free(t); return v;
}
int peek(Node *top) { if (!top) { printf("Empty\n"); return -1; } return top->data; }
int size(Node *top) { int c = 0; for (; top; top = top->next) c++; return c; }
void display(Node *top) { for (; top; top = top->next) printf("%d ", top->data); printf("\n"); }

int main(void) {
    Node *top = NULL;
    int ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) { if (scanf("%d", &x) == 1) push(&top, x); }
        else if (ch == 2) { int v = pop(&top); if (v != -1) printf("Popped %d\n", v); }
        else if (ch == 3) { int v = peek(top); if (v != -1) printf("Top = %d\n", v); }
        else if (ch == 4) printf("Size = %d\n", size(top));
        else if (ch == 5) display(top);
    }
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
