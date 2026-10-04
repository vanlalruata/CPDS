/* Copy one file to another char by char using fgetc/fputc. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("Source content for char-copy.\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *src = argc > 1 ? argv[1] : "sample.txt";
    const char *dst = argc > 2 ? argv[2] : "copy.txt";
    ensure_sample(src);
    FILE *in = fopen(src, "r");
    if (!in) { perror(src); return EXIT_FAILURE; }
    FILE *out = fopen(dst, "w");
    if (!out) { perror(dst); fclose(in); return EXIT_FAILURE; }
    int ch;
    while ((ch = fgetc(in)) != EOF) fputc(ch, out);
    fclose(in); fclose(out);
    printf("Copied %s -> %s\n", src, dst);
    return EXIT_SUCCESS;
}