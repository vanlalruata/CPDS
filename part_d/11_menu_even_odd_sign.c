/* q11.c - Menu-driven even/odd and positive/negative check */
#include <stdio.h>

int main(void) {
    int choice, n;
    do {
        printf("\n--- Number Check ---\n");
        printf("1. Even/Odd\n2. Positive/Negative/Zero\n3. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 3) break;
        printf("Enter a number: ");
        scanf("%d", &n);
        switch (choice) {
            case 1:
                if (n % 2 == 0) printf("%d is EVEN\n", n);
                else printf("%d is ODD\n", n);
                break;
            case 2:
                if (n > 0) printf("%d is POSITIVE\n", n);
                else if (n < 0) printf("%d is NEGATIVE\n", n);
                else printf("ZERO\n");
                break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 3);
    return 0;
}
