/*
 * q10: Uppercase letter check.
 * A letter in 'A'..'Z' is uppercase.
 */
#include <stdio.h>

int main(void) {
    char ch;
    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) return 1;

    if (ch >= 'A' && ch <= 'Z')
        printf("Uppercase letter\n");
    else
        printf("Not an uppercase letter\n");
    return 0;
}
