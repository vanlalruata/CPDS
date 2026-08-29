/* part_t/q30.c — Complete Student Record Data Structure
 * struct Student{int roll; char name[50]; float marks;}
 * Menu: 1.Insert 2.Delete 3.Search 4.Update 5.Sort 6.Display 7.Find topper 8.Exit
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student { int roll; char name[50]; float marks; };

int main(void) {
    struct Student *s = NULL; int n = 0, ch, i, roll, found;
    do {
        printf("\n1.Insert 2.Delete 3.Search 4.Update 5.Sort 6.Display 7.Topper 8.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            s = realloc(s, (n + 1) * sizeof(struct Student));
            printf("roll name marks: "); scanf("%d %49s %f", &s[n].roll, s[n].name, &s[n].marks); n++;
        } else if (ch == 2) {
            printf("roll to delete: "); scanf("%d", &roll); found = 0;
            for (i = 0; i < n; i++) if (s[i].roll == roll) { found = 1; for (int j = i; j < n - 1; j++) s[j] = s[j+1]; n--; s = realloc(s, n * sizeof(struct Student)); printf("Deleted.\n"); break; }
            if (!found) printf("Not found.\n");
        } else if (ch == 3) {
            printf("roll: "); scanf("%d", &roll); found = 0;
            for (i = 0; i < n; i++) if (s[i].roll == roll) { printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks); found = 1; break; }
            if (!found) printf("Not found.\n");
        } else if (ch == 4) {
            printf("roll to update: "); scanf("%d", &roll); found = 0;
            for (i = 0; i < n; i++) if (s[i].roll == roll) { printf("new name marks: "); scanf("%49s %f", s[i].name, &s[i].marks); found = 1; break; }
            if (!found) printf("Not found.\n");
        } else if (ch == 5) {
            for (i = 0; i < n - 1; i++) for (int j = i + 1; j < n; j++) if (s[i].roll > s[j].roll) { struct Student t = s[i]; s[i] = s[j]; s[j] = t; }
        } else if (ch == 6) {
            for (i = 0; i < n; i++) printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
        } else if (ch == 7) {
            if (n == 0) printf("None.\n");
            else { int top = 0; for (i = 1; i < n; i++) if (s[i].marks > s[top].marks) top = i; printf("Topper: %d %s %.2f\n", s[top].roll, s[top].name, s[top].marks); }
        }
    } while (ch != 8);
    free(s);
    return 0;
}
