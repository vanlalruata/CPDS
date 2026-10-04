/* XOR file encrypt/decrypt: XOR each byte with a key; encrypt then decrypt and verify. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_plain(const char *name) {
    FILE *fp = fopen(name, "wb");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    const char *data = "Secret payload for XOR demo!";
    fwrite(data, 1, strlen(data), fp);
    fclose(fp);
}

static int xor_copy(const char *in_name, const char *out_name, unsigned char key) {
    FILE *in = fopen(in_name, "rb"); if (!in) { perror(in_name); return -1; }
    FILE *out = fopen(out_name, "wb"); if (!out) { perror(out_name); fclose(in); return -1; }
    unsigned char buf[4096]; size_t n;
    while ((n = fread(buf, 1, sizeof buf, in)) > 0) {
        for (size_t i = 0; i < n; ++i) buf[i] ^= key;
        if (fwrite(buf, 1, n, out) != n) { perror("fwrite"); fclose(in); fclose(out); return -1; }
    }
    fclose(in); fclose(out);
    return 0;
}

int main(int argc, char *argv[]) {
    const char *plain = argc > 1 ? argv[1] : "plain.bin";
    const char *enc   = argc > 2 ? argv[2] : "enc.bin";
    const char *dec   = argc > 3 ? argv[3] : "dec.bin";
    unsigned char key = (unsigned char)(argc > 4 ? atoi(argv[4]) : 0x5A);

    ensure_plain(plain);
    if (xor_copy(plain, enc, key) != 0) return EXIT_FAILURE;
    if (xor_copy(enc, dec, key) != 0) return EXIT_FAILURE;

    FILE *a = fopen(plain, "rb"); FILE *b = fopen(dec, "rb");
    if (!a || !b) { perror("verify"); return EXIT_FAILURE; }
    int xa, xb; int same = 1;
    while ((xa = fgetc(a)) != EOF && (xb = fgetc(b)) != EOF) if (xa != xb) { same = 0; break; }
    fclose(a); fclose(b);
    printf("Encrypt+decrypt %s match=%s\n", plain, same ? "YES" : "NO");
    return same ? EXIT_SUCCESS : EXIT_FAILURE;
}