/* part_t/q9.c — Parentheses Checker {[()]}
 * Concepts: stack for balanced bracket checking
 */
#include <stdio.h>

#define MAX 100

char stack[MAX]; int top = -1;
void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int isMatch(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int balanced(char *s) {
    top = -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') push(s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top < 0 || !isMatch(stack[top], s[i])) return 0;
            pop();
        }
    }
    return top == -1;
}

int main(void) {
    char s[MAX];
    printf("Expression: ");
    scanf("%s", s);
    printf(balanced(s) ? "Balanced\n" : "Not balanced\n");
    return 0;
}
