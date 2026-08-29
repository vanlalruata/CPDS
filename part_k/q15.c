/* part_k / q15: Sort employees according to salary (descending). */
#include <stdio.h>

typedef struct {
    int empId;
    float salary;
} Employee;

int main(void) {
    int n, i, j;
    Employee e[100], tmp;
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    for (i = 0; i < n; i++) {
        printf("Employee %d (id salary): ", i);
        scanf("%d %f", &e[i].empId, &e[i].salary);
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (e[j].salary < e[j + 1].salary) {
                tmp = e[j]; e[j] = e[j + 1]; e[j + 1] = tmp;
            }
    for (i = 0; i < n; i++) printf("%d %.2f\n", e[i].empId, e[i].salary);
    return 0;
}
