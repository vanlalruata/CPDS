/* q24.c - Find the Nth Fibonacci number */
#include <stdio.h>

int main(void) {
    int n, a = 0, b = 1, c;
    printf("Enter N: ");
    scanf("%d", &n);
    if (n == 1) { printf("F(1) = 0\n"); return 0; }
    if (n == 2) { printf("F(2) = 1\n"); return 0; }
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    printf("F(%d) = %d\n", n, b);
    return 0;
}
