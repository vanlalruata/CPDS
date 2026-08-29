/* part_t/q12.c — Sparse Matrix efficient representation
 * Concepts: store only non-zero entries with row, col, value
 */
#include <stdio.h>
#include <stdlib.h>

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, n;       /* n = number of non-zero entries */
    struct Element *e;
};

struct Sparse readSparse(int r, int c) {
    struct Sparse s; s.rows = r; s.cols = c; s.n = 0;
    printf("Enter %dx%d matrix:\n", r, c);
    int v;
    struct Element tmp[100];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            scanf("%d", &v);
            if (v != 0) { tmp[s.n].row = i; tmp[s.n].col = j; tmp[s.n].val = v; s.n++; }
        }
    s.e = malloc(s.n * sizeof(struct Element));
    for (int i = 0; i < s.n; i++) s.e[i] = tmp[i];
    return s;
}

void displaySparse(struct Sparse s) {
    printf("Row Col Val\n");
    for (int i = 0; i < s.n; i++) printf("%d   %d   %d\n", s.e[i].row, s.e[i].col, s.e[i].val);
}

int main(void) {
    int r, c;
    printf("Rows and cols: ");
    scanf("%d %d", &r, &c);
    struct Sparse s = readSparse(r, c);
    printf("Non-zero entries: %d\n", s.n);
    displaySparse(s);
    free(s.e);
    return 0;
}
