/* part_l/q9.c
 * Student-related union.
 * A student identifier may be stored either as a numeric id (int) or as a
 * single-letter grade code (char). Using a union saves memory when only one
 * representation is needed at a time.
 */
#include <stdio.h>

union StudentId {
    int number;
    char code;
};

int main(void) {
    union StudentId s;
    s.number = 1024;
    printf("Student number: %d\n", s.number);
    s.code = 'A';  /* now reuse the same memory for grade code */
    printf("Grade code: %c\n", s.code);
    return 0;
}
