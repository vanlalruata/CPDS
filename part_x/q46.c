/* Find and replace a word in a file (read line by line, write to new file). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    fputs("foo bar foo\nbaz foo qux\nend foo\n", fp);
    fclose(fp);
}

static void replace_in_line(char *line, const char *old, const char *new) {
    char *p; size_t olen = strlen(old), nlen = strlen(new);
    char tmp[1024];
    while ((p = strstr(line, old)) != NULL) {
        size_t head = (size_t)(p - line);
        snprintf(tmp, sizeof tmp, "%.*s%s%s", (int)head, line, new, p + olen);
        snprintf(line, 1024, "%s", tmp);
        (void)nlen;
        if (strlen(line) >= 1023) break;
    }
}

int main(int argc, char *argv[]) {
    const char *src  = argc > 1 ? argv[1] : "sample.txt";
    const char *dst  = argc > 2 ? argv[2] : "out.txt";
    const char *oldw = argc > 3 ? argv[3] : "foo";
    const char *neww = argc > 4 ? argv[4] : "FOO";

    ensure_sample(src);
    FILE *in = fopen(src, "r"); if (!in) { perror(src); return EXIT_FAILURE; }
    FILE *out = fopen(dst, "w"); if (!out) { perror(dst); fclose(in); return EXIT_FAILURE; }

    char line[1024];
    while (fgets(line, sizeof line, in)) {
        replace_in_line(line, oldw, neww);
        fputs(line, out);
    }
    fclose(in); fclose(out);
    printf("Replaced '%s' -> '%s' in %s, wrote %s\n", oldw, neww, src, dst);
    return EXIT_SUCCESS;
}