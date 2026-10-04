/* part_t/q6.c — Contact Management System
 * Concepts: struct Contact
 * Operations: Add, Delete, Search, Sort (by name), Display
 */
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[20];
};

void addContact(struct Contact *c, int *n) {
    printf("name, phone: ");
    scanf("%49s %19s", c[*n].name, c[*n].phone);
    (*n)++;
}

void deleteContact(struct Contact *c, int *n, char *name) {
    for (int i = 0; i < *n; i++)
        if (strcmp(c[i].name, name) == 0) {
            for (int j = i; j < *n - 1; j++) c[j] = c[j+1];
            (*n)--; printf("Deleted.\n"); return;
        }
    printf("Not found.\n");
}

void searchContact(struct Contact *c, int n, char *name) {
    for (int i = 0; i < n; i++)
        if (strcmp(c[i].name, name) == 0) { printf("%s %s\n", c[i].name, c[i].phone); return; }
    printf("Not found.\n");
}

void sortContact(struct Contact *c, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(c[i].name, c[j].name) > 0) { struct Contact t = c[i]; c[i] = c[j]; c[j] = t; }
}

void display(struct Contact *c, int n) {
    for (int i = 0; i < n; i++) printf("%s %s\n", c[i].name, c[i].phone);
}

int main(void) {
    struct Contact c[MAX]; int n = 0, ch; char name[50];
    do {
        printf("\n1.Add 2.Delete 3.Search 4.Sort 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addContact(c, &n); break;
            case 2: printf("name: "); scanf("%49s", name); deleteContact(c, &n, name); break;
            case 3: printf("name: "); scanf("%49s", name); searchContact(c, n, name); break;
            case 4: sortContact(c, n); break;
            case 5: display(c, n); break;
        }
    } while (ch != 6);
    return 0;
}
