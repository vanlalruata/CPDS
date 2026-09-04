/* fread: read back student structs from a binary file and display. */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int roll; char name[32]; float marks; } Student;

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "students.bin";
    FILE *fp = fopen(name, "rb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    Student s;
    long i = 0;
    while (fread(&s, sizeof s, 1, fp) == 1) {
        printf("Roll=%d Name=%s Marks=%.2f\n", s.roll, s.name, s.marks);
        i++;
    }
    fclose(fp);
    printf("Read %ld record(s)\n", i);
    return EXIT_SUCCESS;
}