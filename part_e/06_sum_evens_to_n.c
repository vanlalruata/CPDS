/* q6.c - Sum of all even numbers up to N */
#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Enter N: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) sum += i;
    printf("Sum of evens = %d\n", sum);
    return 0;
}
