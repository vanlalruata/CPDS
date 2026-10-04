/* part_f q22: Function to find largest element in an array. */
#include <stdio.h>

int largest(int arr[], int n);

int largest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1) return 1;
    printf("Largest element = %d\n", largest(arr, n));
    return 0;
}
