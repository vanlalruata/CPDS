/* Chunked file processing: read a file in 64-byte chunks, print summary per chunk. */
#include <stdio.h>
#include <stdlib.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "wb");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    for (int i = 0; i < 250; ++i) fputc(i % 256, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "chunk.bin";
    ensure_sample(name);
    FILE *fp = fopen(name, "rb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    unsigned char buf[64];
    size_t n; long idx = 0;
    while ((n = fread(buf, 1, sizeof buf, fp)) > 0) {
        printf("Chunk %ld: size=%zu first=0x%02X last=0x%02X\n",
               idx++, n, buf[0], buf[n-1]);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}