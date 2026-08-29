/* part_m/q22.c
 * COMPARE BUBBLE, SELECTION AND INSERTION SORT (step counts)
 *
 * ALGORITHM STEPS:
 * 1. Copy the same array into three buffers.
 * 2. Run each sort, counting key comparison/assignment steps.
 * 3. Print the step counts for comparison.
 *
 * All three sorts TIME COMPLEXITY: O(n^2)
 * AUXILIARY SPACE: O(1)
 */
#include <stdio.h>

#define N 6

void bubble(int a[], int n, long *steps) {
    *steps = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++) {
            (*steps)++;
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t; (*steps)++;
            }
        }
}

void selection(int a[], int n, long *steps) {
    *steps = 0;
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            (*steps)++;
            if (a[j] < a[m]) m = j;
        }
        int t = a[i]; a[i] = a[m]; a[m] = t; (*steps)++;
    }
}

void insertion(int a[], int n, long *steps) {
    *steps = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            (*steps)++;
            if (a[j] > key) { a[j+1] = a[j]; j--; (*steps)++; }
            else break;
        }
        a[j+1] = key;
    }
}

int main(void) {
    int base[] = {64, 25, 12, 22, 11, 90};
    int a[N], b[N], c[N];
    long s1, s2, s3;
    for (int i = 0; i < N; i++) { a[i]=b[i]=c[i]=base[i]; }
    bubble(a, N, &s1);
    selection(b, N, &s2);
    insertion(c, N, &s3);
    printf("Bubble sort steps   : %ld\n", s1);
    printf("Selection sort steps: %ld\n", s2);
    printf("Insertion sort steps: %ld\n", s3);
    return 0;
}
