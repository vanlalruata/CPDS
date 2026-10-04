/* Print the size of a file in bytes using fseek/ftell. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    FILE *fp = fopen(name, "rb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    if (fseek(fp, 0, SEEK_END) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    long sz = ftell(fp);
    fclose(fp);
    if (sz < 0) { perror("ftell"); return EXIT_FAILURE; }
    printf("%s: %ld bytes\n", name, sz);
    return EXIT_SUCCESS;
}