/* part_l/q10.c
 * Employee-related union.
 * An employee's compensation may be an hourly wage (float) or a fixed
 * salary (int). We store only one at a time via a union.
 */
#include <stdio.h>

union Pay {
    int salary;
    float wage;
};

int main(void) {
    union Pay p;
    p.salary = 50000;
    printf("Salary: %d\n", p.salary);
    p.wage = 25.5f;
    printf("Hourly wage: %.2f\n", p.wage);
    return 0;
}
