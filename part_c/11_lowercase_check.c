/*
 * q11: Lowercase letter check.
 * A letter in 'a'..'z' is lowercase.
 */
#include <stdio.h>

int main(void) {
    char ch;
    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) return 1;

    if (ch >= 'a' && ch <= 'z')
        printf("Lowercase letter\n");
    else
        printf("Not a lowercase letter\n");
    return 0;
}
