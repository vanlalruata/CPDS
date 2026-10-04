/* q23.c - Generate Fibonacci series up to N terms */
#include <stdio.h>

int main(void) {
    int n, a = 0, b = 1, c;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
