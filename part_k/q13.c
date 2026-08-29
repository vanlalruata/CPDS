/* part_k / q13: Sort students according to marks (ascending). */
#include <stdio.h>

typedef struct {
    int roll;
    int marks;
} Student;

int main(void) {
    int n, i, j;
    Student s[100], tmp;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    for (i = 0; i < n; i++) {
        printf("Student %d (roll marks): ", i);
        scanf("%d %d", &s[i].roll, &s[i].marks);
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (s[j].marks > s[j + 1].marks) {
                tmp = s[j]; s[j] = s[j + 1]; s[j + 1] = tmp;
            }
    for (i = 0; i < n; i++) printf("%d %d\n", s[i].roll, s[i].marks);
    return 0;
}
