/* q39.c - Dynamically create an array of strings using char ** and malloc.
 * Concept: char **names is an array of char pointers; each element gets
 *          its own malloc'ed character buffer.  Free every string and
 *          then the pointer array.
 * Compile: gcc q39.c -o q39
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

int main(void)
{
    char **names;
    int n, i, j;
    char buffer[LEN];

    printf("How many strings? ");
    if (scanf("%d", &n) != 1 || n < 1) { printf("Invalid count.\n"); return 1; }

    names = (char **) malloc((size_t) n * sizeof(char *));
    if (names == NULL) { printf("Allocation failed.\n"); return 1; }

    printf("Enter %d strings (one word each):\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%49s", buffer) != 1) { strcpy(buffer, "unknown"); }

        names[i] = (char *) malloc(strlen(buffer) + 1);   /* +1 for '\0' */
        if (names[i] == NULL) {
            printf("Allocation failed for string %d.\n", i);
            for (j = 0; j < i; j++) free(names[j]);
            free(names);
            return 1;
        }
        strcpy(names[i], buffer);
    }

    printf("\n%-4s %-20s %-8s %s\n", "No", "String", "Length", "Address");
    for (i = 0; i < n; i++)
        printf("%-4d %-20s %-8lu %p\n",
               i + 1, names[i], (unsigned long) strlen(names[i]), (void *) names[i]);

    /* sort the strings alphabetically by swapping pointers */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (strcmp(names[i], names[j]) > 0) {
                char *t = names[i];
                names[i] = names[j];
                names[j] = t;
            }

    printf("\nStrings in alphabetical order:\n");
    for (i = 0; i < n; i++) printf("%s\n", names[i]);

    for (i = 0; i < n; i++) free(names[i]);   /* free each string */
    free(names);                              /* then the array */
    printf("\nMemory released.\n");

    return 0;
}
