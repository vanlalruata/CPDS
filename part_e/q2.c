/* q2.c - Print numbers from N to 1 */
#include <stdio.h>

int main(void) {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) printf("%d ", i);
    printf("\n");
    return 0;
}
