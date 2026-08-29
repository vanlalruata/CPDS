/*
 * part_p / q1.c
 * Stack Using Array - basic push/pop/display menu.
 * Menu: 1=push x, 2=pop, 3=display, 0=exit. Fixed-size array stack.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct { int a[MAX]; int top; } Stack;

void init(Stack *s) { s->top = -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int x) { if (isFull(s)) { printf("Overflow\n"); return; } s->a[++s->top] = x; }
int pop(Stack *s) { if (isEmpty(s)) { printf("Underflow\n"); return -1; } return s->a[s->top--]; }
void display(Stack *s) { for (int i = s->top; i >= 0; i--) printf("%d ", s->a[i]); printf("\n"); }

int main(void) {
    Stack s; init(&s);
    int ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) { if (scanf("%d", &x) == 1) push(&s, x); }
        else if (ch == 2) { int v = pop(&s); if (v != -1) printf("Popped %d\n", v); }
        else if (ch == 3) display(&s);
    }
    return 0;
}
