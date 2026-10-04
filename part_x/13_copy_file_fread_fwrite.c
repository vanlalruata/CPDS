/* Copy file via fread/fwrite using a 1024-byte buffer; report bytes copied. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "wb");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("Block copy with fread/fwrite.\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *src = argc > 1 ? argv[1] : "sample.txt";
    const char *dst = argc > 2 ? argv[2] : "copy.txt";
    ensure_sample(src);
    FILE *in = fopen(src, "rb");
    if (!in) { perror(src); return EXIT_FAILURE; }
    FILE *out = fopen(dst, "wb");
    if (!out) { perror(dst); fclose(in); return EXIT_FAILURE; }
    char buf[1024];
    size_t n;
    long total = 0;
    while ((n = fread(buf, 1, sizeof buf, in)) > 0) {
        if (fwrite(buf, 1, n, out) != n) { perror("fwrite"); fclose(in); fclose(out); return EXIT_FAILURE; }
        total += (long)n;
    }
    fclose(in); fclose(out);
    printf("Copied %ld bytes from %s to %s\n", total, src, dst);
    return EXIT_SUCCESS;
}