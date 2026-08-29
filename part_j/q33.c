/* part_j / q33: Sort dynamically allocated student records by marks (descending). */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll;
    int marks;
} Student;

int main(void) {
    int n, i, j;
    Student tmp;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student *s = (Student *)malloc((size_t)n * sizeof(Student));
    if (!s) return 1;
    for (i = 0; i < n; i++) {
        printf("Student %d (roll marks): ", i);
        scanf("%d %d", &s[i].roll, &s[i].marks);
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (s[j].marks < s[j + 1].marks) {
                tmp = s[j]; s[j] = s[j + 1]; s[j + 1] = tmp;
            }
    printf("Sorted by marks (desc):\n");
    for (i = 0; i < n; i++) printf("%d %d\n", s[i].roll, s[i].marks);
    free(s);
    return 0;
}
