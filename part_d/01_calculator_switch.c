/* q1.c - Calculator using switch (+, -, *, /)
   Reads two numbers and an operator, then prints the result. */
#include <stdio.h>

int main(void) {
    double a, b, result;
    char op;
    printf("Enter expression (a op b): ");
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
        printf("Invalid input\n");
        return 1;
    }
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) { printf("Error: division by zero\n"); return 1; }
            result = a / b; break;
        default: printf("Error: unknown operator\n"); return 1;
    }
    printf("Result = %.2f\n", result);
    return 0;
}
