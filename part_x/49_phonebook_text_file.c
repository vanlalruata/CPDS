/* Simple phonebook using a text file: add/list/search entries stored as "name|phone". */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *DB = "phonebook.txt";

static void add(void) {
    char name[64], phone[32];
    printf("Name Phone: ");
    if (scanf("%63s %31s", name, phone) != 2) { puts("Bad input"); return; }
    FILE *fp = fopen(DB, "a");
    if (!fp) { perror(DB); return; }
    fprintf(fp, "%s|%s\n", name, phone);
    fclose(fp);
    puts("Added.");
}
static void list(void) {
    FILE *fp = fopen(DB, "r");
    if (!fp) { puts("Empty."); return; }
    char line[128]; long n = 0;
    while (fgets(line, sizeof line, fp)) {
        printf("[%ld] %s", n++, line);
    }
    fclose(fp);
}
static void search(void) {
    char name[64];
    printf("Name: "); scanf("%63s", name);
    FILE *fp = fopen(DB, "r");
    if (!fp) { perror(DB); return; }
    char line[128]; int found = 0;
    while (fgets(line, sizeof line, fp)) {
        if (strncmp(line, name, strlen(name)) == 0 && line[strlen(name)] == '|') {
            printf("Found: %s", line);
            found = 1;
        }
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