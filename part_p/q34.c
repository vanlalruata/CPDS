/*
 * part_p / q34.c
 * Stack Using Linked List - Evaluate postfix expression (single digits).
 * Each stack node holds an operand; operators consume two nodes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { int data; struct Node *next; } Node;

void push(Node **top, int x) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = x; nn->next = *top; *top = nn;
}
int pop(Node **top) {
    if (!*top) return 0;
    Node *t = *top; int v = t->data; *top = t->next; free(t); return v;
}

int main(void) {
    Node *top = NULL;
    char str[300];
    if (scanf("%s", str) != 1) return 0;
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c >= '0' && c <= '9') push(&top, c - '0');
        else {
            int b = pop(&top), a = pop(&top), r = 0;
            if (c == '+') r = a + b;
            else if (c == '-') r = a - b;
            else if (c == '*') r = a * b;
            else if (c == '/') r = a / b;
            push(&top, r);
        }
    }
    printf("Result = %d\n", pop(&top));
    return 0;
}
