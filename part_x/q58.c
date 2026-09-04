/* Hex dump: read a file in binary, print 16 bytes per row as hex + ASCII. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "wb");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("The quick brown fox jumps over the lazy dog.", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "dump.bin";
    ensure_sample(name);
    FILE *fp = fopen(name, "rb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    unsigned char buf[16];
    size_t n; long off = 0;
    while ((n = fread(buf, 1, sizeof buf, fp)) > 0) {
        printf("%08lx  ", off);
        for (size_t i = 0; i < 16; ++i) {
            if (i < n) printf("%02x ", buf[i]); else printf("   ");
            if (i == 7) printf(" ");
        }
        printf(" |");
        for (size_t i = 0; i < n; ++i) putchar(isprint(buf[i]) ? buf[i] : '.');
        printf("|\n");
        off += (long)n;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}