/*
 * part_p / q6.c
 * Stack Using Array - isFull() check.
 * Builds a stack then reports whether it is full (size MAX reached).
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct { int a[MAX]; int top; } Stack;

int isFull(Stack *s) { return s->top == MAX - 1; }
void push(Stack *s, int x) { if (!isFull(s)) s->a[++s->top] = x; }

int main(void) {
    Stack s; s.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    printf(isFull(&s) ? "Stack is full\n" : "Stack is not full\n");
    return 0;
}
