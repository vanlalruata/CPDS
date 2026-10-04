/* Write two strings to a file using fputs. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "out.txt";
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    if (fputs("First line via fputs.\n", fp) == EOF) { perror("fputs"); fclose(fp); return EXIT_FAILURE; }
    if (fputs("Second line via fputs.\n", fp) == EOF) { perror("fputs"); fclose(fp); return EXIT_FAILURE; }
    fclose(fp);
    printf("Wrote 2 lines to %s\n", name);
    return EXIT_SUCCESS;
}