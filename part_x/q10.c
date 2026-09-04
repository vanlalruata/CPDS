/* Demo of fopen modes: w, a, r+, w+, a+ with write then read. */
#include <stdio.h>
#include <stdlib.h>

static const char *name = "modes.txt";

static void cleanup(void) { remove(name); }

int main(void) {
    cleanup();

    FILE *fp = fopen(name, "w");
    if (!fp) { perror("w"); return EXIT_FAILURE; }
    fputs("hello\n", fp); fclose(fp);
    printf("w  : created/truncated, wrote 'hello\\n'\n");

    fp = fopen(name, "a");
    if (!fp) { perror("a"); cleanup(); return EXIT_FAILURE; }
    fputs("appended\n", fp); fclose(fp);
    printf("a  : appended 'appended\\n'\n");

    fp = fopen(name, "r+");
    if (!fp) { perror("r+"); cleanup(); return EXIT_FAILURE; }
    fseek(fp, 0, SEEK_END);
    fputs("rplus\n", fp); fclose(fp);
    printf("r+ : opened for read/write, appended 'rplus\\n'\n");

    fp = fopen(name, "w+");
    if (!fp) { perror("w+"); cleanup(); return EXIT_FAILURE; }
    fputs("fresh\n", fp); rewind(fp);
    char buf[64]; fgets(buf, sizeof buf, fp); fclose(fp);
    printf("w+ : truncated then wrote 'fresh\\n', read back: %s", buf);

    fp = fopen(name, "a+");
    if (!fp) { perror("a+"); cleanup(); return EXIT_FAILURE; }
    fseek(fp, 0, SEEK_END);
    fputs("aplus\n", fp); rewind(fp);
    while (fgets(buf, sizeof buf, fp)) printf("%s", buf);
    fclose(fp);
    printf("a+ : appended and read full file.\n");

    cleanup();
    return EXIT_SUCCESS;
}