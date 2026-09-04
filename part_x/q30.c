/* clearerr: after triggering an error, call clearerr and show flags are reset. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    fputs("hello\n", fp);
    fclose(fp);

    fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    fputc('X', fp);
    printf("After bad write: ferror=%d\n", ferror(fp));

    clearerr(fp);
    printf("After clearerr:   ferror=%d feof=%d\n", ferror(fp), feof(fp));
    fclose(fp);
    return EXIT_SUCCESS;
}