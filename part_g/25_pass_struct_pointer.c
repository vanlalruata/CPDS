/* part_g q25: Pass a pointer to a structure to a function (call by reference). */
#include <stdio.h>

typedef struct {
    int id;
    char name[30];
    float salary;
} Employee;

void giveRaise(Employee *e, float pct) {
    e->salary += e->salary * pct / 100;
}

void printEmp(const Employee *e) {
    printf("ID: %d, Name: %s, Salary: %.2f\n", e->id, e->name, e->salary);
}

int main(void) {
    Employee emp;
    printf("Enter id, name, salary: ");
    if (scanf("%d %29s %f", &emp.id, emp.name, &emp.salary) != 3) return 1;
    float pct;
    printf("Enter raise percentage: ");
    if (scanf("%f", &pct) != 1) return 1;
    giveRaise(&emp, pct);
    printf("Updated employee:\n");
    printEmp(&emp);
    return 0;
}
