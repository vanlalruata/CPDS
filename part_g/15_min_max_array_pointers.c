/* part_g q15: Find minimum and maximum of an array via pointer parameters. */
#include <stdio.h>

void arrMinMax(int arr[], int n, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) if (scanf("%d", &arr[i]) != 1) return 1;
    int mn, mx;
    arrMinMax(arr, n, &mn, &mx);
    printf("Minimum = %d, Maximum = %d\n", mn, mx);
    return 0;
}
