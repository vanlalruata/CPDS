/* Read entire file into dynamically allocated buffer using fseek/ftell+malloc+fread. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    FILE *fp = fopen(name, "rb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    if (fseek(fp, 0, SEEK_END) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    long sz = ftell(fp);
    if (sz < 0) { perror("ftell"); fclose(fp); return EXIT_FAILURE; }
    rewind(fp);

    char *buf = malloc((size_t)sz + 1);
    if (!buf) { perror("malloc"); fclose(fp); return EXIT_FAILURE; }
    size_t n = fread(buf, 1, (size_t)sz, fp);
    buf[n] = '\0';
    fclose(fp);

    printf("Read %zu/%ld bytes:\n%s\n", n, sz, buf);
    free(buf);
    return EXIT_SUCCESS;
}