/* Read back formatted student records from students.txt via fscanf. */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int roll; char name[32]; float marks; } Student;

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "students.txt";
    FILE *fp = fopen(name, "r");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    Student s;
    int n = 0;
    while (fscanf(fp, "%d %31s %f", &s.roll, s.name, &s.marks) == 3) {
        printf("Roll=%d Name=%s Marks=%.2f\n", s.roll, s.name, s.marks);
        n++;
    }
    fclose(fp);
    printf("Read %d record(s)\n", n);
    return EXIT_SUCCESS;
}