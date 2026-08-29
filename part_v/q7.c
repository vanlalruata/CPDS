/* part_v/q7.c — Pointer-based swap */
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int main(void) {
    int x, y;
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);
    printf("Before: x=%d y=%d\n", x, y);
    swap(&x, &y);
    printf("After:  x=%d y=%d\n", x, y);
    return 0;
}
