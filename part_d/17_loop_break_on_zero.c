/* q17.c - Loop terminates when user enters 0, using break */
#include <stdio.h>

int main(void) {
    int n;
    while (1) {
        printf("Enter a number (0 to stop): ");
        if (scanf("%d", &n) != 1) break;
        if (n == 0) break;
        printf("You entered: %d\n", n);
    }
    printf("Loop terminated.\n");
    return 0;
}
