/* part_j / q29: Dynamically allocate one structure with malloc(). */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float salary;
} Employee;

int main(void) {
    Employee *e = (Employee *)malloc(sizeof(Employee));
    if (!e) return 1;
    e->id = 1;
    e->salary = 50000.0f;
    printf("Employee id=%d salary=%.2f\n", e->id, e->salary);
    free(e);
    return 0;
}
