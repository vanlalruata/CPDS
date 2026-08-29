/* part_k / q17: Return a structure from a function. */
#include <stdio.h>

typedef struct {
    int roll;
    int marks;
} Student;

Student makeStudent(int r, int m) {
    Student s;
    s.roll = r;
    s.marks = m;
    return s;
}

int main(void) {
    Student s = makeStudent(7, 91);
    printf("Roll=%d Marks=%d\n", s.roll, s.marks);
    return 0;
}
