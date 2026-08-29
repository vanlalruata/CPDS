/* part_k / q16: Pass a structure to a function (by value). */
#include <stdio.h>

typedef struct {
    int roll;
    int marks;
} Student;

void display(Student s) {
    printf("Roll=%d Marks=%d\n", s.roll, s.marks);
}

int main(void) {
    Student s = { 5, 88 };
    display(s);
    return 0;
}
