/* part_k / q3: Define a structure for a book. */
#include <stdio.h>

typedef struct {
    char title[50];
    char author[40];
    int year;
} Book;

int main(void) {
    Book b = { "C Programming", "Ritchie", 1988 };
    printf("%s by %s (%d)\n", b.title, b.author, b.year);
    return 0;
}
