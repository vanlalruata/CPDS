/* part_t/q16.c — Undo System using a stack
 * Maintains a stack of text edits; undo pops the last action.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char *stack[MAX]; int top = -1;

void push(char *s) {
    if (top == MAX - 1) { printf("Stack full.\n"); return; }
    stack[++top] = malloc(strlen(s) + 1);
    strcpy(stack[top], s);
}
void undo() {
    if (top < 0) { printf("Nothing to undo.\n"); return; }
    printf("Undid: %s\n", stack[top]);
    free(stack[top]); top--;
}
void current() {
    if (top < 0) printf("Empty.\n");
    else printf("Current: %s\n", stack[top]);
}

int main(void) {
    int ch; char s[50];
    do {
        printf("\n1.Do (push) 2.Undo 3.Show 4.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) { printf("text: "); scanf("%49s", s); push(s); }
        else if (ch == 2) undo();
        else if (ch == 3) current();
    } while (ch != 4);
    while (top >= 0) free(stack[top]), top--;
    return 0;
}
