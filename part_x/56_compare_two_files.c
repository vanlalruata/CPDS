/* Compare two files char by char (diff-like); print first difference or "identical". */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name, const char *data) {
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs(data, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *a = argc > 1 ? argv[1] : "a.txt";
    const char *b = argc > 2 ? argv[2] : "b.txt";

    if (argc < 3) {
        ensure_sample(a, "Same content.\nLine two.\n");
        ensure_sample(b, "Same content.\nLine two!\n");
    }

    FILE *fa = fopen(a, "rb"); if (!fa) { perror(a); return EXIT_FAILURE; }
    FILE *fb = fopen(b, "rb"); if (!fb) { perror(b); fclose(fa); return EXIT_FAILURE; }

    long pos = 0; int ca, cb;
    while ((ca = fgetc(fa)) != EOF && (cb = fgetc(fb)) != EOF) {
        if (ca != cb) {
            printf("Differ at byte %ld: 0x%02X vs 0x%02X\n", pos, (unsigned char)ca, (unsigned char)cb);
            fclose(fa); fclose(fb);
            return EXIT_FAILURE;
        }
        pos++;
    }
    int ea = (ca == EOF), eb = (cb == EOF);
    fclose(fa); fclose(fb);
    if (ea && eb) { puts("Identical."); return EXIT_SUCCESS; }
    printf("Length differs at byte %ld\n", pos);
    return EXIT_FAILURE;
}