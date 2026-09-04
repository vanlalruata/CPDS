/* Complete student record system with file persistence (students.dat) and random access. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int roll; char name[32]; float marks; } Student;

static const char *DB = "students.dat";

static long count_records(void) {
    FILE *fp = fopen(DB, "rb"); if (!fp) return 0;
    if (fseek(fp, 0, SEEK_END) != 0) { fclose(fp); return -1; }
    long sz = ftell(fp); fclose(fp);
    return sz / (long)sizeof(Student);
}
static void add(void) {
    Student s;
    printf("Roll Name Marks: ");
    if (scanf("%d %31s %f", &s.roll, s.name, &s.marks) != 3) { puts("Bad input"); return; }
    FILE *fp = fopen(DB, "ab"); if (!fp) { perror(DB); return; }
    fwrite(&s, sizeof s, 1, fp); fclose(fp); puts("Added.");
}
static void list(void) {
    FILE *fp = fopen(DB, "rb"); if (!fp) { puts("No records."); return; }
    Student s; long n = 0;
    while (fread(&s, sizeof s, 1, fp) == 1)
        printf("[%ld] Roll=%d Name=%s Marks=%.2f\n", n++, s.roll, s.name, s.marks);
    fclose(fp);
}
static void search(void) {
    int r; printf("Roll: "); if (scanf("%d", &r) != 1) { puts("Bad input"); return; }
    FILE *fp = fopen(DB, "rb"); if (!fp) { perror(DB); return; }
    Student s; long i = 0; int found = 0;
    while (fread(&s, sizeof s, 1, fp) == 1) {
        if (s.roll == r) { printf("Found at %ld: %d %s %.2f\n", i, s.roll, s.name, s.marks); found = 1; }
        i++;
    }
    if (!found) puts("Not found.");
    fclose(fp);
}
static void update(void) {
    long n = count_records(); if (n <= 0) { puts("No records."); return; }
    long idx; printf("Index to update [0..%ld]: ", n-1);
    if (scanf("%ld", &idx) != 1 || idx < 0 || idx >= n) { puts("Bad index."); return; }
    FILE *fp = fopen(DB, "rb+"); if (!fp) { perror(DB); return; }
    Student s;
    fseek(fp, idx * (long)sizeof s, SEEK_SET);
    fread(&s, sizeof s, 1, fp);
    printf("Current: %d %s %.2f\n", s.roll, s.name, s.marks);
    printf("New Name Marks: "); scanf("%31s %f", s.name, &s.marks);
    fseek(fp, idx * (long)sizeof s, SEEK_SET);
    fwrite(&s, sizeof s, 1, fp); fclose(fp);
    puts("Updated.");
}
static void delete(void) {
    long n = count_records(); if (n <= 0) { puts("No records."); return; }
    long idx; printf("Index to delete [0..%ld]: ", n-1);
    if (scanf("%ld", &idx) != 1 || idx < 0 || idx >= n) { puts("Bad index."); return; }
    FILE *in = fopen(DB, "rb"); if (!in) { perror(DB); return; }
    FILE *out = fopen("students.tmp", "wb"); if (!out) { perror("tmp"); fclose(in); return; }
    Student s; long i = 0;
    while (fread(&s, sizeof s, 1, in) == 1) {
        if (i++ == idx) continue;
        fwrite(&s, sizeof s, 1, out);
    }
    fclose(in); fclose(out);
    remove(DB); rename("students.tmp", DB);
    puts("Deleted.");
}

int main(void) {
    int ch;
    for (;;) {
        puts("1.Add 2.List 3.Search 4.Update 5.Delete 6.Exit");
        if (scanf("%d", &ch) != 1) return EXIT_SUCCESS;
        switch (ch) {
            case 1: add(); break;
            case 2: list(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: delete(); break;
            default: return EXIT_SUCCESS;
        }
    }
}