/**
 * bonus_menu_driven.c - Part P: Stack Data Structure Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_CAPACITY 50

// Array-based Stack
int arr_stack[STACK_CAPACITY];
int top = -1;

void push_arr(int val) {
    if (top == STACK_CAPACITY - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    arr_stack[++top] = val;
    printf("Pushed %d onto array stack.\n", val);
}

int pop_arr(void) {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return arr_stack[top--];
}

void display_arr_stack(void) {
    if (top == -1) {
        printf("Stack is EMPTY.\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("[%d] ", arr_stack[i]);
    }
    printf("\n");
}

// Application 1: Balanced Parentheses & Brackets Check
int check_balanced_brackets(const char *expr) {
    char s[100];
    int s_top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s[++s_top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s_top == -1) return 0;
            char open = s[s_top--];
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                return 0;
            }
        }
    }
    return s_top == -1;
}

// Application 2: Postfix Expression Evaluation
int evaluate_postfix(const char *expr) {
    int val_stack[50];
    int v_top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isspace((unsigned char)expr[i])) continue;
        if (isdigit((unsigned char)expr[i])) {
            val_stack[++v_top] = expr[i] - '0';
        } else {
            if (v_top < 1) return -999999;
            int b = val_stack[v_top--];
            int a = val_stack[v_top--];
            switch (expr[i]) {
                case '+': val_stack[++v_top] = a + b; break;
                case '-': val_stack[++v_top] = a - b; break;
                case '*': val_stack[++v_top] = a * b; break;
                case '/': val_stack[++v_top] = (b != 0) ? (a / b) : 0; break;
                default: break;
            }
        }
    }
    return (v_top == 0) ? val_stack[0] : -999999;
}

int main(void) {
    push_arr(10);
    push_arr(20);
    push_arr(30);

    int choice, val;
    char buffer[100];

    do {
        printf("\n============================================\n");
        printf("  Part P: Stack Data Structure Hub          \n");
        printf("============================================\n");
        printf("1. Push Element (Array Stack)\n");
        printf("2. Pop Element\n");
        printf("3. Peek Top Element\n");
        printf("4. Display Stack\n");
        printf("5. Balanced Brackets Checker (Application)\n");
        printf("6. Postfix Expression Evaluator (Application)\n");
        printf("7. Exit\n");
        printf("Enter choice (1-7): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter integer to push: ");
                if (scanf("%d", &val) == 1) push_arr(val);
                break;
            case 2:
                val = pop_arr();
                if (val != -1) printf("Popped: %d\n", val);
                break;
            case 3:
                if (top != -1) printf("Top element: %d\n", arr_stack[top]);
                else printf("Stack is empty.\n");
                break;
            case 4:
                display_arr_stack();
                break;
            case 5:
                printf("Enter expression with brackets (e.g. {[()]}: ");
                scanf(" %99s", buffer);
                if (check_balanced_brackets(buffer)) {
                    printf("Result: The brackets are BALANCED!\n");
                } else {
                    printf("Result: The brackets are NOT balanced!\n");
                }
                break;
            case 6:
                printf("Enter single-digit postfix expr (e.g. 5 3 + 2 *): ");
                scanf(" %99[^\n]", buffer);
                val = evaluate_postfix(buffer);
                if (val != -999999) {
                    printf("Evaluation Result: %d\n", val);
                } else {
                    printf("Invalid postfix expression!\n");
                }
                break;
            case 7:
                printf("Exiting Part P Hub. Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
