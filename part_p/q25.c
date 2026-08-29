/*
 * part_p / q25.c
 * Stack Using Array - Dynamic memory (malloc-backed array stack).
 * The backing array is allocated with malloc (so it can later be
 * realloc'd to grow). Freed at the end.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int *a; int top; int cap; } Stack;

void init(Stack *s, int cap) { s->a = (int*)malloc(cap * sizeof(int)); s->top = -1; s->cap = cap; }
void push(Stack *s, int x) {
    if (s->top == s->cap - 1) { printf("Overflow (cap=%d)\n", s->cap); return; }
    s->a[++s->top] = x;
}
int pop(Stack *s) { if (s->top == -1) return -1; return s->a[s->top--]; }

int main(void) {
    Stack s; init(&s, 5);
    int n, x;
    if (scanf("%d", &n) != 1) { free(s.a); return 0; }
    for (int i = 0; i < n; i++) { if (scanf("%d", &x) == 1) push(&s, x); }
    printf("Popped: ");
    int v;
    while ((v = pop(&s)) != -1) printf("%d ", v);
    printf("\n");
    free(s.a);
    return 0;
}
