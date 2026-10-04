/* rename: rename old.txt to new.txt using rename(). */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *oldn = argc > 1 ? argv[1] : "old.txt";
    const char *newn = argc > 2 ? argv[2] : "new.txt";
    FILE *fp = fopen(oldn, "w");
    if (fp) { fputs("to be renamed\n", fp); fclose(fp); }
    if (rename(oldn, newn) == 0) printf("Renamed %s -> %s\n", oldn, newn);
    else { perror("rename"); return EXIT_FAILURE; }
    return EXIT_SUCCESS;
}