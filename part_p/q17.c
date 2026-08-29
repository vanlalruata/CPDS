/*
 * part_p / q17.c
 * Stack Using Array - Convert infix to prefix.
 * Reverse the infix, swap parentheses, build a reversed postfix,
 * then reverse the result to obtain the prefix expression.
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
void reverseStr(char *str) {
    int n = (int)strlen(str);
    for (int i = 0; i < n / 2; i++) { char t = str[i]; str[i] = str[n-1-i]; str[n-1-i] = t; }
}
char swapP(char c) {
    if (c == '(') return ')';
    if (c == ')') return '(';
    return c;
}

int main(void) {
    char str[MAX];
    if (scanf("%s", str) != 1) return 0;
    reverseStr(str);
    for (int i = 0; str[i]; i++) str[i] = swapP(str[i]);
    Stack s; s.top = -1;
    char out[MAX]; int k = 0;
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            out[k++] = c;
        else if (c == '(') push(&s, c);
        else if (c == ')') {
            while (!isEmpty(&s) && top(&s) != '(') out[k++] = pop(&s);
            if (!isEmpty(&s)) pop(&s);
        } else {
            while (!isEmpty(&s) && prec(top(&s)) > prec(c)) out[k++] = pop(&s);
            push(&s, c);
        }
    }
    while (!isEmpty(&s)) out[k++] = pop(&s);
    out[k] = '\0';
    reverseStr(out);
    printf("Prefix: %s\n", out);
    return 0;
}
