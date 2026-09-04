/* Merge two files into a third by concatenating contents. */
#include <stdio.h>
#include <stdlib.h>

static void write_sample(const char *name, const char *data) {
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs(data, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *f1 = argc > 1 ? argv[1] : "file1.txt";
    const char *f2 = argc > 2 ? argv[2] : "file2.txt";
    const char *fm = argc > 3 ? argv[3] : "merged.txt";

    write_sample(f1, "Content from file one.\n");
    write_sample(f2, "Content from file two.\n");

    FILE *m = fopen(fm, "w");
    if (!m) { perror(fm); return EXIT_FAILURE; }
    char buf[1024]; size_t n;
    FILE *in;
    in = fopen(f1, "r"); if (!in) { perror(f1); fclose(m); return EXIT_FAILURE; }
    while ((n = fread(buf, 1, sizeof buf, in)) > 0) fwrite(buf, 1, n, m);
    fclose(in);
    in = fopen(f2, "r"); if (!in) { perror(f2); fclose(m); return EXIT_FAILURE; }
    while ((n = fread(buf, 1, sizeof buf, in)) > 0) fwrite(buf, 1, n, m);
    fclose(in);
    fclose(m);

    printf("Merged %s + %s -> %s\n", f1, f2, fm);
    return EXIT_SUCCESS;
}