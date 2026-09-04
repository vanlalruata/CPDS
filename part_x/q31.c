/* fflush: write to a file, flush, then read it back from disk to confirm. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "flush.txt";
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    fputs("flushed line\n", fp);
    if (fflush(fp) != 0) { perror("fflush"); fclose(fp); return EXIT_FAILURE; }
    fclose(fp);

    fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    char buf[64];
    if (fgets(buf, sizeof buf, fp)) printf("Read back: %s", buf);
    fclose(fp);
    return EXIT_SUCCESS;
}