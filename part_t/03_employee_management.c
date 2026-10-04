/* part_t/q3.c — Employee Management System
 * Concepts: array of structures
 * Operations: Add, Delete, Search, Sort (by salary), Display
 */
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmp(struct Employee *e, int *n) {
    printf("id, name, salary: ");
    scanf("%d %49s %f", &e[*n].id, e[*n].name, &e[*n].salary);
    (*n)++;
}

void deleteEmp(struct Employee *e, int *n, int id) {
    for (int i = 0; i < *n; i++)
        if (e[i].id == id) {
            for (int j = i; j < *n - 1; j++) e[j] = e[j+1];
            (*n)--; printf("Deleted.\n"); return;
        }
    printf("Not found.\n");
}

void searchEmp(struct Employee *e, int n, int id) {
    for (int i = 0; i < n; i++)
        if (e[i].id == id) { printf("%d %s %.2f\n", e[i].id, e[i].name, e[i].salary); return; }
    printf("Not found.\n");
}

void sortEmp(struct Employee *e, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (e[i].salary < e[j].salary) { struct Employee t = e[i]; e[i] = e[j]; e[j] = t; }
}

void display(struct Employee *e, int n) {
    for (int i = 0; i < n; i++) printf("%d %s %.2f\n", e[i].id, e[i].name, e[i].salary);
}

int main(void) {
    struct Employee e[MAX]; int n = 0, ch, id;
    do {
        printf("\n1.Add 2.Delete 3.Search 4.Sort 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addEmp(e, &n); break;
            case 2: printf("id to delete: "); scanf("%d", &id); deleteEmp(e, &n, id); break;
            case 3: printf("id to search: "); scanf("%d", &id); searchEmp(e, n, id); break;
            case 4: sortEmp(e, n); break;
            case 5: display(e, n); break;
        }
    } while (ch != 6);
    return 0;
}
