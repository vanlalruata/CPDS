/* part_f q28: Function to count even and odd elements in an array. */
#include <stdio.h>

void countEvenOdd(int arr[], int n, int *even, int *odd);

void countEvenOdd(int arr[], int n, int *even, int *odd) {
    *even = *odd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) (*even)++;
        else (*odd)++;
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
    int even, odd;
    countEvenOdd(arr, n, &even, &odd);
    printf("Even = %d, Odd = %d\n", even, odd);
    return 0;
}
