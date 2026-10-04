/**
 * bonus_menu_driven.c - Part T: Integrated Data Structures Practical Workbench
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Dynamic Student Records Management
typedef struct {
    int id;
    char name[32];
    float gpa;
} Student;

void student_records_workbench(void) {
    int capacity = 2, count = 0;
    Student *list = (Student *)malloc(capacity * sizeof(Student));
    if (!list) return;

    printf("\n--- Integrated Practical: Dynamic Student System ---\n");
    int sub_choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n3. Find Highest GPA\n4. Return to Main Menu\nEnter choice: ");
        if (scanf("%d", &sub_choice) != 1) break;

        if (sub_choice == 1) {
            if (count == capacity) {
                capacity *= 2;
                Student *temp = (Student *)realloc(list, capacity * sizeof(Student));
                if (!temp) { printf("Memory reallocation failed!\n"); break; }
                list = temp;
                printf("[realloc] Expanded storage capacity to %d records.\n", capacity);
            }
            Student s;
            printf("Enter Student ID: ");
            scanf("%d", &s.id);
            printf("Enter Student Name: ");
            scanf(" %31[^\n]", s.name);
            printf("Enter GPA (0.0 - 10.0): ");
            scanf("%f", &s.gpa);
            list[count++] = s;
            printf("Student added successfully.\n");
        } else if (sub_choice == 2) {
            if (count == 0) printf("No student records available.\n");
            else {
                printf("%-6s %-20s %-6s\n", "ID", "Name", "GPA");
                printf("----------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%-6d %-20s %-6.2f\n", list[i].id, list[i].name, list[i].gpa);
                }
            }
        } else if (sub_choice == 3) {
            if (count == 0) printf("No student records.\n");
            else {
                int top_idx = 0;
                for (int i = 1; i < count; i++) {
                    if (list[i].gpa > list[top_idx].gpa) top_idx = i;
                }
                printf("Top Student: %s (ID %d) with GPA: %.2f\n",
                       list[top_idx].name, list[top_idx].id, list[top_idx].gpa);
            }
        }
    } while (sub_choice != 4);

    free(list);
}

// 2. Polynomial Representation & Addition using Linked List
typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode *next;
} PolyNode;

PolyNode *add_poly_term(PolyNode *head, int coeff, int exp) {
    PolyNode *term = (PolyNode *)malloc(sizeof(PolyNode));
    term->coeff = coeff;
    term->exp = exp;
    term->next = NULL;

    if (!head || exp > head->exp) {
        term->next = head;
        return term;
    }
    PolyNode *curr = head;
    while (curr->next && curr->next->exp >= exp) {
        curr = curr->next;
    }
    if (curr->exp == exp) {
        curr->coeff += coeff;
        free(term);
        return head;
    }
    term->next = curr->next;
    curr->next = term;
    return head;
}

void display_poly(PolyNode *head) {
    if (!head) { printf("0\n"); return; }
    PolyNode *curr = head;
    while (curr) {
        printf("%dx^%d", curr->coeff, curr->exp);
        if (curr->next && curr->next->coeff >= 0) printf(" + ");
        else if (curr->next) printf(" ");
        curr = curr->next;
    }
    printf("\n");
}

void polynomial_workbench(void) {
    PolyNode *p1 = NULL, *p2 = NULL, *res = NULL;
    // P1: 5x^3 + 4x^2 + 2x^0
    p1 = add_poly_term(p1, 5, 3);
    p1 = add_poly_term(p1, 4, 2);
    p1 = add_poly_term(p1, 2, 0);

    // P2: -2x^3 + 3x^1 + 7x^0
    p2 = add_poly_term(p2, -2, 3);
    p2 = add_poly_term(p2, 3, 1);
    p2 = add_poly_term(p2, 7, 0);

    printf("\n--- Integrated Practical: Polynomial Operations via Linked List ---\n");
    printf("Polynomial 1: "); display_poly(p1);
    printf("Polynomial 2: "); display_poly(p2);

    // Add P1 and P2
    PolyNode *c1 = p1;
    while (c1) {
        res = add_poly_term(res, c1->coeff, c1->exp);
        c1 = c1->next;
    }
    PolyNode *c2 = p2;
    while (c2) {
        res = add_poly_term(res, c2->coeff, c2->exp);
        c2 = c2->next;
    }
    printf("Sum Result:   "); display_poly(res);

    // Free polynomials
    while (p1) { PolyNode *t = p1; p1 = p1->next; free(t); }
    while (p2) { PolyNode *t = p2; p2 = p2->next; free(t); }
    while (res) { PolyNode *t = res; res = res->next; free(t); }
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part T: Integrated Practical DS Hub       \n");
        printf("============================================\n");
        printf("1. Dynamic Student Record System (DMA + Structs)\n");
        printf("2. Polynomial Arithmetic via Linked Lists\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: student_records_workbench(); break;
            case 2: polynomial_workbench(); break;
            case 3: printf("Exiting Part T Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
