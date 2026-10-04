/* part_g q16: Pass an array to a function and display its elements. */
#include <stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) if (scanf("%d", &arr[i]) != 1) return 1;
    printf("Array elements: ");
    display(arr, n);
    return 0;
}
