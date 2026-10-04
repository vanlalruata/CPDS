/* Append data to an existing file using "a" mode. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "append.txt";
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    fputs("first line\n", fp);
    fclose(fp);

    fp = fopen(name, "a");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    fputs("appended line\n", fp);
    fclose(fp);

    fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    char buf[128];
    while (fgets(buf, sizeof buf, fp)) printf("%s", buf);
    fclose(fp);
    return EXIT_SUCCESS;
}