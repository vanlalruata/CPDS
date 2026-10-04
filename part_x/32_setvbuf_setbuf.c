/* setvbuf / setbuf: open a file with _IONBF, _IOLBF, _IOFBF and demonstrate. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "buf.txt";

    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    if (setvbuf(fp, NULL, _IONBF, 0) != 0) { perror("setvbuf IONBF"); fclose(fp); return EXIT_FAILURE; }
    fputs("_IONBF unbuffered\n", fp);
    fclose(fp);

    fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    char lbbuf[128];
    if (setvbuf(fp, lbbuf, _IOLBF, sizeof lbbuf) != 0) { perror("setvbuf IOLBF"); fclose(fp); return EXIT_FAILURE; }
    fputs("_IOLBF line buffered line1\n", fp);
    fputs("line2 (no flush yet)\n", fp);
    fclose(fp);

    fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    char fbbuf[4096];
    if (setvbuf(fp, fbbuf, _IOFBF, sizeof fbbuf) != 0) { perror("setvbuf IOFBF"); fclose(fp); return EXIT_FAILURE; }
    fputs("_IOFBF fully buffered\n", fp);
    fclose(fp);

    printf("Wrote three files demonstrating IONBF, IOLBF, IOFBF.\n");
    return EXIT_SUCCESS;
}