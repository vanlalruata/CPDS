/* Command-line file processor: argv[1] filename; print char/word/line counts. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) { fprintf(stderr, "Usage: %s <file>\n", argv[0]); return EXIT_FAILURE; }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) { perror(argv[1]); return EXIT_FAILURE; }
    long chars = 0, words = 0, lines = 0;
    int in_word = 0, ch;
    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (isspace((unsigned char)ch)) in_word = 0;
        else if (!in_word) { in_word = 1; words++; }
    }
    fclose(fp);
    printf("%s: chars=%ld words=%ld lines=%ld\n", argv[1], chars, words, lines);
    return EXIT_SUCCESS;
}