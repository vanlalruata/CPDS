/*
 * part_p / q3.c
 * Stack Using Array - pop() function demonstration.
 * Reads integers to build a stack, then pops once and prints result.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct { int a[MAX]; int top; } Stack;

void push(Stack *s, int x) { if (s->top < MAX - 1) s->a[++s->top] = x; }
int pop(Stack *s) {
    if (s->top == -1) { printf("Underflow\n"); return -1; }
    return s->a[s->top--];
}

int main(void) {
    Stack s; s.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    int v = pop(&s);
    if (v != -1) printf("Popped %d\n", v);
    return 0;
}
