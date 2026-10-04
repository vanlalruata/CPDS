/* part_k / q31: Find highest and lowest salary using employee structures. */
#include <stdio.h>

typedef struct {
    int empId;
    float salary;
} Employee;

int main(void) {
    int n, i, hi = 0, lo = 0;
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Employee e[100];
    for (i = 0; i < n && i < 100; i++) {
        printf("Employee %d (id salary): ", i);
        scanf("%d %f", &e[i].empId, &e[i].salary);
    }
    for (i = 1; i < n; i++) {
        if (e[i].salary > e[hi].salary) hi = i;
        if (e[i].salary < e[lo].salary) lo = i;
    }
    printf("Highest: %d %.2f\nLowest: %d %.2f\n",
           e[hi].empId, e[hi].salary, e[lo].empId, e[lo].salary);
    return 0;
}
