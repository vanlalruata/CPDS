/* part_j / q5: Allocate an array of characters (string) using malloc().
   Reads a line (single word) and prints it. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n = 100;
    char *str = (char *)malloc((size_t)n * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Enter a string: ");
    if (scanf("%99s", str) != 1) {
        free(str);
        return 1;
    }
    printf("You entered: %s (length=%zu)\n", str, strlen(str));
    free(str);
    return 0;
}
