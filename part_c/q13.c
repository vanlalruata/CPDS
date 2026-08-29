/*
 * q13: Vowel or consonant.
 * Checks an alphabet letter against a,e,i,o,u (case-insensitive).
 */
#include <stdio.h>

int main(void) {
    char ch;
    printf("Enter a letter: ");
    if (scanf(" %c", &ch) != 1) return 1;

    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        printf("Vowel\n");
    else if (ch >= 'a' && ch <= 'z')
        printf("Consonant\n");
    else
        printf("Not a letter\n");
    return 0;
}
