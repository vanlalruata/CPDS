/* q30.c - Print a pyramid pattern using * (5 rows)
        *
       ***
      *****
     *******
    ********* */
#include <stdio.h>

int main(void) {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}
