/*
 * part_p / q20.c
 * Stack Using Array - Two stacks in one array.
 * Stack1 grows from the left (index 0 upward), stack2 grows from the
 * right (MAX-1 downward). Overflow when they meet.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int a[MAX];
    int top1; /* -1 means empty (left) */
    int top2; /* MAX means empty (right) */
} TwoStacks;

void init(TwoStacks *t) { t->top1 = -1; t->top2 = MAX; }
void push1(TwoStacks *t, int x) {
    if (t->top1 + 1 == t->top2) { printf("Overflow\n"); return; }
    t->a[++t->top1] = x;
}
void push2(TwoStacks *t, int x) {
    if (t->top2 - 1 == t->top1) { printf("Overflow\n"); return; }
    t->a[--t->top2] = x;
}
int pop1(TwoStacks *t) { if (t->top1 == -1) return -1; return t->a[t->top1--]; }
int pop2(TwoStacks *t) { if (t->top2 == MAX) return -1; return t->a[t->top2++]; }

int main(void) {
    TwoStacks t; init(&t);
    /* demo: push 1,2,3 to stack1 and 10,20 to stack2 */
    int m, which, x;
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        if (scanf("%d%d", &which, &x) != 2) break;
        if (which == 1) push1(&t, x); else push2(&t, x);
    }
    printf("pop1=%d pop2=%d\n", pop1(&t), pop2(&t));
    return 0;
}
