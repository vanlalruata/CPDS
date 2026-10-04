/*
 * part_p / q12.c
 * Stack Using Array - Reverse an array using a stack.
 * Reads n then n integers; pushes them and pops to reverse order.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct { int a[MAX]; int top; } Stack;

void push(Stack *s, int x) { if (s->top < MAX - 1) s->a[++s->top] = x; }
int pop(Stack *s) { return s->a[s->top--]; }

int main(void) {
    Stack s; s.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    printf("Reversed: ");
    while (s.top != -1) printf("%d ", pop(&s));
    printf("\n");
    return 0;
}
