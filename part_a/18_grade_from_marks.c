/*
 * q18: Grade of a student from marks.
 * Maps percentage to grade A/B/C/D/F.
 *
 * Flowchart:
 * +-------+
 * | START |
 * +-------+
 *     |
 *     v
 * +------------------+
 * | read marks (0-100)
 * +------------------+
 *     |
 *     v
 * +-------------------+
 * | >=90 A | >=80 B   |
 * | >=70 C | >=60 D   |
 * | else F           |
 * +-------------------+
 *     |
 *     v
 * +-------------------+
 * | print grade       |
 * +-------------------+
 *     |
 *     v
 * +-------+
 * | STOP  |
 * +-------+
 */
#include <stdio.h>

int main(void) {
    int m;
    printf("Enter marks (0-100): ");
    if (scanf("%d", &m) != 1 || m < 0 || m > 100) return 1;

    char g;
    if (m >= 90) g = 'A';
    else if (m >= 80) g = 'B';
    else if (m >= 70) g = 'C';
    else if (m >= 60) g = 'D';
    else g = 'F';

    printf("Grade: %c\n", g);
    return 0;
}
