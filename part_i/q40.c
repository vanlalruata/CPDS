/* q40.c - Dynamically allocate and manipulate student records.
 * Concept: Combine malloc with structures: allocate an array of
 *          structs at run time, fill it through a pointer, compute
 *          results, then free the block.
 * Compile: gcc q40.c -o q40
 */
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int   roll;
    char  name[30];
    float marks[3];
    float total;
    float average;
};

int main(void)
{
    struct Student *s;
    int n, i, j;
    int best = 0;

    printf("How many student records? ");
    if (scanf("%d", &n) != 1 || n < 1) { printf("Invalid count.\n"); return 1; }

    s = (struct Student *) malloc((size_t) n * sizeof(struct Student));
    if (s == NULL) { printf("Memory allocation failed.\n"); return 1; }

    printf("Allocated %lu bytes for %d record(s) at %p\n",
           (unsigned long) ((size_t) n * sizeof(struct Student)), n, (void *) s);

    for (i = 0; i < n; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("  Roll number: ");
        scanf("%d", &(s + i)->roll);
        printf("  Name (one word): ");
        scanf("%29s", (s + i)->name);
        printf("  Marks of 3 subjects: ");
        (s + i)->total = 0.0f;
        for (j = 0; j < 3; j++) {
            scanf("%f", &(s + i)->marks[j]);
            (s + i)->total += (s + i)->marks[j];
        }
        (s + i)->average = (s + i)->total / 3.0f;
    }

    printf("\n%-6s %-15s %-8s %-8s %-8s %-8s %-8s %s\n",
           "Roll", "Name", "M1", "M2", "M3", "Total", "Avg", "Result");
    for (i = 0; i < n; i++) {
        printf("%-6d %-15s %-8.1f %-8.1f %-8.1f %-8.1f %-8.2f %s\n",
               s[i].roll, s[i].name,
               s[i].marks[0], s[i].marks[1], s[i].marks[2],
               s[i].total, s[i].average,
               (s[i].average >= 40.0f) ? "PASS" : "FAIL");
        if (s[i].total > s[best].total) best = i;
    }

    printf("\nTopper: %s (roll %d) with total %.1f and average %.2f\n",
           s[best].name, s[best].roll, s[best].total, s[best].average);

    free(s);
    s = NULL;
    printf("Dynamic student records freed.\n");

    return 0;
}
