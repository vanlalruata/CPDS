/*
 * part_p / q2.c
 * Stack Using Array - push() function demonstration.
 * Reads integers and pushes each onto the stack, then displays.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct { int a[MAX]; int top; } Stack;

void push(Stack *s, int x) {
    if (s->top == MAX - 1) { printf("Overflow\n"); return; }
    s->a[++s->top] = x;
}

int main(void) {
    Stack s; s.top = -1;
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    printf("Stack (top to bottom): ");
    for (int i = s.top; i >= 0; i--) printf("%d ", s.a[i]);
    printf("\n");
    return 0;
}
