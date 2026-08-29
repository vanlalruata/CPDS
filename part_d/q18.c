/* q18.c - Print 1 to 100 but skip multiples of 5 using continue */
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 100; i++) {
        if (i % 5 == 0) continue;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
