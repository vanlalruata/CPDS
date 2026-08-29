/*
 * part_p / q8.c
 * Stack Using Array - Handle stack overflow.
 * Pushes beyond capacity prints an overflow message and keeps the
 * existing contents intact.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct { int a[MAX]; int top; } Stack;

void push(Stack *s, int x) {
    if (s->top == MAX - 1) { printf("Stack Overflow: cannot push %d\n", x); return; }
    s->a[++s->top] = x;
}

int main(void) {
    Stack s; s.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    printf("Stack size = %d\n", s.top + 1);
    return 0;
}
