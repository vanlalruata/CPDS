/* Read chars from stdin with getchar until '#', echo with putchar. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Type chars (terminate with #):\n");
    int ch;
    long n = 0;
    while ((ch = getchar()) != EOF && ch != '#') {
        putchar(ch);
        n++;
    }
    putchar("\n"[0]);
    printf("Echoed %ld chars.\n", n);
    return EXIT_SUCCESS;
}