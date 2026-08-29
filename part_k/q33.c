/* part_k / q33: Copy one structure into another (assignment copies members). */
#include <stdio.h>
#include <string.h>

typedef struct {
    int roll;
    char name[40];
    int marks;
} Student;

int main(void) {
    Student a = { 5, "Alice", 95 };
    Student b;
    b = a;   /* direct structure assignment copies all members */
    printf("Copy: %d %s %d\n", b.roll, b.name, b.marks);
    return 0;
}
