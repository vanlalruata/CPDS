/* part_k / q26: Create an employee management system (add/display/search). */
#include <stdio.h>

#define MAX 100

typedef struct {
    int empId;
    char name[40];
    float salary;
} Employee;

int main(void) {
    Employee e[MAX];
    int n = 0, i, key, choice, found;
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            if (n >= MAX) { printf("Full.\n"); continue; }
            printf("id name salary: ");
            scanf("%d %39s %f", &e[n].empId, e[n].name, &e[n].salary);
            n++;
        } else if (choice == 2) {
            for (i = 0; i < n; i++) printf("%d %s %.2f\n", e[i].empId, e[i].name, e[i].salary);
        } else if (choice == 3) {
            found = 0;
            printf("Enter id: ");
            scanf("%d", &key);
            for (i = 0; i < n; i++)
                if (e[i].empId == key) { printf("%d %s %.2f\n", e[i].empId, e[i].name, e[i].salary); found = 1; }
            if (!found) printf("Not found.\n");
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
