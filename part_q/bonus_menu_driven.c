/**
 * bonus_menu_driven.c - Part Q: Simple Linear Queue Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_CAPACITY 50

int q_arr[QUEUE_CAPACITY];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == QUEUE_CAPACITY - 1) {
        printf("Queue Overflow! (Linear queue requires reset/circular queue to reuse slots)\n");
        return;
    }
    if (front == -1) front = 0;
    q_arr[++rear] = val;
    printf("Enqueued %d to rear (pos %d).\n", val, rear);
}

void dequeue(void) {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    int val = q_arr[front++];
    printf("Dequeued %d from front.\n", val);
    if (front > rear) {
        // Reset when queue becomes empty
        front = -1;
        rear = -1;
    }
}

void display_queue(void) {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY.\n");
        return;
    }
    printf("Queue (Front to Rear): ");
    for (int i = front; i <= rear; i++) {
        printf("[%d] ", q_arr[i]);
    }
    printf("\n");
}

// Application: Customer Support Ticket Queue
typedef struct {
    int ticket_id;
    char customer_name[32];
} Ticket;

Ticket ticket_queue[20];
int t_front = -1, t_rear = -1, next_ticket = 101;

void customer_service_sim(void) {
    int sub_choice;
    printf("\n--- Customer Service Desk Simulation ---\n");
    do {
        printf("\n1. Issue New Ticket\n2. Serve Next Customer\n3. View Waiting Customers\n4. Return to Main Menu\nEnter choice: ");
        if (scanf("%d", &sub_choice) != 1) break;

        if (sub_choice == 1) {
            if (t_rear >= 19) {
                printf("Ticket queue is full for today!\n");
            } else {
                if (t_front == -1) t_front = 0;
                t_rear++;
                ticket_queue[t_rear].ticket_id = next_ticket++;
                printf("Enter Customer Name: ");
                scanf(" %31[^\n]", ticket_queue[t_rear].customer_name);
                printf("Ticket #%d issued to %s!\n",
                       ticket_queue[t_rear].ticket_id, ticket_queue[t_rear].customer_name);
            }
        } else if (sub_choice == 2) {
            if (t_front == -1 || t_front > t_rear) {
                printf("No customers waiting in line!\n");
            } else {
                printf("Now Serving: Ticket #%d - %s\n",
                       ticket_queue[t_front].ticket_id, ticket_queue[t_front].customer_name);
                t_front++;
                if (t_front > t_rear) { t_front = -1; t_rear = -1; }
            }
        } else if (sub_choice == 3) {
            if (t_front == -1 || t_front > t_rear) {
                printf("No customers waiting.\n");
            } else {
                printf("Waiting Customers (%d):\n", t_rear - t_front + 1);
                for (int i = t_front; i <= t_rear; i++) {
                    printf("  #%d: %s\n", ticket_queue[i].ticket_id, ticket_queue[i].customer_name);
                }
            }
        }
    } while (sub_choice != 4);
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    int choice, val;
    do {
        printf("\n============================================\n");
        printf("  Part Q: Simple Linear Queue Hub           \n");
        printf("============================================\n");
        printf("1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Display Queue\n");
        printf("4. Customer Service Ticket Queue (Application)\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter integer to enqueue: ");
                if (scanf("%d", &val) == 1) enqueue(val);
                break;
            case 2: dequeue(); break;
            case 3: display_queue(); break;
            case 4: customer_service_sim(); break;
            case 5: printf("Exiting Part Q Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
