/* q36.c - Pointer to a function.
 * Concept: A function name is an address.  int (*fp)(int, int) can hold
 *          it, and the function is called with fp(a, b).  This is how
 *          callbacks and menu tables are built.
 * Compile: gcc q36.c -o q36
 */
#include <stdio.h>

static int add(int a, int b)      { return a + b; }
static int subtract(int a, int b) { return a - b; }
static int multiply(int a, int b) { return a * b; }
static int maximum(int a, int b)  { return (a > b) ? a : b; }

int main(void)
{
    int (*fp)(int, int);                     /* pointer to function */
    int (*table[4])(int, int) = { add, subtract, multiply, maximum };
    const char *names[4] = { "add", "subtract", "multiply", "maximum" };
    int a, b, choice, i;

    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) { printf("Invalid input.\n"); return 1; }

    printf("\nOperations: 0=add 1=subtract 2=multiply 3=maximum\n");
    printf("Enter choice (0-3): ");
    if (scanf("%d", &choice) != 1 || choice < 0 || choice > 3) {
        printf("Invalid choice.\n");
        return 1;
    }

    fp = table[choice];                      /* assign a function */
    printf("\nCalling %s through a function pointer: result = %d\n",
           names[choice], fp(a, b));

    printf("\nAll operations via the function-pointer table:\n");
    for (i = 0; i < 4; i++)
        printf("%-10s(%d, %d) = %d\n", names[i], a, b, table[i](a, b));

    printf("\nfp currently points to the same function as table[%d]: %s\n",
           choice, (fp == table[choice]) ? "yes" : "no");
    return 0;
}
