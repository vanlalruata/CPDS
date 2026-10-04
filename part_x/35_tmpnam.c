/* tmpnam: generate a temporary filename and write to it (portability warning). */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char name[L_tmpnam];
    if (!tmpnam(name)) { perror("tmpnam"); return EXIT_FAILURE; }
    printf("Generated temp name: %s\n", name);

    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    fputs("data via tmpnam\n", fp);
    fclose(fp);
    remove(name);
    return EXIT_SUCCESS;
}