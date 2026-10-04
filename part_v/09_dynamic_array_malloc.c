/* part_v/q9.c — Dynamic array using malloc() */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, *a, i;
    printf("Number of elements: ");
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    if (!a) return 1;
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("You entered: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
