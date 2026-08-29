/* part_f q29: Menu-driven calculator using separate functions. */
#include <stdio.h>

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divv(double a, double b) { return b != 0 ? a / b : 0; }

int main(void) {
    int ch;
    double x, y;
    do {
        printf("\n--- Calculator Menu ---\n");
        printf("1.Add 2.Sub 3.Mul 4.Div 5.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) return 1;
        if (ch >= 1 && ch <= 4) {
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &x, &y) != 2) return 1;
        }
        switch (ch) {
            case 1: printf("Result = %.2f\n", add(x, y)); break;
            case 2: printf("Result = %.2f\n", sub(x, y)); break;
            case 3: printf("Result = %.2f\n", mul(x, y)); break;
            case 4:
                if (y == 0) printf("Error: division by zero\n");
                else printf("Result = %.2f\n", divv(x, y));
                break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 5);
    return 0;
}
