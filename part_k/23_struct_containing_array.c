/* part_k / q23: Create a structure containing an array (marks[5]). */
#include <stdio.h>

typedef struct {
    int roll;
    int marks[5];
} Student;

int main(void) {
    int i;
    Student s;
    printf("Enter roll and 5 marks: ");
    if (scanf("%d", &s.roll) != 1) return 1;
    for (i = 0; i < 5; i++) scanf("%d", &s.marks[i]);
    printf("Roll=%d Marks: ", s.roll);
    for (i = 0; i < 5; i++) printf("%d ", s.marks[i]);
    printf("\n");
    return 0;
}
