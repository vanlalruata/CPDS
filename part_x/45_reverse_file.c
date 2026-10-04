/* Reverse the contents of a file: read all chars, reverse in memory, write back. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "reverse.txt";
    FILE *fp = fopen(name, "rb+");
    if (!fp) { perror(name); return EXIT_FAILURE; }

    if (fseek(fp, 0, SEEK_END) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    long sz = ftell(fp);
    if (sz <= 0) { fclose(fp); printf("File empty.\n"); return EXIT_SUCCESS; }

    unsigned char *buf = malloc((size_t)sz);
    if (!buf) { perror("malloc"); fclose(fp); return EXIT_FAILURE; }
    rewind(fp);
    if (fread(buf, 1, (size_t)sz, fp) != (size_t)sz) { perror("fread"); free(buf); fclose(fp); return EXIT_FAILURE; }

    for (long i = 0, j = sz - 1; i < j; ++i, --j) {
        unsigned char t = buf[i]; buf[i] = buf[j]; buf[j] = t;
    }
    rewind(fp);
    if (fwrite(buf, 1, (size_t)sz, fp) != (size_t)sz) { perror("fwrite"); free(buf); fclose(fp); return EXIT_FAILURE; }
    free(buf); fclose(fp);
    printf("Reversed %ld bytes in %s\n", sz, name);
    return EXIT_SUCCESS;
}