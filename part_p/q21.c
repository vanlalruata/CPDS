/*
 * part_p / q21.c
 * Stack Using Array - Multiple stacks (concept + 2-stack demo).
 *
 * CONCEPT: "Multiple stacks" means managing several independent stacks
 * that share one contiguous array. Two common strategies:
 *   1. Fixed partitioning: divide the array into equal slots (simple,
 *      but one stack may overflow while others are empty).
 *   2. Dynamic/linked partitioning: stacks grow toward each other and
 *      shift when one needs more room (efficient but complex).
 *
 * Below is a simple fixed-partition demo with an array of two stacks,
 * each limited to HALF of the backing array.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define HALF (MAX / 2)

typedef struct { int a[HALF]; int top; } MiniStack;

typedef struct { MiniStack s[2]; } MultiStack;

void push(MiniStack *m, int x, int id) {
    if (m->top == HALF - 1) { printf("Stack %d overflow\n", id); return; }
    m->a[++m->top] = x;
}
int pop(MiniStack *m, int id) {
    if (m->top == -1) { printf("Stack %d underflow\n", id); return -1; }
    return m->a[m->top--];
}

int main(void) {
    MultiStack ms;
    ms.s[0].top = -1; ms.s[1].top = -1;
    int m, which, x;
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        if (scanf("%d%d", &which, &x) != 2) break;
        if (which == 0 || which == 1) push(&ms.s[which], x, which);
    }
    printf("pop0=%d pop1=%d\n", pop(&ms.s[0], 0), pop(&ms.s[1], 1));
    return 0;
}
