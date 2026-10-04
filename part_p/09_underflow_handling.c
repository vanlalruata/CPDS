/*
 * part_p / q9.c
 * Stack Using Array - Handle stack underflow.
 * Attempting to pop from an empty stack prints an underflow message.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct { int a[MAX]; int top; } Stack;

int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int x) { if (s->top < MAX - 1) s->a[++s->top] = x; }
int pop(Stack *s) {
    if (isEmpty(s)) { printf("Stack Underflow\n"); return -1; }
    return s->a[s->top--];
}

int main(void) {
    Stack s; s.top = -1;
    int m, op, x;
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        if (scanf("%d", &op) != 1) break;
        if (op == 1) { if (scanf("%d", &x) == 1) push(&s, x); }
        else if (op == 2) { int v = pop(&s); if (v != -1) printf("Popped %d\n", v); }
    }
    return 0;
}
