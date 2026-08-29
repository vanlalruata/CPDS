/*
 * part_p / q18.c
 * Stack Using Array - Evaluate prefix expression (single digits).
 * Reverses the prefix string then evaluates it like a postfix one.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

typedef struct { int a[MAX]; int top; } Stack;
void push(Stack *s, int x) { s->a[++s->top] = x; }
int pop(Stack *s) { return s->a[s->top--]; }
void reverseStr(char *str) {
    int n = (int)strlen(str);
    for (int i = 0; i < n / 2; i++) { char t = str[i]; str[i] = str[n-1-i]; str[n-1-i] = t; }
}

int main(void) {
    Stack s; s.top = -1;
    char str[MAX];
    if (scanf("%s", str) != 1) return 0;
    reverseStr(str);
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c >= '0' && c <= '9') push(&s, c - '0');
        else {
            int b = pop(&s), a = pop(&s), r = 0;
            if (c == '+') r = a + b;
            else if (c == '-') r = a - b;
            else if (c == '*') r = a * b;
            else if (c == '/') r = a / b;
            push(&s, r);
        }
    }
    printf("Result = %d\n", pop(&s));
    return 0;
}
