/* q16.c - Repeatedly accept a choice until user chooses Exit
   Loop + switch; break on exit. */
#include <stdio.h>

int main(void) {
    int choice;
    while (1) {
        printf("\n--- Loop Menu ---\n");
        printf("1. Hello\n2. Date (sample)\n3. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: printf("Hello, world!\n"); break;
            case 2: printf("Today is a good day.\n"); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid\n");
        }
        if (choice == 3) break;
    }
    return 0;
}
