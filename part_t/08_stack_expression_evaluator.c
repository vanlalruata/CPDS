/* part_t/q8.c — Stack-Based Expression Evaluator
 * Concepts: infix -> postfix, postfix -> evaluation using a stack
 */
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX], top = -1;
void push(int v) { stack[++top] = v; }
int pop() { return stack[top--]; }
int prec(char c) { if (c == '+' || c == '-') return 1; if (c == '*' || c == '/') return 2; return 0; }

void infixToPostfix(char *in, char *post) {
    int j = 0; top = -1;
    for (int i = 0; in[i]; i++) {
        if (isdigit(in[i])) post[j++] = in[i];
        else if (in[i] == '(') push((int)'(');
        else if (in[i] == ')') {
            while (stack[top] != '(') post[j++] = (char)pop();
            pop();
        } else {
            while (top >= 0 && stack[top] != '(' && prec((char)stack[top]) >= prec(in[i]))
                post[j++] = (char)pop();
            push((int)in[i]);
        }
    }
    while (top >= 0) post[j++] = (char)pop();
    post[j] = '\0';
}

int evaluate(char *post) {
    top = -1;
    for (int i = 0; post[i]; i++) {
        if (isdigit(post[i])) push(post[i] - '0');
        else {
            int b = pop(), a = pop();
            if (post[i] == '+') push(a + b);
            else if (post[i] == '-') push(a - b);
            else if (post[i] == '*') push(a * b);
            else if (post[i] == '/') push(a / b);
        }
    }
    return pop();
}

int main(void) {
    char in[MAX], post[MAX];
    printf("Infix (single digit operands): ");
    scanf("%s", in);
    infixToPostfix(in, post);
    printf("Postfix: %s\n", post);
    printf("Result: %d\n", evaluate(post));
    return 0;
}
