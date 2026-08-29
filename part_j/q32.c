/* part_j / q32: Search student records dynamically by roll number. */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll;
    char name[30];
    int marks;
} Student;

int main(void) {
    int n, i, key, found = 0;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student *s = (Student *)malloc((size_t)n * sizeof(Student));
    if (!s) return 1;
    for (i = 0; i < n; i++) {
        printf("Student %d (roll name marks): ", i);
        scanf("%d %29s %d", &s[i].roll, s[i].name, &s[i].marks);
    }
    printf("Enter roll to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (s[i].roll == key) {
            printf("Found: %d %s %d\n", s[i].roll, s[i].name, s[i].marks);
            found = 1;
        }
    }
    if (!found) printf("Student not found.\n");
    free(s);
    return 0;
}
