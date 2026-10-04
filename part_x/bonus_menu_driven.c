/**
 * bonus_menu_driven.c - Part X: C File Handling Master Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_FILE   "temp_demo.txt"
#define BINARY_FILE "students_demo.bin"

typedef struct {
    int id;
    char name[32];
    float marks;
} StudentRecord;

void text_file_write_read(void) {
    printf("\n--- Text File Operations (fprintf / fgets) ---\n");
    FILE *fp = fopen(TEXT_FILE, "w");
    if (!fp) {
        perror("Failed to open file for writing");
        return;
    }
    fprintf(fp, "Line 1: Mizoram University CPDS Practical\n");
    fprintf(fp, "Line 2: Department of Information Technology\n");
    fprintf(fp, "Line 3: File I/O Demonstration in C\n");
    fclose(fp);
    printf("Successfully wrote 3 lines to '%s'.\n", TEXT_FILE);

    printf("\nReading back from '%s':\n", TEXT_FILE);
    fp = fopen(TEXT_FILE, "r");
    if (!fp) {
        perror("Failed to open file for reading");
        return;
    }
    char line[256];
    int line_num = 1;
    while (fgets(line, sizeof(line), fp)) {
        printf("  [%d] %s", line_num++, line);
    }
    fclose(fp);
}

void file_word_char_count(void) {
    printf("\n--- File Statistics: Characters, Words, Lines Counter ---\n");
    FILE *fp = fopen(TEXT_FILE, "r");
    if (!fp) {
        printf("Please run Option 1 first to create '%s'!\n", TEXT_FILE);
        return;
    }

    int chars = 0, words = 0, lines = 0, in_word = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    fclose(fp);

    printf("File '%s' Statistics:\n", TEXT_FILE);
    printf("  Total Characters: %d\n", chars);
    printf("  Total Words:      %d\n", words);
    printf("  Total Lines:      %d\n", lines);
}

void binary_file_records(void) {
    printf("\n--- Binary File Random Access (fwrite, fread, fseek, ftell) ---\n");
    FILE *fp = fopen(BINARY_FILE, "wb");
    if (!fp) {
        perror("Failed to open binary file for writing");
        return;
    }

    StudentRecord records[3] = {
        {101, "Alice", 89.5f},
        {102, "Bob", 74.0f},
        {103, "Charlie", 92.5f}
    };

    fwrite(records, sizeof(StudentRecord), 3, fp);
    fclose(fp);
    printf("Wrote 3 structured records to binary file '%s'.\n", BINARY_FILE);

    // Reopen for reading and random access
    fp = fopen(BINARY_FILE, "rb");
    if (!fp) return;

    printf("\nReading Record #2 directly using fseek (random access):\n");
    fseek(fp, (long)(1 * sizeof(StudentRecord)), SEEK_SET);
    long pos = ftell(fp);
    printf("File pointer byte offset via ftell(): %ld bytes\n", pos);

    StudentRecord s;
    if (fread(&s, sizeof(StudentRecord), 1, fp) == 1) {
        printf("Retrieved: ID=%d, Name=%s, Marks=%.2f\n", s.id, s.name, s.marks);
    }
    fclose(fp);
}

void cleanup_demo_files(void) {
    remove(TEXT_FILE);
    remove(BINARY_FILE);
    printf("Cleaned up temporary demonstration files.\n");
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part X: C File Handling Master Hub        \n");
        printf("============================================\n");
        printf("1. Text File Write and Read (Formatted I/O)\n");
        printf("2. Count Characters, Words, Lines in File\n");
        printf("3. Binary File Random Access (fseek, ftell)\n");
        printf("4. Clean Up Temporary Demonstration Files\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: text_file_write_read(); break;
            case 2: file_word_char_count(); break;
            case 3: binary_file_records(); break;
            case 4: cleanup_demo_files(); break;
            case 5:
                cleanup_demo_files();
                printf("Exiting Part X Hub. Goodbye!\n");
                break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
