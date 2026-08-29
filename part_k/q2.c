/* part_k / q2: Define a structure for an employee. */
#include <stdio.h>

typedef struct {
    int empId;
    char name[40];
    float salary;
} Employee;

int main(void) {
    Employee e = { 101, "Bob", 45000.0f };
    printf("%d %s %.2f\n", e.empId, e.name, e.salary);
    return 0;
}
