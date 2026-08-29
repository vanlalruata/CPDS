/* part_v/q8.c — Structure-based student record */
#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main(void) {
    struct Student s;
    printf("Enter roll, name, marks: ");
    scanf("%d %49s %f", &s.roll, s.name, &s.marks);
    printf("Roll: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
    return 0;
}
