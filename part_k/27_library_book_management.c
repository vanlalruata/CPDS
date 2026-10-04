/* part_k / q27: Create a library book management system. */
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char title[50];
    char author[40];
    int available;
} Book;

int main(void) {
    Book b[MAX];
    int n = 0, i, choice;
    char t[50];
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            if (n >= MAX) { printf("Full.\n"); continue; }
            printf("title author available(1/0): ");
            scanf("%49s %39s %d", b[n].title, b[n].author, &b[n].available);
            n++;
        } else if (choice == 2) {
            for (i = 0; i < n; i++) printf("%s by %s (avail=%d)\n", b[i].title, b[i].author, b[i].available);
        } else if (choice == 3) {
            printf("Enter title: ");
            scanf("%49s", t);
            for (i = 0; i < n; i++)
                if (strcmp(b[i].title, t) == 0) printf("%s by %s (avail=%d)\n", b[i].title, b[i].author, b[i].available);
        } else if (choice == 4) {
            break;
        }
    }
    return 0;
}
