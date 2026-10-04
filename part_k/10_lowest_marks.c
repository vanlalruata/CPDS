/* part_k / q10: Find the student with the lowest marks. */
#include <stdio.h>

typedef struct {
    int roll;
    int marks;
} Student;

int main(void) {
    int n, i, low = 0;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student s[100];
    for (i = 0; i < n && i < 100; i++) {
        printf("Student %d (roll marks): ", i);
        scanf("%d %d", &s[i].roll, &s[i].marks);
    }
    for (i = 1; i < n; i++)
        if (s[i].marks < s[low].marks) low = i;
    printf("Lowest student: roll=%d marks=%d\n", s[low].roll, s[low].marks);
    return 0;
}
