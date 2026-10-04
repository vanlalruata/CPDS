/* q37.c - Pointer arithmetic with an array of structures.
 * Concept: p++ on a struct pointer advances by sizeof(struct), so a
 *          struct array can be walked exactly like an int array.
 * Compile: gcc q37.c -o q37
 */
#include <stdio.h>

#define MAXE 20

struct Employee {
    int   id;
    char  name[30];
    float salary;
};

int main(void)
{
    struct Employee emp[MAXE];
    struct Employee *p, *end;
    int n, i;
    double total = 0.0;

    printf("How many employees (1-%d)? ", MAXE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXE) { printf("Invalid count.\n"); return 1; }

    for (i = 0; i < n; i++) {
        printf("Employee %d - id, name(one word), salary: ", i + 1);
        scanf("%d %29s %f", &emp[i].id, emp[i].name, &emp[i].salary);
    }

    end = emp + n;                        /* one past the last record */

    printf("\n%-6s %-15s %-12s %s\n", "Id", "Name", "Salary", "Address");
    for (p = emp; p < end; p++) {         /* pointer arithmetic */
        printf("%-6d %-15s %-12.2f %p\n", p->id, p->name, p->salary, (void *) p);
        total += p->salary;
    }

    printf("\nsizeof(struct Employee) = %lu bytes\n",
           (unsigned long) sizeof(struct Employee));
    printf("Distance between record 0 and record %d = %ld bytes\n",
           n - 1, (long) ((char *) (emp + n - 1) - (char *) emp));
    printf("Total salary = %.2f, average = %.2f\n", total, total / n);

    /* highest paid, found with a pointer */
    p = emp;
    for (end = emp + 1; end < emp + n; end++)
        if (end->salary > p->salary) p = end;
    printf("Highest paid: %s (%.2f), index %ld\n",
           p->name, p->salary, (long) (p - emp));

    return 0;
}
