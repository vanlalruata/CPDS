/*
 * part_p / q15.c
 * Stack Using Array - Convert infix to postfix.
 * Supports + - * / ^ and parentheses. Assumes single-letter operands.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

typedef struct { char a[MAX]; int top; } Stack;
void push(Stack *s, char c) { s->a[++s->top] = c; }
char pop(Stack *s) { return s->a[s->top--]; }
char top(Stack *s) { return s->a[s->top]; }
int isEmpty(Stack *s) { return s->top == -1; }

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main(void) {
    Stack s; s.top = -1;
    char str[MAX];
    if (scanf("%s", str) != 1) return 0;
    printf("Postfix: ");
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            putchar(c);
        else if (c == '(') push(&s, c);
        else if (c == ')') {
            while (!isEmpty(&s) && top(&s) != '(') putchar(pop(&s));
            if (!isEmpty(&s)) pop(&s);
        } else {
            while (!isEmpty(&s) && prec(top(&s)) >= prec(c)) putchar(pop(&s));
            push(&s, c);
        }
    }
    while (!isEmpty(&s)) putchar(pop(&s));
    printf("\n");
    return 0;
}
