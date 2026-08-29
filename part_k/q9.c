/* part_k / q9: Find the student with the highest marks. */
#include <stdio.h>

typedef struct {
    int roll;
    int marks;
} Student;

int main(void) {
    int n, i, top = 0;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student s[100];
    for (i = 0; i < n && i < 100; i++) {
        printf("Student %d (roll marks): ", i);
        scanf("%d %d", &s[i].roll, &s[i].marks);
    }
    for (i = 1; i < n; i++)
        if (s[i].marks > s[top].marks) top = i;
    printf("Top student: roll=%d marks=%d\n", s[top].roll, s[top].marks);
    return 0;
}
