/* part_k / q11: Search a student by roll number. */
#include <stdio.h>

typedef struct {
    int roll;
    char name[40];
    int marks;
} Student;

int main(void) {
    int n, i, key, found = 0;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Student s[100];
    for (i = 0; i < n && i < 100; i++) {
        printf("Student %d (roll name marks): ", i);
        scanf("%d %39s %d", &s[i].roll, s[i].name, &s[i].marks);
    }
    printf("Enter roll to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
        if (s[i].roll == key) {
            printf("Found: %d %s %d\n", s[i].roll, s[i].name, s[i].marks);
            found = 1;
        }
    if (!found) printf("Not found.\n");
    return 0;
}
