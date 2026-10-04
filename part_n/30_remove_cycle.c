/*
 * q30.c -- Singly Linked List: REMOVE A CYCLE
 *
 * Idea:
 *   1. detect the cycle with Floyd's algorithm (slow/fast meeting point);
 *   2. find the first node of the loop: reset one pointer to the head and
 *      advance both one step at a time until they meet;
 *   3. walk around the loop to the node whose next is that start node and set
 *      its next to NULL -- the list becomes linear again.
 *
 * A cycle is created from user input so the removal can be demonstrated.
 *
 * Compile: gcc q30.c -o q30
 * Sample input : 6  1 2 3 4 5 6   link 3  ->  cycle removed, list = 1..6 -> NULL
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

struct Node *detectCycle(struct Node *head)
{
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}

/*
 * Removes the cycle if one exists.
 * Returns 1 if a cycle was found and removed, 0 if the list was already linear.
 */
int removeCycle(struct Node *head)
{
    struct Node *meet = detectCycle(head);
    struct Node *p, *q;

    if (meet == NULL)
        return 0;                       /* nothing to remove */

    /* step 2: find the first node of the loop */
    p = head;
    q = meet;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    /* p == q == start of the cycle */

    /* step 3: find the last node of the loop and cut the link */
    q = p;
    while (q->next != p)
        q = q->next;
    q->next = NULL;

    printf("Cycle removed: the link from node %d back to node %d was cut\n",
           q->data, p->data);
    return 1;
}

/* Safe display used while a cycle may still be present. */
void displaySafe(struct Node *head, int limit)
{
    struct Node *cur = head;
    int i = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (cur != NULL && i < limit) {
        printf("%d -> ", cur->data);
        cur = cur->next;
        i++;
    }
    if (cur == NULL)
        printf("NULL\n");
    else
        printf("... (cycle: traversal never ends)\n");
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
    struct Node *head = NULL, *cur, *target = NULL, *last = NULL;
    int n, i, value, linkPos;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input (need at least 1 node)\n");
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

    printf("Enter position (1..%d) the last node should point to, "
           "or 0 for no cycle: ", n);
    if (scanf("%d", &linkPos) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    for (cur = head, i = 1; cur != NULL; cur = cur->next, i++) {
        if (i == linkPos)
            target = cur;
        if (cur->next == NULL)
            last = cur;
    }

    if (linkPos >= 1 && linkPos <= n && target != NULL) {
        last->next = target;
        printf("\nCycle created: last node -> node %d (value %d)\n",
               linkPos, target->data);
    } else {
        printf("\nNo cycle created -- the list is linear\n");
    }

    printf("List before removal (safe print): ");
    displaySafe(head, n + 5);

    printf("\nDetecting a cycle: %s\n",
           (detectCycle(head) != NULL) ? "cycle present" : "no cycle");

    if (!removeCycle(head))
        printf("No cycle to remove\n");

    printf("\nList after cycle removal: ");
    display(head);                       /* now safe: the list is linear */
    printf("Detecting a cycle again: %s\n",
           (detectCycle(head) != NULL) ? "cycle present" : "no cycle");

    freeList(head);
    return 0;
}
