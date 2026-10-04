/* part_k / q8: Create an array of students. */
#include <stdio.h>

typedef struct {
    int roll;
    char name[40];
    int marks;
} Student;

int main(void) {
    int n, i;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student s[100];
    for (i = 0; i < n && i < 100; i++) {
        printf("Student %d (roll name marks): ", i);
        scanf("%d %39s %d", &s[i].roll, s[i].name, &s[i].marks);
    }
    for (i = 0; i < n; i++)
        printf("%d %s %d\n", s[i].roll, s[i].name, s[i].marks);
    return 0;
}
