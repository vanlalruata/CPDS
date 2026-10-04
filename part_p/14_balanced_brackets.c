/*
 * part_p / q14.c
 * Stack Using Array - Check balanced brackets ( ), { }, [ ].
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

typedef struct { char a[MAX]; int top; } Stack;

void push(Stack *s, char c) { s->a[++s->top] = c; }
char pop(Stack *s) { return s->a[s->top--]; }
int isEmpty(Stack *s) { return s->top == -1; }
int match(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int main(void) {
    Stack s; s.top = -1;
    char str[MAX];
    if (scanf("%s", str) != 1) return 0;
    int ok = 1;
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[') push(&s, c);
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s) || !match(s.a[s.top], c)) { ok = 0; break; }
            pop(&s);
        }
    }
    printf((ok && isEmpty(&s)) ? "Balanced\n" : "Not balanced\n");
    return 0;
}
