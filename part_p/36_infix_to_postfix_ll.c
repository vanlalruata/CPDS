/*
 * part_p / q36.c
 * Stack Using Linked List - Convert infix to postfix using a
 * linked-list stack for operators/parentheses.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { char data; struct Node *next; } Node;

void push(Node **top, char c) { Node *nn = (Node*)malloc(sizeof(Node)); nn->data = c; nn->next = *top; *top = nn; }
char pop(Node **top) { if (!*top) return '\0'; Node *t = *top; char v = t->data; *top = t->next; free(t); return v; }
char peek(Node *top) { return top ? top->data : '\0'; }
int isEmpty(Node *top) { return top == NULL; }

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main(void) {
    Node *top = NULL;
    char str[300];
    if (scanf("%s", str) != 1) return 0;
    printf("Postfix: ");
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            putchar(c);
        else if (c == '(') push(&top, c);
        else if (c == ')') {
            while (!isEmpty(top) && peek(top) != '(') putchar(pop(&top));
            if (!isEmpty(top)) pop(&top);
        } else {
            while (!isEmpty(top) && prec(peek(top)) >= prec(c)) putchar(pop(&top));
            push(&top, c);
        }
    }
    while (!isEmpty(top)) putchar(pop(&top));
    printf("\n");
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
