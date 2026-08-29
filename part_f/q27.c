/* part_f q27: Function to calculate average of an array. */
#include <stdio.h>

double average(int arr[], int n);

double average(int arr[], int n) {
    long s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return (double)s / n;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1) return 1;
    printf("Average = %.2f\n", average(arr, n));
    return 0;
}
