/* Write chars A..E to out.txt using fputc. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "out.txt";
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    for (char c = 'A'; c <= 'E'; ++c) {
        if (fputc(c, fp) == EOF) { perror("fputc"); fclose(fp); return EXIT_FAILURE; }
    }
    fclose(fp);
    printf("Wrote A..E to %s\n", name);
    return EXIT_SUCCESS;
}