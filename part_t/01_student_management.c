/* part_t/q1.c — Student Management System
 * Concepts: structure, array, functions, pointers
 * Operations: Add, Display, Search, Find Topper, Sort (by marks)
 */
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent(struct Student *s, int *n) {
    printf("Enter roll, name, marks: ");
    scanf("%d %49s %f", &s[*n].roll, s[*n].name, &s[*n].marks);
    (*n)++;
}

void displayStudents(struct Student *s, int n) {
    printf("Roll\tName\tMarks\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
}

void searchStudent(struct Student *s, int n, int roll) {
    for (int i = 0; i < n; i++)
        if (s[i].roll == roll) {
            printf("Found: %d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
            return;
        }
    printf("Not found.\n");
}

void findTopper(struct Student *s, int n) {
    if (n == 0) { printf("No students.\n"); return; }
    int top = 0;
    for (int i = 1; i < n; i++)
        if (s[i].marks > s[top].marks) top = i;
    printf("Topper: %d %s %.2f\n", s[top].roll, s[top].name, s[top].marks);
}

void sortStudents(struct Student *s, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].marks < s[j].marks) {
                struct Student t = s[i]; s[i] = s[j]; s[j] = t;
            }
    printf("Sorted by marks.\n");
}

int main(void) {
    struct Student s[MAX];
    int n = 0, ch, roll;
    do {
        printf("\n1.Add 2.Display 3.Search 4.Topper 5.Sort 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addStudent(s, &n); break;
            case 2: displayStudents(s, n); break;
            case 3: printf("Roll to search: "); scanf("%d", &roll);
                    searchStudent(s, n, roll); break;
            case 4: findTopper(s, n); break;
            case 5: sortStudents(s, n); break;
        }
    } while (ch != 6);
    return 0;
}
