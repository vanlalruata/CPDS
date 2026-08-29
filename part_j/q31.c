/* part_j / q31: Input student records using dynamic allocation. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll;
    char name[30];
    int marks;
} Student;

int main(void) {
    int n, i;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student *s = (Student *)malloc((size_t)n * sizeof(Student));
    if (!s) return 1;
    for (i = 0; i < n; i++) {
        printf("Student %d (roll name marks): ", i);
        scanf("%d %29s %d", &s[i].roll, s[i].name, &s[i].marks);
    }
    printf("Records:\n");
    for (i = 0; i < n; i++)
        printf("%d %s %d\n", s[i].roll, s[i].name, s[i].marks);
    free(s);
    return 0;
}
