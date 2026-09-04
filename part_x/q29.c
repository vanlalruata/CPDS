/* ferror: trigger a write to a read-only stream and report via ferror. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "sample.txt";
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    fputs("data\n", fp);
    fclose(fp);

    fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    if (fputs("attempt write to read-only stream\n", fp) == EOF) {
        printf("fputs failed (expected).\n");
        if (ferror(fp)) {
            perror("ferror reports");
            printf("errno=%d (%s)\n", errno, strerror(errno));
        }
    }
    clearerr(fp);
    printf("After clearerr, ferror=%d\n", ferror(fp));
    fclose(fp);
    return EXIT_SUCCESS;
}