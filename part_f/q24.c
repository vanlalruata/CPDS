/* part_f q24: Function to search an element in an array (returns index or -1). */
#include <stdio.h>

int search(int arr[], int n, int key);

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int main(void) {
    int n, key;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    int arr[100];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1) return 1;
    printf("Enter element to search: ");
    if (scanf("%d", &key) != 1) return 1;
    int pos = search(arr, n, key);
    if (pos == -1)
        printf("Element %d not found\n", key);
    else
        printf("Element %d found at index %d\n", key, pos);
    return 0;
}
