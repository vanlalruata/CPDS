/*
 * part_p / q22.c
 * Stack Using Array - Sort a stack using a temporary stack.
 * Repeatedly pop from the source; insert into the helper stack in
 * sorted (ascending) order by shifting larger elements back.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct { int a[MAX]; int top; } Stack;
void push(Stack *s, int x) { s->a[++s->top] = x; }
int pop(Stack *s) { return s->a[s->top--]; }
int isEmpty(Stack *s) { return s->top == -1; }

Stack sortStack(Stack src) {
    Stack tmp; tmp.top = -1;
    while (!isEmpty(&src)) {
        int v = pop(&src);
        while (!isEmpty(&tmp) && tmp.a[tmp.top] > v) push(&src, pop(&tmp));
        push(&tmp, v);
    }
    return tmp;
}

int main(void) {
    Stack s; s.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    s = sortStack(s);
    printf("Sorted (top to bottom): ");
    while (!isEmpty(&s)) printf("%d ", pop(&s));
    printf("\n");
    return 0;
}
