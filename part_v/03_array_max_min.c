/* part_v/q3.c — Array maximum/minimum */
#include <stdio.h>

int main(void) {
    int n, a[100], max, min;
    printf("Number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    max = min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    printf("Max = %d, Min = %d\n", max, min);
    return 0;
}
