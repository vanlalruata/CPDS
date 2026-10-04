/* part_k / q12: Search an employee by employee ID. */
#include <stdio.h>

typedef struct {
    int empId;
    char name[40];
    float salary;
} Employee;

int main(void) {
    int n, i, key, found = 0;
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    Employee e[100];
    for (i = 0; i < n && i < 100; i++) {
        printf("Employee %d (id name salary): ", i);
        scanf("%d %39s %f", &e[i].empId, e[i].name, &e[i].salary);
    }
    printf("Enter employee ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
        if (e[i].empId == key) {
            printf("Found: %d %s %.2f\n", e[i].empId, e[i].name, e[i].salary);
            found = 1;
        }
    if (!found) printf("Not found.\n");
    return 0;
}
