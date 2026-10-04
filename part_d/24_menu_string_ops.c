/* q24.c - Menu-driven string operations (length, reverse, copy, compare) */
#include <stdio.h>
#include <string.h>

int main(void) {
    int choice;
    char s1[100], s2[100], s3[100];
    printf("Enter a string: ");
    scanf(" %99[^\n]", s1);
    do {
        printf("\n1. Length\n2. Reverse\n3. Copy\n4. Compare(to s2)\n5. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Length = %lu\n", strlen(s1));
                break;
            case 2: {
                int n = strlen(s1);
                for (int i = n - 1; i >= 0; i--) putchar(s1[i]);
                printf("\n");
                break;
            }
            case 3:
                strcpy(s3, s1);
                printf("Copied: %s\n", s3);
                break;
            case 4:
                printf("Enter second string: ");
                scanf(" %99[^\n]", s2);
                if (strcmp(s1, s2) == 0) printf("Strings are equal\n");
                else printf("Strings are not equal\n");
                break;
            case 5: break;
            default: printf("Invalid\n");
        }
    } while (choice != 5);
    return 0;
}
