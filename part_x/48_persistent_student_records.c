/* Persistent student records using binary file: add, list, search; data in students.bin. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int roll; char name[32]; float marks; } Student;

static const char *DB = "students.bin";

static void add(void) {
    Student s;
    printf("Roll Name Marks: ");
    if (scanf("%d %31s %f", &s.roll, s.name, &s.marks) != 3) { puts("Bad input"); return; }
    FILE *fp = fopen(DB, "ab");
    if (!fp) { perror(DB); return; }
    fwrite(&s, sizeof s, 1, fp);
    fclose(fp);
    puts("Added.");
}
static void list(void) {
    FILE *fp = fopen(DB, "rb");
    if (!fp) { puts("No records."); return; }
    Student s; long n = 0;
    while (fread(&s, sizeof s, 1, fp) == 1) {
        printf("[%ld] Roll=%d Name=%s Marks=%.2f\n", n++, s.roll, s.name, s.marks);
    }
    fclose(fp);
}
static void search(void) {
    int r; printf("Roll to search: ");
    if (scanf("%d", &r) != 1) { puts("Bad input"); return; }
    FILE *fp = fopen(DB, "rb");
    if (!fp) { perror(DB); return; }
    Student s; long i = 0; int found = 0;
    while (fread(&s, sizeof s, 1, fp) == 1) {
        if (s.roll == r) {
            printf("Found at %ld: %d %s %.2f\n", i, s.roll, s.name, s.marks);
            found = 1; break;
        }
        i++;
    }
    if (!found) puts("Not found.");
    fclose(fp);
}

int main(void) {
    int ch;
    for (;;) {
        puts("1.Add 2.List 3.Search 4.Exit");
        if (scanf("%d", &ch) != 1) return EXIT_SUCCESS;
        switch (ch) {
            case 1: add(); break;
            case 2: list(); break;
            case 3: search(); break;
            default: return EXIT_SUCCESS;
        }
    }
}