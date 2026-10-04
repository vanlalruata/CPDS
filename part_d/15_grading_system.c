/* q15.c - Grading system using switch (based on marks 0-100) */
#include <stdio.h>

int main(void) {
    int marks;
    printf("Enter marks (0-100): ");
    scanf("%d", &marks);
    if (marks < 0 || marks > 100) { printf("Invalid marks\n"); return 1; }
    switch (marks / 10) {
        case 10:
        case 9:  printf("Grade: A+\n"); break;
        case 8:  printf("Grade: A\n"); break;
        case 7:  printf("Grade: B\n"); break;
        case 6:  printf("Grade: C\n"); break;
        case 5:  printf("Grade: D\n"); break;
        default: printf("Grade: F (Fail)\n");
    }
    return 0;
}
