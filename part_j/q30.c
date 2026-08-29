/* part_j / q30: Dynamically allocate an array of structures using malloc(). */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll;
    int marks;
} Student;

int main(void) {
    int n, i;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student *s = (Student *)malloc((size_t)n * sizeof(Student));
    if (!s) return 1;
    for (i = 0; i < n; i++) {
        printf("Student %d roll and marks: ", i);
        scanf("%d %d", &s[i].roll, &s[i].marks);
    }
    for (i = 0; i < n; i++)
        printf("roll=%d marks=%d\n", s[i].roll, s[i].marks);
    free(s);
    return 0;
}
