/* part_g q4: Function with no arguments and a return value. */
#include <stdio.h>

int getNumber(void) {
    return 42;
}

int main(void) {
    int n = getNumber();
    printf("The function returned: %d\n", n);
    return 0;
}
