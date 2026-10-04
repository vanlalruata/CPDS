/* tmpfile: create a temporary binary file, write, rewind, read it back; auto-deletes on close. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = tmpfile();
    if (!fp) { perror("tmpfile"); return EXIT_FAILURE; }
    const char *msg = "temporary binary data\n";
    if (fwrite(msg, 1, 18, fp) != 18) { perror("fwrite"); fclose(fp); return EXIT_FAILURE; }

    rewind(fp);
    char buf[64];
    size_t n = fread(buf, 1, sizeof buf - 1, fp);
    buf[n] = '\0';
    printf("Read back from tmpfile: %s", buf);
    fclose(fp);
    return EXIT_SUCCESS;
}