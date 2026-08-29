/* part_g q6: Swap two numbers using ordinary (value) arguments.
   Note: changes inside the function do NOT affect the caller's variables. */
#include <stdio.h>

void swapValue(int a, int b) {
    int t = a; a = b; b = t;
    printf("Inside function: a=%d b=%d\n", a, b);
}

int main(void) {
    int x = 5, y = 10;
    printf("Before call: x=%d y=%d\n", x, y);
    swapValue(x, y);
    printf("After call : x=%d y=%d (unchanged!)\n", x, y);
    return 0;
}
