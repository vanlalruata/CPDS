/* part_k / q18: Pass a structure pointer to a function. */
#include <stdio.h>

typedef struct {
    int roll;
    int marks;
} Student;

void update(Student *s, int m) {
    s->marks = m;
}

int main(void) {
    Student s = { 3, 50 };
    update(&s, 80);
    printf("Roll=%d Marks=%d\n", s.roll, s.marks);
    return 0;
}
