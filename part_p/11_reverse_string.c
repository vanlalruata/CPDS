/*
 * part_p / q11.c
 * Stack Using Array - Reverse a string using a stack.
 * Reads a string (no spaces) and prints it reversed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct { char a[MAX]; int top; } Stack;

void push(Stack *s, char c) { if (s->top < MAX - 1) s->a[++s->top] = c; }
char pop(Stack *s) { return s->a[s->top--]; }

int main(void) {
    Stack s; s.top = -1;
    char str[MAX];
    if (scanf("%s", str) != 1) return 0;
    int n = (int)strlen(str);
    for (int i = 0; i < n; i++) push(&s, str[i]);
    printf("Reversed: ");
    while (s.top != -1) putchar(pop(&s));
    printf("\n");
    return 0;
}
