/* Demonstrate ungetc: read a char, push back, read again. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("ABC", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    int c1 = fgetc(fp);
    if (c1 == EOF) { fclose(fp); return EXIT_FAILURE; }
    if (ungetc(c1, fp) == EOF) { perror("ungetc"); fclose(fp); return EXIT_FAILURE; }
    int c2 = fgetc(fp);
    printf("Read: %c, pushed back, re-read: %c\n", (char)c1, (char)c2);
    fclose(fp);
    return EXIT_SUCCESS;
}