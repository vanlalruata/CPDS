/* Read a file line-by-line with fgets and print each line. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("line one\nline two\nline three\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    char buf[256];
    long n = 0;
    while (fgets(buf, sizeof buf, fp)) {
        printf("%s", buf);
        n++;
    }
    fclose(fp);
    printf("--- %ld line(s) printed ---\n", n);
    return EXIT_SUCCESS;
}