/* part_k / q14: Sort students according to name (case-sensitive strcmp). */
#include <stdio.h>
#include <string.h>

typedef struct {
    int roll;
    char name[40];
} Student;

int main(void) {
    int n, i, j;
    Student s[100], tmp;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    for (i = 0; i < n; i++) {
        printf("Student %d (roll name): ", i);
        scanf("%d %39s", &s[i].roll, s[i].name);
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (strcmp(s[j].name, s[j + 1].name) > 0) {
                tmp = s[j]; s[j] = s[j + 1]; s[j + 1] = tmp;
            }
    for (i = 0; i < n; i++) printf("%d %s\n", s[i].roll, s[i].name);
    return 0;
}
