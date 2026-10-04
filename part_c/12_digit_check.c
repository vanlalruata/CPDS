/*
 * q12: Digit check.
 * A character '0'..'9' is a digit.
 */
#include <stdio.h>

int main(void) {
    char ch;
    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) return 1;

    if (ch >= '0' && ch <= '9')
        printf("Digit\n");
    else
        printf("Not a digit\n");
    return 0;
}
