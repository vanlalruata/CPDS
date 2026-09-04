/* Update a record in a binary file via rb+: seek to index 2, modify marks, then list all. */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int roll; char name[32]; float marks; } Student;

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "students.bin";
    FILE *fp = fopen(name, "rb+");
    if (!fp) { perror(name); return EXIT_FAILURE; }

    Student s;
    if (fseek(fp, (long)2 * sizeof s, SEEK_SET) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    if (fread(&s, sizeof s, 1, fp) != 1) { perror("fread"); fclose(fp); return EXIT_FAILURE; }
    s.marks += 5.0f;
    if (fseek(fp, (long)2 * sizeof s, SEEK_SET) != 0) { perror("fseek"); fclose(fp); return EXIT_FAILURE; }
    if (fwrite(&s, sizeof s, 1, fp) != 1) { perror("fwrite"); fclose(fp); return EXIT_FAILURE; }
    fclose(fp);

    fp = fopen(name, "rb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    printf("Updated record at index 2 (+5 marks):\n");
    long i = 0;
    while (fread(&s, sizeof s, 1, fp) == 1) {
        printf("[%ld] Roll=%d Name=%s Marks=%.2f\n", i++, s.roll, s.name, s.marks);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}