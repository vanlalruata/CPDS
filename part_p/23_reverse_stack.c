/*
 * part_p / q23.c
 * Stack Using Array - Reverse a stack using another stack.
 * Pop everything from the source into a helper stack; the helper now
 * holds the elements in reversed order.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct { int a[MAX]; int top; } Stack;
void push(Stack *s, int x) { s->a[++s->top] = x; }
int pop(Stack *s) { return s->a[s->top--]; }
int isEmpty(Stack *s) { return s->top == -1; }

int main(void) {
    Stack s, r; s.top = -1; r.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    while (!isEmpty(&s)) push(&r, pop(&s));
    printf("Reversed: ");
    while (!isEmpty(&r)) printf("%d ", pop(&r));
    printf("\n");
    return 0;
}
