/* part_f q18: Function to generate Fibonacci series up to n terms. */
#include <stdio.h>

void fibonacci(int n);

void fibonacci(int n) {
    long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        printf("%ld ", a);
        long next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main(void) {
    int n;
    printf("Enter number of terms: ");
    if (scanf("%d", &n) != 1 || n < 0) return 1;
    printf("Fibonacci series:\n");
    fibonacci(n);
    return 0;
}
