/*
 * q50.c -- CIRCULAR QUEUE IMPLEMENTED WITH A CIRCULAR LINKED LIST
 *
 * Design: a single 'rear' pointer is enough for a circular list, because
 *      front = rear->next
 * so both enqueue (insert after rear) and dequeue (remove rear->next) are O(1).
 * A capacity and a size counter are kept so the classic FULL / EMPTY
 * (overflow / underflow) conditions of a circular queue can be demonstrated.
 *
 * Operations: 1 Enqueue  2 Dequeue  3 Peek front  4 Display  5 Status  6 Exit
 *
 * Compile: gcc q50.c -o q50
 * Sample session: 1 10   1 20   1 30   4   2   4   6
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct CQueue {
    struct Node *rear;        /* last inserted node; front = rear->next */
    int size;                 /* current number of elements */
    int capacity;             /* maximum number of elements */
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

void initQueue(struct CQueue *q, int capacity)
{
    q->rear = NULL;
    q->size = 0;
    q->capacity = capacity;
}

int isEmpty(struct CQueue *q)
{
    return (q->size == 0);
}

int isFull(struct CQueue *q)
{
    return (q->size == q->capacity);
}

/* Insert at the rear: O(1). */
void enqueue(struct CQueue *q, int value)
{
    struct Node *node;

    if (isFull(q)) {
        printf("Queue is FULL (overflow) -- cannot insert %d\n", value);
        return;
    }

    node = newNode(value);
    if (q->rear == NULL) {              /* first element */
        node->next = node;              /* points to itself */
        q->rear = node;
    } else {
        node->next = q->rear->next;     /* new node points to the front */
        q->rear->next = node;           /* old rear points to the new node */
        q->rear = node;                 /* new node becomes the rear */
    }
    q->size++;
    printf("Enqueued %d (size = %d/%d)\n", value, q->size, q->capacity);
}

/* Remove from the front: O(1). Returns 1 and the value through *out. */
int dequeue(struct CQueue *q, int *out)
{
    struct Node *front;

    if (isEmpty(q)) {
        printf("Queue is EMPTY (underflow) -- nothing to delete\n");
        return 0;
    }

    front = q->rear->next;              /* the oldest element */
    *out = front->data;

    if (front == q->rear) {             /* only one element */
        q->rear = NULL;
    } else {
        q->rear->next = front->next;    /* skip the front node */
    }
    free(front);
    q->size--;
    return 1;
}

/* Look at the front element without removing it. */
int peek(struct CQueue *q, int *out)
{
    if (isEmpty(q))
        return 0;
    *out = q->rear->next->data;
    return 1;
}

void display(struct CQueue *q)
{
    struct Node *cur;
    int i;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    cur = q->rear->next;                /* start from the front */
    printf("Queue (front to rear): ");
    for (i = 0; i < q->size; i++) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n  front = %d, rear = %d\n", q->rear->next->data, q->rear->data);
}

void status(struct CQueue *q)
{
    printf("Size = %d, Capacity = %d, %s%s\n", q->size, q->capacity,
           isEmpty(q) ? "EMPTY " : "", isFull(q) ? "FULL" : "not full");
}

/* Free every node of the circular queue. */
void destroyQueue(struct CQueue *q)
{
    struct Node *cur, *tmp;
    int i;

    if (q->rear == NULL)
        return;
    cur = q->rear->next;
    for (i = 0; i < q->size; i++) {
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    q->rear = NULL;
    q->size = 0;
}

int main(void)
{
    struct CQueue q;
    int capacity, choice, value;

    printf("Enter the capacity of the circular queue: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("Invalid capacity\n");
        return 1;
    }
    initQueue(&q, capacity);

    for (;;) {
        printf("\n--- Circular Queue (linked list) ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek front\n");
        printf("4. Display\n5. Status\n6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input -- exiting\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter the value to enqueue: ");
            if (scanf("%d", &value) != 1) {
                printf("Invalid input\n");
                destroyQueue(&q);
                return 1;
            }
            enqueue(&q, value);
            break;

        case 2:
            if (dequeue(&q, &value))
                printf("Dequeued %d (size = %d/%d)\n", value, q.size, q.capacity);
            break;

        case 3:
            if (peek(&q, &value))
                printf("Front element = %d\n", value);
            else
                printf("Queue is empty\n");
            break;

        case 4:
            display(&q);
            break;

        case 5:
            status(&q);
            break;

        case 6:
            printf("Exiting -- freeing all nodes\n");
            destroyQueue(&q);
            return 0;

        default:
            printf("Invalid choice, please try again\n");
        }
    }

    destroyQueue(&q);
    return 0;
}
