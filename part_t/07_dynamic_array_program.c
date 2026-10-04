/* part_t/q7.c — Dynamic Array Program
 * Concepts: malloc/realloc
 * Operations: create, insert, delete, search, sort, display
 */
#include <stdio.h>
#include <stdlib.h>

int *insert(int *a, int *n, int pos, int val) {
    a = realloc(a, (*n + 1) * sizeof(int));
    for (int i = *n; i > pos; i--) a[i] = a[i-1];
    a[pos] = val; (*n)++;
    return a;
}

int *del(int *a, int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) a[i] = a[i+1];
    (*n)--; a = realloc(a, *n * sizeof(int));
    return a;
}

int search(int *a, int n, int val) {
    for (int i = 0; i < n; i++) if (a[i] == val) return i;
    return -1;
}

void sortArr(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) { int t = a[i]; a[i] = a[j]; a[j] = t; }
}

void display(int *a, int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int *a = NULL, n = 0, ch, pos, val, idx;
    do {
        printf("\n1.Insert 2.Delete 3.Search 4.Sort 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("pos, val: "); scanf("%d %d", &pos, &val); a = insert(a, &n, pos, val); break;
            case 2: printf("pos: "); scanf("%d", &pos); a = del(a, &n, pos); break;
            case 3: printf("val: "); scanf("%d", &val); idx = search(a, n, val);
                    printf(idx < 0 ? "Not found\n" : "Found at %d\n", idx); break;
            case 4: sortArr(a, n); break;
            case 5: display(a, n); break;
        }
    } while (ch != 6);
    free(a);
    return 0;
}
