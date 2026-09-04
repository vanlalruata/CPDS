/* Count chars, words, and lines in a file (wc-like). */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("Hello world\nThis is C\nFile I/O demo\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    long chars = 0, words = 0, lines = 0;
    int in_word = 0, ch;
    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (isspace((unsigned char)ch)) { in_word = 0; }
        else if (!in_word) { in_word = 1; words++; }
    }
    fclose(fp);
    printf("chars=%ld words=%ld lines=%ld\n", chars, words, lines);
    return EXIT_SUCCESS;
}