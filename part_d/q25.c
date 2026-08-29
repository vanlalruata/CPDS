/* q25.c - Menu-driven array operations (insert, delete, search, display) */
#include <stdio.h>

int main(void) {
    int a[100], n = 0, choice, pos, val, i, found;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter position (1-based) and value: ");
                scanf("%d %d", &pos, &val);
                if (pos < 1 || pos > n + 1) { printf("Invalid position\n"); break; }
                for (i = n; i >= pos; i--) a[i] = a[i - 1];
                a[pos - 1] = val;
                n++;
                break;
            case 2:
                printf("Enter position (1-based): ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n) { printf("Invalid position\n"); break; }
                for (i = pos - 1; i < n - 1; i++) a[i] = a[i + 1];
                n--;
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                found = 0;
                for (i = 0; i < n; i++) if (a[i] == val) { printf("Found at %d\n", i + 1); found = 1; }
                if (!found) printf("Not found\n");
                break;
            case 4:
                printf("Array: ");
                for (i = 0; i < n; i++) printf("%d ", a[i]);
                printf("\n");
                break;
            case 5: break;
            default: printf("Invalid\n");
        }
    } while (choice != 5);
    return 0;
}
