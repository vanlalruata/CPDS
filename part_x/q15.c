/* Use fprintf to write formatted student records to students.txt. */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int roll; char name[32]; float marks; } Student;

int main(int argc, char *argv[]) {
    const char *name = argc > 1 ? argv[1] : "students.txt";
    FILE *fp = fopen(name, "w");
    if (!fp) { perror(name); return EXIT_FAILURE; }
    Student s[3] = {
        {1, "Alice", 88.5f},
        {2, "Bob",   76.0f},
        {3, "Carol", 92.25f},
    };
    for (size_t i = 0; i < 3; ++i)
        fprintf(fp, "%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    fclose(fp);
    printf("Wrote 3 records to %s\n", name);
    return EXIT_SUCCESS;
}