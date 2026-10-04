/* part_g q24: Pass a structure to a function (call by value). */
#include <stdio.h>

typedef struct {
    int id;
    char name[30];
    float salary;
} Employee;

void printEmp(Employee e) {
    printf("ID: %d, Name: %s, Salary: %.2f\n", e.id, e.name, e.salary);
}

int main(void) {
    Employee emp;
    printf("Enter id, name, salary: ");
    if (scanf("%d %29s %f", &emp.id, emp.name, &emp.salary) != 3) return 1;
    printEmp(emp);
    return 0;
}
