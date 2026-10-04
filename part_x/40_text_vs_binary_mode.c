/* Text vs binary mode: write same data with fprintf vs fwrite, read both back. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *text = argc > 1 ? argv[1] : "text_mode.txt";
    const char *bin  = argc > 2 ? argv[2] : "bin_mode.bin";

    FILE *ft = fopen(text, "w");
    if (!ft) { perror(text); return EXIT_FAILURE; }
    fprintf(ft, "Line1\n");
    fclose(ft);

    FILE *fb = fopen(bin, "wb");
    if (!fb) { perror(bin); return EXIT_FAILURE; }
    const char *data = "Line1\n";
    fwrite(data, 1, strlen(data), fb);
    fclose(fb);

    ft = fopen(text, "r"); if (!ft) { perror(text); return EXIT_FAILURE; }
    char tbuf[32]; fgets(tbuf, sizeof tbuf, ft); fclose(ft);
    fb = fopen(bin, "rb"); if (!fb) { perror(bin); return EXIT_FAILURE; }
    char bbuf[32]; fread(bbuf, 1, 6, fb); fclose(fb);

    printf("Text mode read: '%s'\n", tbuf);
    printf("Binary read 6 bytes: ");
    for (size_t i = 0; i < 6; ++i) printf("%02x ", (unsigned char)bbuf[i]);
    printf("\nOn Windows text mode may translate \\n; binary writes bytes verbatim.\n");
    return EXIT_SUCCESS;
}