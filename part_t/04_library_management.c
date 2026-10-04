/* part_t/q4.c — Library Management System
 * Concepts: struct Book
 * Operations: Add book, Search, Issue, Return, Display
 */
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    int issued; /* 0=available, 1=issued */
};

void addBook(struct Book *b, int *n) {
    printf("id, title: ");
    scanf("%d %49s", &b[*n].id, b[*n].title);
    b[*n].issued = 0; (*n)++;
}

void searchBook(struct Book *b, int n, int id) {
    for (int i = 0; i < n; i++)
        if (b[i].id == id) { printf("%d %s %s\n", b[i].id, b[i].title, b[i].issued ? "Issued" : "Available"); return; }
    printf("Not found.\n");
}

void issueBook(struct Book *b, int n, int id) {
    for (int i = 0; i < n; i++)
        if (b[i].id == id) {
            if (b[i].issued) printf("Already issued.\n");
            else { b[i].issued = 1; printf("Issued.\n"); }
            return;
        }
    printf("Not found.\n");
}

void returnBook(struct Book *b, int n, int id) {
    for (int i = 0; i < n; i++)
        if (b[i].id == id) { b[i].issued = 0; printf("Returned.\n"); return; }
    printf("Not found.\n");
}

void display(struct Book *b, int n) {
    for (int i = 0; i < n; i++) printf("%d %s %s\n", b[i].id, b[i].title, b[i].issued ? "Issued" : "Available");
}

int main(void) {
    struct Book b[MAX]; int n = 0, ch, id;
    do {
        printf("\n1.Add 2.Search 3.Issue 4.Return 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addBook(b, &n); break;
            case 2: printf("id: "); scanf("%d", &id); searchBook(b, n, id); break;
            case 3: printf("id: "); scanf("%d", &id); issueBook(b, n, id); break;
            case 4: printf("id: "); scanf("%d", &id); returnBook(b, n, id); break;
            case 5: display(b, n); break;
        }
    } while (ch != 6);
    return 0;
}
