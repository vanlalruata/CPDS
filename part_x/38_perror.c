/* perror: try to open a non-existent file and show "No such file or directory: ..." */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "definitely_missing_file.txt";
    FILE *fp = fopen(name, "r");
    if (!fp) {
        perror(name);
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}