/* part_k / q20: Demonstrate nested structures (struct Date inside struct Employee). */
#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int empId;
    char name[40];
    Date joinDate;
} Employee;

int main(void) {
    Employee e;
    printf("Enter id name and join date (d m y): ");
    if (scanf("%d %39s %d %d %d", &e.empId, e.name,
              &e.joinDate.day, &e.joinDate.month, &e.joinDate.year) != 5) return 1;
    printf("ID=%d Name=%s Joined=%d/%d/%d\n",
           e.empId, e.name, e.joinDate.day, e.joinDate.month, e.joinDate.year);
    return 0;
}
