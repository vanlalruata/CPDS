/* Search for a record by roll number in a binary file using fread in a loop. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int roll; char name[32]; float marks; } Student;

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "students.bin";
    int target = argc > 2 ? atoi(argv[2]) : 3;

    FILE *fp = fopen(name, "rb");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    Student s;
    long i = 0, found = -1;
    while (fread(&s, sizeof s, 1, fp) == 1) {
        if (s.roll == target) {
            printf("Found at index %ld: Roll=%d Name=%s Marks=%.2f\n", i, s.roll, s.name, s.marks);
            found = i;
            break;
        }
        i++;
    }
    fclose(fp);
    if (found < 0) printf("Roll %d not found.\n", target);
    return found < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}