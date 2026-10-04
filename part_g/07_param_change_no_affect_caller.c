/* part_g q7: Shows why changing a parameter does not change the original variable. */
#include <stdio.h>

void modify(int p) {
    printf("Inside function before change: p = %d\n", p);
    p = 999;
    printf("Inside function after  change: p = %d\n", p);
}

int main(void) {
    int x = 10;
    printf("Original before call: x = %d\n", x);
    modify(x);
    printf("Original after  call: x = %d (unmodified)\n", x);
    return 0;
}
