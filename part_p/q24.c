/*
 * part_p / q24.c
 * Stack Using Array - Minimum element in a stack (tracked via a
 * second stack). The min-stack holds the running minimum so getMin()
 * is O(1); both advance together on push/pop.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct { int a[MAX]; int top; } Stack;
void push(Stack *s, int x) { s->a[++s->top] = x; }
int pop(Stack *s) { return s->a[s->top--]; }
int isEmpty(Stack *s) { return s->top == -1; }
int peek(Stack *s) { return s->a[s->top]; }

typedef struct { Stack data, min; } MinStack;

void mpush(MinStack *m, int x) {
    push(&m->data, x);
    if (isEmpty(&m->min) || x <= peek(&m->min)) push(&m->min, x);
    else push(&m->min, peek(&m->min));
}
int mpop(MinStack *m) {
    if (isEmpty(&m->data)) return -1;
    pop(&m->min);
    return pop(&m->data);
}
int getMin(MinStack *m) { return isEmpty(&m->min) ? -1 : peek(&m->min); }

int main(void) {
    MinStack m; m.data.top = -1; m.min.top = -1;
    int n, x, ch;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) mpush(&m, x); }
    printf("Min = %d\n", getMin(&m));
    return 0;
}
