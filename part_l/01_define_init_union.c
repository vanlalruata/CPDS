/* part_l/q1.c
 * Define and initialize a union.
 * A union is like a struct but all members share the same memory location.
 * Here we define a union with three members and initialize it.
 */
#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main(void) {
    union Data d;
    d.i = 65;            /* initialize by writing the int member */
    printf("Initialized union via int member: %d\n", d.i);
    printf("Same memory interpreted as char: %c\n", d.c);
    return 0;
}
