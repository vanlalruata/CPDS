/* part_f q9: Function to check even/odd. Returns 1 if even, 0 if odd. */
#include <stdio.h>

int isEven(int n);

int isEven(int n) {
    return (n % 2 == 0);
}

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return 1;
    if (isEven(n))
        printf("%d is Even\n", n);
    else
        printf("%d is Odd\n", n);
    return 0;
}
