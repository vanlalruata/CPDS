/* part_t/q10.c — Browser History (Back, Forward, Visit)
 * Concepts: doubly linked list
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[50];
    struct Node *prev, *next;
};

struct Node *current = NULL;

void visit(char *url) {
    struct Node *n = malloc(sizeof(struct Node));
    strcpy(n->url, url); n->prev = NULL; n->next = NULL;
    if (current) {
        current->next = n; n->prev = current;
        while (n->next) free(n->next), n->next = NULL;
    }
    current = n;
    printf("Visited %s\n", current->url);
}

void back() {
    if (current && current->prev) { current = current->prev; printf("Back to %s\n", current->url); }
    else printf("No back history.\n");
}

void forward() {
    if (current && current->next) { current = current->next; printf("Forward to %s\n", current->url); }
    else printf("No forward history.\n");
}

int main(void) {
    int ch; char url[50];
    do {
        printf("\n1.Visit 2.Back 3.Forward 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("url: "); scanf("%49s", url); visit(url); }
        else if (ch == 2) back();
        else if (ch == 3) forward();
    } while (ch != 4);
    while (current) { struct Node *t = current; current = current->prev; free(t); }
    return 0;
}
