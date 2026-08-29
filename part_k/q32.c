/* part_k / q32: Compare two structure variables (member-wise). */
#include <stdio.h>
#include <string.h>

typedef struct {
    int roll;
    int marks;
} Student;

int main(void) {
    Student a = { 1, 90 };
    Student b = { 1, 90 };
    int equal = (a.roll == b.roll) && (a.marks == b.marks);
    printf("Structures are %s\n", equal ? "equal" : "not equal");
    return 0;
}
