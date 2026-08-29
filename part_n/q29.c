/*
 * q29.c -- Singly Linked List: DETECT A CYCLE (Floyd's cycle detection)
 *
 * Idea: move 'slow' one node and 'fast' two nodes per step. If a cycle exists
 * the two pointers must eventually meet inside the loop; if fast reaches NULL
 * the list is linear. O(n) time, O(1) space -- the "tortoise and hare".
 * The program can create a cycle on purpose so the algorithm can be tested:
 * enter the position whose node the last node should point to (0 = no cycle).
 *
 * NOTE: a cyclic list must NOT be printed with a plain traversal (infinite
 * loop) and cannot be freed with a plain free-walk, so the loop is broken
 * before releasing memory.
 *
 * Compile: gcc q29.c -o q29
 * Sample input : 5  1 2 3 4 5   link 3  ->  cycle detected
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

/* Returns the meeting node if a cycle exists, otherwise NULL. */
struct Node *detectCycle(struct Node *head)
{
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;               /* 1 step  */
        fast = fast->next->next;         /* 2 steps */
        if (slow == fast)
            return slow;                 /* they met -> cycle */
    }
    return NULL;                         /* fast hit NULL -> linear list */
}

/*
 * Start of the cycle: after the meeting, move one pointer back to the head and
 * advance both one step at a time; they meet at the first node of the loop.
 */
struct Node *cycleStart(struct Node *head, struct Node *meet)
{
    struct Node *p = head, *q = meet;

    if (meet == NULL)
        return NULL;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}

/* Number of nodes inside the loop. */
int cycleLength(struct Node *meet)
{
    struct Node *p;
    int len = 1;

    if (meet == NULL)
        return 0;
    for (p = meet->next; p != meet; p = p->next)
        len++;
    return len;
}

/* Safe display for possibly cyclic lists: prints at most 'limit' nodes. */
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
        printf("... (traversal stopped: the list repeats)\n");
}

/* Breaks a cycle (if any) so the list can be freed safely. */
void breakCycle(struct Node *head)
{
    struct Node *meet = detectCycle(head);
    struct Node *start, *p;

    if (meet == NULL)
        return;
    start = cycleStart(head, meet);
    p = start;
    while (p->next != start)             /* last node of the loop */
        p = p->next;
    p->next = NULL;
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
    struct Node *head = NULL, *cur, *target = NULL, *last = NULL, *meet, *start;
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

    printf("\nCreated list: ");
    displaySafe(head, n + 5);

    printf("Enter position (1..%d) the last node should point to, "
           "or 0 for no cycle: ", n);
    if (scanf("%d", &linkPos) != 1) {
        printf("Invalid input\n");
        freeList(head);
        return 1;
    }

    /* locate the last node and the target node */
    for (cur = head, i = 1; cur != NULL; cur = cur->next, i++) {
        if (i == linkPos)
            target = cur;
        if (cur->next == NULL)
            last = cur;
    }

    if (linkPos >= 1 && linkPos <= n && target != NULL) {
        last->next = target;             /* create the cycle on purpose */
        printf("A cycle was created: last node now points to node %d (value %d)\n",
               linkPos, target->data);
    } else {
        printf("No cycle created -- the list stays linear\n");
    }

    printf("\nSafe traversal: ");
    displaySafe(head, n + 5);

    meet = detectCycle(head);
    if (meet != NULL) {
        start = cycleStart(head, meet);
        printf("\nFloyd's algorithm: CYCLE DETECTED\n");
        printf("  pointers met at a node with value %d\n", meet->data);
        printf("  cycle starts at the node with value %d\n", start->data);
        printf("  number of nodes in the cycle = %d\n", cycleLength(meet));
    } else {
        printf("\nFloyd's algorithm: NO CYCLE -- the list is linear\n");
    }

    breakCycle(head);                    /* required before freeing */
    freeList(head);
    return 0;
}
