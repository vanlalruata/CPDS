/* q19.c - Print 1 to 100 except even numbers using continue */
#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) continue;
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
