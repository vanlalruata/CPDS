/* CSV reader: read data.csv, split by commas, print as a table. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("id,name,age\n1,Alice,30\n2,Bob,25\n3,Carol,28\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "data.csv";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    char line[1024]; long row = 0;
    while (fgets(line, sizeof line, fp)) {
        row++;
        size_t len = strlen(line);
        if (len && line[len-1] == '\n') line[len-1] = '\0';
        printf("Row %ld: |", row);
        char *tok = strtok(line, ",");
        while (tok) {
            printf(" %-12s |", tok);
            tok = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(fp);
    return EXIT_SUCCESS;
}