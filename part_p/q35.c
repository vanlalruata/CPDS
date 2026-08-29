/*
 * part_p / q35.c
 * Stack Using Linked List - Check balanced parentheses with a
 * linked-list stack (no fixed-size backing array).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { char data; struct Node *next; } Node;

void push(Node **top, char c) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->data = c; nn->next = *top; *top = nn;
}
char pop(Node **top) {
    if (!*top) return '\0';
    Node *t = *top; char v = t->data; *top = t->next; free(t); return v;
}
int isEmpty(Node *top) { return top == NULL; }

int main(void) {
    Node *top = NULL;
    char str[300];
    if (scanf("%s", str) != 1) return 0;
    int ok = 1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') push(&top, '(');
        else if (str[i] == ')') {
            if (isEmpty(top)) { ok = 0; break; }
            pop(&top);
        }
    }
    printf((ok && isEmpty(top)) ? "Balanced\n" : "Not balanced\n");
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
