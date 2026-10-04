/*
 * part_p / q5.c
 * Stack Using Array - isEmpty() check.
 * Reads integers, pops them all while printing isEmpty status.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct { int a[MAX]; int top; } Stack;

int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int x) { if (s->top < MAX - 1) s->a[++s->top] = x; }
int pop(Stack *s) { return s->a[s->top--]; }

int main(void) {
    Stack s; s.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    while (!isEmpty(&s)) { printf("Popped %d\n", pop(&s)); }
    printf(isEmpty(&s) ? "Stack is empty\n" : "Stack not empty\n");
    return 0;
}
