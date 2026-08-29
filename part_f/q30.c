/* part_f q30: Student result program using separate functions. */
#include <stdio.h>

typedef struct {
    char name[50];
    int marks[5];
} Student;

int total(Student s) {
    int t = 0;
    for (int i = 0; i < 5; i++) t += s.marks[i];
    return t;
}

double percentage(Student s) {
    return (double)total(s) / 5;
}

int isPass(Student s) {
    for (int i = 0; i < 5; i++)
        if (s.marks[i] < 40) return 0;
    return 1;
}

int main(void) {
    Student s;
    printf("Enter name: ");
    if (scanf("%49s", s.name) != 1) return 1;
    printf("Enter marks of 5 subjects: ");
    for (int i = 0; i < 5; i++)
        if (scanf("%d", &s.marks[i]) != 1) return 1;
    printf("\nName: %s\n", s.name);
    printf("Total: %d\n", total(s));
    printf("Percentage: %.2f\n", percentage(s));
    printf("Result: %s\n", isPass(s) ? "PASS" : "FAIL");
    return 0;
}
