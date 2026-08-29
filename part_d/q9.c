/* q9.c - Menu-driven student result program
   Enter marks of 3 subjects; menu lets you view total/avg/result. */
#include <stdio.h>

int main(void) {
    int m1, m2, m3, choice;
    float total, avg;
    printf("Enter marks of 3 subjects: ");
    scanf("%d %d %d", &m1, &m2, &m3);
    total = m1 + m2 + m3;
    avg = total / 3;
    do {
        printf("\n--- Student Result ---\n");
        printf("1. Total\n2. Average\n3. Result (Pass/Fail)\n4. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: printf("Total = %.2f\n", total); break;
            case 2: printf("Average = %.2f\n", avg); break;
            case 3:
                if (m1 >= 35 && m2 >= 35 && m3 >= 35)
                    printf("Result = PASS\n");
                else
                    printf("Result = FAIL\n");
                break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
