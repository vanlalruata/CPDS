/*
 * part_p / q44.c
 * Stack Using Linked List - Stack for student records.
 * Each node holds a Student {id, name, gpa}. Menu:
 * 1=push 2=pop 3=display 0=exit. Push reads id name gpa.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int id; char name[30]; float gpa; } Student;

typedef struct Node { Student s; struct Node *next; } Node;

void push(Node **top, Student s) {
    Node *nn = (Node*)malloc(sizeof(Node));
    nn->s = s; nn->next = *top; *top = nn;
}
Student pop(Node **top) {
    Student empty; empty.id = -1;
    if (!*top) { printf("Underflow\n"); return empty; }
    Node *t = *top; Student v = t->s; *top = t->next; free(t); return v;
}

int main(void) {
    Node *top = NULL;
    int ch;
    while (scanf("%d", &ch) == 1 && ch != 0) {
        if (ch == 1) {
            Student s;
            if (scanf("%d %29s %f", &s.id, s.name, &s.gpa) == 3) push(&top, s);
        } else if (ch == 2) {
            Student s = pop(&top);
            if (s.id != -1) printf("Popped %d %s %.2f\n", s.id, s.name, s.gpa);
        } else if (ch == 3) {
            printf("Records: ");
            for (Node *c = top; c; c = c->next)
                printf("[%d %s %.2f] ", c->s.id, c->s.name, c->s.gpa);
            printf("\n");
        }
    }
    while (top) { Node *t = top->next; free(top); top = t; }
    return 0;
}
