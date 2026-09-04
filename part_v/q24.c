/*
 * Program: q24.c
 * Dynamically allocates an array of strings (char **) using malloc plus strcpy,
 * reads N strings, displays them, then frees each string and the pointer array.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 128

int main(void) {
    int n;
    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid count\n");
        return 1;
    }
    getchar();

    char **strs = malloc((size_t)n * sizeof(char *));
    if (strs == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    char buf[MAX_LEN];
    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            fprintf(stderr, "Read error\n");
            for (int k = 0; k < i; k++) free(strs[k]);
            free(strs);
            return 1;
        }
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';

        strs[i] = malloc(strlen(buf) + 1);
        if (strs[i] == NULL) {
            fprintf(stderr, "malloc failed\n");
            for (int k = 0; k < i; k++) free(strs[k]);
            free(strs);
            return 1;
        }
        strcpy(strs[i], buf);
    }

    printf("\nStored strings:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] %s\n", i, strs[i]);
    }

    for (int i = 0; i < n; i++) {
        free(strs[i]);
    }
    free(strs);
    return 0;
}