/* fgetpos and fsetpos: save a position, seek elsewhere, then restore it. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("abcdefghij\nklmnopqrst\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }

    fpos_t pos;
    if (fgetpos(fp, &pos) != 0) { perror("fgetpos"); fclose(fp); return EXIT_FAILURE; }
    printf("Saved position.\n");

    if (fseek(fp, 10, SEEK_SET) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    printf("After seek 10, next char: %c\n", (char)fgetc(fp));

    if (fsetpos(fp, &pos) != 0) { perror("fsetpos"); fclose(fp); return EXIT_FAILURE; }
    printf("After restore, next char: %c\n", (char)fgetc(fp));

    fclose(fp);
    return EXIT_SUCCESS;
}