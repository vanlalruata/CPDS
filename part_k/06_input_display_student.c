/* part_k / q6: Input and display a student structure. */
#include <stdio.h>

typedef struct {
    int roll;
    char name[40];
    int marks;
} Student;

int main(void) {
    Student s;
    printf("Enter roll name marks: ");
    if (scanf("%d %39s %d", &s.roll, s.name, &s.marks) != 3) return 1;
    printf("Roll: %d\nName: %s\nMarks: %d\n", s.roll, s.name, s.marks);
    return 0;
}
