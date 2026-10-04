/* part_t/q27.c — Dynamic Student Records + Sorting
 * Dynamically allocate students; sort by roll, marks, name.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main(void) {
    int n, ch, i, j;
    printf("Number of students: "); scanf("%d", &n);
    struct Student *s = malloc(n * sizeof(struct Student));
    for (i = 0; i < n; i++) { printf("roll name marks: "); scanf("%d %49s %f", &s[i].roll, s[i].name, &s[i].marks); }
    do {
        printf("\n1.Sort by roll 2.Sort by marks 3.Sort by name 4.Display 5.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) for (i = 0; i < n - 1; i++) for (j = i + 1; j < n; j++) if (s[i].roll > s[j].roll) { struct Student t = s[i]; s[i] = s[j]; s[j] = t; }
        else if (ch == 2) for (i = 0; i < n - 1; i++) for (j = i + 1; j < n; j++) if (s[i].marks < s[j].marks) { struct Student t = s[i]; s[i] = s[j]; s[j] = t; }
        else if (ch == 3) for (i = 0; i < n - 1; i++) for (j = i + 1; j < n; j++) if (strcmp(s[i].name, s[j].name) > 0) { struct Student t = s[i]; s[i] = s[j]; s[j] = t; }
        else if (ch == 4) for (i = 0; i < n; i++) printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    } while (ch != 5);
    free(s);
    return 0;
}
