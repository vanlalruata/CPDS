/* q1.c - Print numbers from 1 to N */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) printf("%d ", i);
    printf("\n");
    return 0;
}
