/* Read first char of a file using fgetc and print it. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("Hello, World!\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    int ch = fgetc(fp);
    if (ch == EOF) { printf("%s is empty\n", name); fclose(fp); return EXIT_SUCCESS; }
    printf("First char of %s: %c\n", name, (char)ch);
    fclose(fp);
    return EXIT_SUCCESS;
}