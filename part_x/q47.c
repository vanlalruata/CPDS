/* Count occurrences of a word in a file (read line by line). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("foo bar foo\nbaz foo qux\nfoo end\n", fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *src = argc > 1 ? argv[1] : "sample.txt";
    const char *w   = argc > 2 ? argv[2] : "foo";

    ensure_sample(src);
    FILE *fp = fopen(src, "r"); if (!fp) { perror(src); return EXIT_FAILURE; }
    char line[1024]; long count = 0;
    while (fgets(line, sizeof line, fp)) {
        const char *p = line;
        size_t wlen = strlen(w);
        while ((p = strstr(p, w)) != NULL) {
            count++;
            p += wlen;
        }
    }
    fclose(fp);
    printf("'%s' appears %ld time(s) in %s\n", w, count, src);
    return EXIT_SUCCESS;
}