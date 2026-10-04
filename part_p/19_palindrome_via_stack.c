/*
 * part_p / q19.c
 * Stack Using Array - Check palindrome using a stack.
 * Pushes every character, then pops and compares against the
 * original string left-to-right.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

typedef struct { char a[MAX]; int top; } Stack;
void push(Stack *s, char c) { s->a[++s->top] = c; }
char pop(Stack *s) { return s->a[s->top--]; }

int main(void) {
    Stack s; s.top = -1;
    char str[MAX];
    if (scanf("%s", str) != 1) return 0;
    int n = (int)strlen(str);
    for (int i = 0; i < n; i++) push(&s, str[i]);
    int pal = 1;
    for (int i = 0; i < n; i++)
        if (pop(&s) != str[i]) { pal = 0; break; }
    printf(pal ? "Palindrome\n" : "Not a palindrome\n");
    return 0;
}
