/* part_t/q2.c — Dynamic Student Management System
 * Concepts: structure, pointer, malloc/realloc, functions
 * Grows number of students dynamically as needed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student *addStudent(struct Student *list, int *n) {
    list = realloc(list, (*n + 1) * sizeof(struct Student));
    if (!list) { printf("Memory error.\n"); exit(1); }
    printf("Enter roll, name, marks: ");
    scanf("%d %49s %f", &list[*n].roll, list[*n].name, &list[*n].marks);
    (*n)++;
    return list;
}

void display(struct Student *list, int n) {
    for (int i = 0; i < n; i++)
        printf("%d %s %.2f\n", list[i].roll, list[i].name, list[i].marks);
}

int main(void) {
    struct Student *list = NULL;
    int n = 0, ch;
    do {
        printf("\n1.Add 2.Display 3.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) list = addStudent(list, &n);
        else if (ch == 2) display(list, n);
    } while (ch != 3);
    free(list);
    return 0;
}
