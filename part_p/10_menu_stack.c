/*
 * part_p / q10.c
 * Stack Using Array - Menu-driven stack.
 * Menu: 1=push 2=pop 3=peek 4=display 5=isEmpty 0=exit.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct { int a[MAX]; int top; } Stack;

int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }
void push(Stack *s, int x) { if (isFull(s)) printf("Overflow\n"); else s->a[++s->top] = x; }
int pop(Stack *s) { if (isEmpty(s)) { printf("Underflow\n"); return -1; } return s->a[s->top--]; }
int peek(Stack *s) { if (isEmpty(s)) { printf("Empty\n"); return -1; } return s->a[s->top]; }
void display(Stack *s) { for (int i = s->top; i >= 0; i--) printf("%d ", s->a[i]); printf("\n"); }

int main(void) {
    Stack s; s.top = -1;
    int ch, x;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) { if (scanf("%d", &x) == 1) push(&s, x); }
        else if (ch == 2) { int v = pop(&s); if (v != -1) printf("Popped %d\n", v); }
        else if (ch == 3) { int v = peek(&s); if (v != -1) printf("Top = %d\n", v); }
        else if (ch == 4) display(&s);
        else if (ch == 5) printf(isEmpty(&s) ? "Empty\n" : "Not empty\n");
    }
    return 0;
}
