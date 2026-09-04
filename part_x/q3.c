/* Read chars via fgetc until EOF and count total characters. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("The quick brown fox jumps over the lazy dog.\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    long count = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF) count++;
    fclose(fp);
    printf("Total chars in %s: %ld\n", name, count);
    return EXIT_SUCCESS;
}