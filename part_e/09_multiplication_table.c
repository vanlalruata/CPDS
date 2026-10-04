/* q9.c - Multiplication table of a number */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) printf("%d x %d = %d\n", n, i, n * i);
    return 0;
}
