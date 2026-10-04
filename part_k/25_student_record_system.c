/* part_k / q25: Create a student record system (add/display/search). */
#include <stdio.h>

#define MAX 100

typedef struct {
    int roll;
    char name[40];
    int marks;
} Student;

int main(void) {
    Student s[MAX];
    int n = 0, i, key, choice, found;
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            if (n >= MAX) { printf("Full.\n"); continue; }
            printf("roll name marks: ");
            scanf("%d %39s %d", &s[n].roll, s[n].name, &s[n].marks);
            n++;
        } else if (choice == 2) {
            for (i = 0; i < n; i++) printf("%d %s %d\n", s[i].roll, s[i].name, s[i].marks);
        } else if (choice == 3) {
            found = 0;
            printf("Enter roll: ");
            scanf("%d", &key);
            for (i = 0; i < n; i++)
                if (s[i].roll == key) { printf("%d %s %d\n", s[i].roll, s[i].name, s[i].marks); found = 1; }
            if (!found) printf("Not found.\n");
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
