/* Split a file into two parts at line N: lines 1..N-1 -> part1.txt, N..end -> part2.txt. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_sample(const char *name) {
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); exit(EXIT_FAILURE); }
    for (int i = 1; i <= 6; ++i) fprintf(fp, "line %d\n", i);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    const char *src = argc > 1 ? argv[1] : "sample.txt";
    const char *p1  = argc > 2 ? argv[2] : "part1.txt";
    const char *p2  = argc > 3 ? argv[3] : "part2.txt";
    int n_split = argc > 4 ? atoi(argv[4]) : 3;

    ensure_sample(src);
    FILE *in = fopen(src, "r");
    if (!in) { perror(src); return EXIT_FAILURE; }
    FILE *a = fopen(p1, "w");
    if (!a) { perror(p1); fclose(in); return EXIT_FAILURE; }
    FILE *b = fopen(p2, "w");
    if (!b) { perror(p2); fclose(in); fclose(a); return EXIT_FAILURE; }

    char line[512];
    int lineno = 0;
    while (fgets(line, sizeof line, in)) {
        lineno++;
        FILE *out = (lineno < n_split) ? a : b;
        fputs(line, out);
    }
    fclose(in); fclose(a); fclose(b);
    printf("Split at line %d -> %s and %s\n", n_split, p1, p2);
    return EXIT_SUCCESS;
}