/* part_k / q19: Use -> to access structure members via a pointer. */
#include <stdio.h>

typedef struct {
    int roll;
    float gpa;
} Student;

int main(void) {
    Student s = { 9, 3.7f };
    Student *p = &s;
    printf("Roll=%d GPA=%.2f\n", p->roll, p->gpa);
    return 0;
}
