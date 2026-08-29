/*
 * q20.c -- Singly Linked List: COUNT OCCURRENCES OF A VALUE
 *
 * Idea: traverse the whole list (do not stop at the first hit) and increment a
 * counter each time data == key. Also prints the positions of the matches.
 *
 * Compile: gcc q20.c -o q20
 * Sample input : 7  5 3 5 7 5 9 3   key 5  ->  occurs 3 time(s)
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int value)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    p->data = value;
    p->next = NULL;
    return p;
}

struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *node = newNode(value);
    struct Node *cur = head;

    if (head == NULL)
        return node;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = node;
    return head;
}

/* Iterative count of occurrences. */
int countOccurrences(struct Node *head, int key)
{
    int count = 0;

    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
}

/* Recursive count of occurrences. */
int countOccurrencesRecursive(struct Node *head, int key)
{
    if (head == NULL)
        return 0;
    return (head->data == key ? 1 : 0) + countOccurrencesRecursive(head->next, key);
}

void printPositions(struct Node *head, int key)
{
    int pos = 1, found = 0;

    while (head != NULL) {
        if (head->data == key) {
            printf("%d ", pos);
            found = 1;
        }
        head = head->next;
        pos++;
    }
    if (!found)
        printf("(none)");
    printf("\n");
}

void display(struct Node *head)
{
    struct Node *cur;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    for (cur = head; cur != NULL; cur = cur->next)
        printf("%d -> ", cur->data);
    printf("NULL\n");
}

void freeList(struct Node *head)
{
    struct Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void)
{
    struct Node *head = NULL;
    int n, i, value, key;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter %d integer(s): ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) {
            printf("Invalid input\n");
            freeList(head);
            return 1;
        }
        head = insertEnd(head, value);
    }

    printf("\nList: ");
    display(head);

    printf("Enter the value to count: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    printf("\nValue %d occurs %d time(s) [iterative]\n",
           key, countOccurrences(head, key));
    printf("Value %d occurs %d time(s) [recursive]\n",
           key, countOccurrencesRecursive(head, key));
    printf("Positions: ");
    printPositions(head, key);

    freeList(head);
    return 0;
}
