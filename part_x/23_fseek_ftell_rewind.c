/* fseek, ftell, rewind: print file size, seek to a position, rewind and read first line. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "r");
    if (fp) { fclose(fp); return; }
    fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("First line\nSecond line\nThird line\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    ensure_sample(name);
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }

    if (fseek(fp, 0, SEEK_END) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    long sz = ftell(fp);
    printf("File size: %ld bytes\n", sz);

    if (fseek(fp, 6, SEEK_SET) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    printf("Position after seek to 6: %ld\n", ftell(fp));

    rewind(fp);
    printf("Position after rewind: %ld\n", ftell(fp));
    char buf[64];
    if (fgets(buf, sizeof buf, fp)) printf("First line: %s", buf);

    fclose(fp);
    return EXIT_SUCCESS;
}