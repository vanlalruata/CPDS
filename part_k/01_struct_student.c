/* part_k / q1: Define a structure for a student. */
#include <stdio.h>

typedef struct {
    int roll;
    char name[40];
    int marks;
} Student;

int main(void) {
    Student s = { 1, "Alice", 90 };
    printf("%d %s %d\n", s.roll, s.name, s.marks);
    return 0;
}
