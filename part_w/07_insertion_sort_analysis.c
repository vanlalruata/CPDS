/* q7: Insertion sort comparison counts for best/avg/worst cases. */
#include <stdio.h>

long insertion_cmp;

void insertion(int *a, int n) {
    insertion_cmp = 0;
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            insertion_cmp++;
            if (a[j] > key) { a[j + 1] = a[j]; j--; }
            else break;
        }
        a[j + 1] = key;
    }
}

void print_arr(const int *a, int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int sorted[]  = {1,2,3,4,5,6,7,8};
    int average[] = {4,1,7,3,8,2,6,5};
    int reverse[] = {8,7,6,5,4,3,2,1};
    int n = 8;

    insertion(sorted, n);
    printf("Best (sorted):    cmp=%ld\n", insertion_cmp);

    insertion(average, n);
    printf("Average:          cmp=%ld\n", insertion_cmp);

    insertion(reverse, n);
    printf("Worst (reversed): cmp=%ld\n", insertion_cmp);

    printf("\nBest O(n), Average/Worst O(n^2).\n");
    return 0;
}