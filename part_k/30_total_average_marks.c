/* part_k / q30: Calculate total marks and average using a student structure. */
#include <stdio.h>

typedef struct {
    int roll;
    int marks[5];
} Student;

int main(void) {
    int i, total = 0;
    Student s;
    printf("Enter roll and 5 marks: ");
    if (scanf("%d", &s.roll) != 1) return 1;
    for (i = 0; i < 5; i++) {
        scanf("%d", &s.marks[i]);
        total += s.marks[i];
    }
    printf("Total=%d Average=%.2f\n", total, total / 5.0);
    return 0;
}
