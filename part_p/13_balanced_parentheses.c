/*
 * part_p / q13.c
 * Stack Using Array - Check balanced parentheses.
 * Reads a string containing '(' and ')'; prints Balanced/Not balanced.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

typedef struct { char a[MAX]; int top; } Stack;

void push(Stack *s, char c) { s->a[++s->top] = c; }
char pop(Stack *s) { return s->a[s->top--]; }
int isEmpty(Stack *s) { return s->top == -1; }

int main(void) {
    Stack s; s.top = -1;
    char str[MAX];
    if (scanf("%s", str) != 1) return 0;
    int ok = 1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') push(&s, str[i]);
        else if (str[i] == ')') {
            if (isEmpty(&s)) { ok = 0; break; }
            pop(&s);
        }
    }
    if (ok && isEmpty(&s)) printf("Balanced\n"); else printf("Not balanced\n");
    return 0;
}
