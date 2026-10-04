/* part_j / q34: Find topper from dynamically allocated student records. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll;
    char name[30];
    int marks;
} Student;

int main(void) {
    int n, i, top = 0;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student *s = (Student *)malloc((size_t)n * sizeof(Student));
    if (!s) return 1;
    for (i = 0; i < n; i++) {
        printf("Student %d (roll name marks): ", i);
        scanf("%d %29s %d", &s[i].roll, s[i].name, &s[i].marks);
    }
    for (i = 1; i < n; i++)
        if (s[i].marks > s[top].marks) top = i;
    printf("Topper: %d %s %d\n", s[top].roll, s[top].name, s[top].marks);
    free(s);
    return 0;
}
