/* part_k / q7: Input and display an employee structure. */
#include <stdio.h>

typedef struct {
    int empId;
    char name[40];
    float salary;
} Employee;

int main(void) {
    Employee e;
    printf("Enter id name salary: ");
    if (scanf("%d %39s %f", &e.empId, e.name, &e.salary) != 3) return 1;
    printf("ID: %d\nName: %s\nSalary: %.2f\n", e.empId, e.name, e.salary);
    return 0;
}
