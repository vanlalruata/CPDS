/**
 * bonus_menu_driven.c - Part K: Structures in C
 * Comprehensive Menu-Driven Student Management System
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int roll;
    char name[40];
    Date dob;
    float marks;
} Student;

int student_count = 0;
Student database[MAX_STUDENTS];

void add_student(void) {
    if (student_count >= MAX_STUDENTS) {
        printf("Database full!\n");
        return;
    }
    Student s;
    printf("\n--- Add Student ---\n");
    printf("Enter Roll Number: ");
    if (scanf("%d", &s.roll) != 1) return;

    // Check duplicate roll
    for (int i = 0; i < student_count; i++) {
        if (database[i].roll == s.roll) {
            printf("Error: Student with Roll %d already exists!\n", s.roll);
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %39[^\n]", s.name);
    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &s.dob.day, &s.dob.month, &s.dob.year);
    printf("Enter Marks: ");
    scanf("%lf", (double *)&s.marks); // using float buffer safely:
    float m;
    scanf("%f", &m);
    s.marks = m;

    database[student_count++] = s;
    printf("Student added successfully! Total students: %d\n", student_count);
}

void display_all(void) {
    printf("\n--- Student Database (%d Records) ---\n", student_count);
    if (student_count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("%-8s %-20s %-12s %-8s\n", "Roll", "Name", "DOB", "Marks");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-8d %-20s %02d/%02d/%04d   %-8.2f\n",
               database[i].roll, database[i].name,
               database[i].dob.day, database[i].dob.month, database[i].dob.year,
               database[i].marks);
    }
}

void search_by_roll(void) {
    int roll;
    printf("\n--- Search Student by Roll ---\n");
    printf("Enter Roll number to search: ");
    if (scanf("%d", &roll) != 1) return;

    for (int i = 0; i < student_count; i++) {
        if (database[i].roll == roll) {
            printf("Record Found:\n");
            printf("Roll:  %d\nName:  %s\nDOB:   %02d/%02d/%04d\nMarks: %.2f\n",
                   database[i].roll, database[i].name,
                   database[i].dob.day, database[i].dob.month, database[i].dob.year,
                   database[i].marks);
            return;
        }
    }
    printf("No student found with Roll %d.\n", roll);
}

void sort_by_marks(void) {
    if (student_count < 2) {
        printf("Not enough records to sort.\n");
        return;
    }
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (database[j].marks < database[j + 1].marks) {
                Student temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
    printf("Students sorted in descending order of marks.\n");
    display_all();
}

void struct_padding_demo(void) {
    struct Unpadded {
        char c;
        int i;
        char d;
    };
    struct Reordered {
        int i;
        char c;
        char d;
    };

    printf("\n--- Structure Memory Padding & Alignment ---\n");
    printf("Size of individual types: char=%zu bytes, int=%zu bytes\n", sizeof(char), sizeof(int));
    printf("struct Unpadded  { char c; int i; char d; } = %zu bytes\n", sizeof(struct Unpadded));
    printf("struct Reordered { int i; char c; char d; } = %zu bytes\n", sizeof(struct Reordered));
    printf("Explanation: Compilers pad members to align them to natural word boundaries.\n");
}

int main(void) {
    // Pre-populate with initial records
    database[0] = (Student){101, "Aarav Sharma", {15, 8, 2003}, 88.5f};
    database[1] = (Student){102, "Lalrinawma", {22, 1, 2004}, 94.0f};
    database[2] = (Student){103, "Zonunsanga", {5, 11, 2003}, 76.5f};
    student_count = 3;

    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part K: C Structures Management System    \n");
        printf("============================================\n");
        printf("1. Display All Students\n");
        printf("2. Add New Student\n");
        printf("3. Search Student by Roll\n");
        printf("4. Sort Students by Marks (Topper First)\n");
        printf("5. Structure Memory Padding Analysis\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: display_all(); break;
            case 2: add_student(); break;
            case 3: search_by_roll(); break;
            case 4: sort_by_marks(); break;
            case 5: struct_padding_demo(); break;
            case 6: printf("Exiting Part K System. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
