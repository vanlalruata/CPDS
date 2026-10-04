/* fwrite: write an array of 5 student structs to a binary file. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int roll; char name[32]; float marks; } Student;

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "students.bin";
    Student s[5] = {
        {1, "Alice", 88.5f}, {2, "Bob", 76.0f}, {3, "Carol", 92.25f},
        {4, "Dave",  65.5f}, {5, "Eve",  81.0f},
    };
    FILE *fp = fopen(name, "wb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    size_t w = fwrite(s, sizeof s[0], 5, fp);
    fclose(fp);
    if (w != 5) { fprintf(stderr, "fwrite wrote only %zu items\n", w); return EXIT_FAILURE; }
    printf("Wrote %zu records (%zu bytes) to %s\n", w, w * sizeof s[0], name);
    return EXIT_SUCCESS;
}