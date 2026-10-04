/* q14.c - Reverse a number */
#include <stdio.h>

int main(void) {
    int n, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0) { rev = rev * 10 + n % 10; n /= 10; }
    printf("Reversed = %d\n", rev);
    return 0;
}
