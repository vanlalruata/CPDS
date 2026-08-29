/* part_v/q4.c — Linear search */
#include <stdio.h>

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int main(void) {
    int n, a[100], key, pos;
    printf("Number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Key to search: ");
    scanf("%d", &key);
    pos = linearSearch(a, n, key);
    printf(pos < 0 ? "Not found\n" : "Found at index %d\n", pos);
    return 0;
}
