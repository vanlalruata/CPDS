/* part_g q18: Pass an array to a function and search for an element. */
#include <stdio.h>

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
    for (int i = 0; i < n; i++) if (scanf("%d", &arr[i]) != 1) return 1;
    printf("Enter element to search: ");
    if (scanf("%d", &key) != 1) return 1;
    int pos = search(arr, n, key);
    if (pos == -1) printf("Not found\n");
    else printf("Found at index %d\n", pos);
    return 0;
}
