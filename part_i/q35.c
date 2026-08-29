/* q35.c - Array of structure pointers.
 * Concept: An array whose elements are pointers to structures.  Each
 *          slot can point at a different record, and the records can be
 *          reordered simply by swapping pointers (cheap - no copying).
 * Compile: gcc q35.c -o q35
 */
#include <stdio.h>

#define MAXS 20

struct Student {
    int   roll;
    char  name[30];
    float marks;
};

int main(void)
{
    struct Student list[MAXS];
    struct Student *ptrs[MAXS];      /* array of pointers */
    struct Student *tmp;
    int n, i, j;

    printf("How many students (1-%d)? ", MAXS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAXS) { printf("Invalid count.\n"); return 1; }

    for (i = 0; i < n; i++) {
        printf("Student %d - roll, name(one word), marks: ", i + 1);
        scanf("%d %29s %f", &list[i].roll, list[i].name, &list[i].marks);
        ptrs[i] = &list[i];          /* store the address */
    }

    printf("\nRecords through the array of pointers:\n");
    for (i = 0; i < n; i++)
        printf("%-5d %-15s %.2f\n", ptrs[i]->roll, ptrs[i]->name, ptrs[i]->marks);

    /* sort by marks (descending) by swapping POINTERS only */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (ptrs[j]->marks > ptrs[i]->marks) {
                tmp = ptrs[i];
                ptrs[i] = ptrs[j];
                ptrs[j] = tmp;
            }

    printf("\nRanking (sorted by marks, only pointers were swapped):\n");
    for (i = 0; i < n; i++)
        printf("%d. %-15s %.2f (roll %d)\n",
               i + 1, ptrs[i]->name, ptrs[i]->marks, ptrs[i]->roll);

    printf("\nThe original array order is unchanged: ");
    for (i = 0; i < n; i++) printf("%s ", list[i].name);
    printf("\n");

    return 0;
}
