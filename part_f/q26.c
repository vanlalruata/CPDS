/* part_f q26: Function to reverse an array. */
#include <stdio.h>

void reverseArray(int arr[], int n);

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int t = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1) return 1;
    reverseArray(arr, n);
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
