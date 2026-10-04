/* feof: read a file in a loop using the correct pattern (read then check feof). */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("abc", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }

    int ch;
    long n = 0;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
        n++;
    }
    if (feof(fp))   printf("\nEnd of file reached after %ld chars.\n", n);
    else if (ferror(fp)) printf("\nRead error.\n");

    clearerr(fp);
    rewind(fp);
    int c2 = fgetc(fp);
    printf("After clearerr+rewind, next char: %c\n", (char)c2);

    fclose(fp);
    return EXIT_SUCCESS;
}