/* part_f q23: Function to calculate sum of array elements. */
#include <stdio.h>

long sumArray(int arr[], int n);

long sumArray(int arr[], int n) {
    long s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1) return 1;
    printf("Sum = %ld\n", sumArray(arr, n));
    return 0;
}
