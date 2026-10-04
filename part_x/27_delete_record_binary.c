/* Delete a record from a binary file by rewriting all others to a temp file then renaming. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int roll; char name[32]; float marks; } Student;

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "students.bin";
    const char *tmp  = "students.tmp";
    int target = argc > 2 ? atoi(argv[2]) : 3;

    FILE *in = fopen(name, "rb");
    if (!in) { perror(name); return EXIT_FAILURE; }
    FILE *out = fopen(tmp, "wb");
    if (!out) { perror(tmp); fclose(in); return EXIT_FAILURE; }

    Student s;
    long kept = 0, removed = 0;
    while (fread(&s, sizeof s, 1, in) == 1) {
        if (s.roll == target) { removed++; continue; }
        if (fwrite(&s, sizeof s, 1, out) != 1) { perror("fwrite"); fclose(in); fclose(out); return EXIT_FAILURE; }
        kept++;
    }
    fclose(in); fclose(out);

    if (remove(name) != 0) { perror("remove src"); remove(tmp); return EXIT_FAILURE; }
    if (rename(tmp, name) != 0) { perror("rename"); return EXIT_FAILURE; }
    printf("Deleted roll=%d. Kept=%ld Removed=%ld\n", target, kept, removed);
    return EXIT_SUCCESS;
}