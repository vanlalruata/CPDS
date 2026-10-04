/**
 * bonus_menu_driven.c - Part R: Circular Queue & Ring Buffer Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <string.h>

#define CQ_SIZE 5

int cq[CQ_SIZE];
int front = -1;
int rear = -1;

int is_full(void) {
    return (front == (rear + 1) % CQ_SIZE);
}

int is_empty(void) {
    return (front == -1);
}

void cq_enqueue(int val) {
    if (is_full()) {
        printf("Circular Queue is FULL! (Wrap-around prevents memory waste)\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % CQ_SIZE;
    cq[rear] = val;
    printf("Enqueued %d at index %d [Front: %d, Rear: %d].\n", val, rear, front, rear);
}

void cq_dequeue(void) {
    if (is_empty()) {
        printf("Circular Queue is EMPTY.\n");
        return;
    }
    int val = cq[front];
    printf("Dequeued %d from index %d.\n", val, front);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % CQ_SIZE;
    }
}

void cq_display(void) {
    if (is_empty()) {
        printf("Circular Queue is EMPTY.\n");
        return;
    }
    printf("Circular Queue (Capacity %d, Front at index %d, Rear at index %d):\n  Elements: ",
           CQ_SIZE, front, rear);
    int i = front;
    while (1) {
        printf("[%d@idx%d] ", cq[i], i);
        if (i == rear) break;
        i = (i + 1) % CQ_SIZE;
    }
    printf("\n");
}

// Application: CPU Round-Robin Process Scheduling using Circular Queue
typedef struct {
    char name[16];
    int remaining_time;
} Process;

void round_robin_simulation(void) {
    Process p_queue[10];
    int p_front = 0, p_count = 0;
    int quantum;

    printf("\n--- Round-Robin CPU Scheduling Simulation ---\n");
    printf("Enter number of processes (1-5): ");
    if (scanf("%d", &p_count) != 1 || p_count < 1 || p_count > 5) return;

    for (int i = 0; i < p_count; i++) {
        sprintf(p_queue[i].name, "P%d", i + 1);
        printf("Enter burst time for %s: ", p_queue[i].name);
        scanf("%d", &p_queue[i].remaining_time);
    }

    printf("Enter Time Quantum: ");
    if (scanf("%d", &quantum) != 1 || quantum < 1) return;

    printf("\n--- Execution Timeline ---\n");
    int active = p_count;
    int current_time = 0;

    while (active > 0) {
        if (p_queue[p_front].remaining_time > 0) {
            int exec = (p_queue[p_front].remaining_time > quantum) ? quantum : p_queue[p_front].remaining_time;
            p_queue[p_front].remaining_time -= exec;
            current_time += exec;
            printf("Time %2d: %s executed for %d ms (Remaining: %d ms)\n",
                   current_time, p_queue[p_front].name, exec, p_queue[p_front].remaining_time);

            if (p_queue[p_front].remaining_time == 0) {
                printf("  -> %s FINISHED execution!\n", p_queue[p_front].name);
                active--;
            }
        }
        p_front = (p_front + 1) % p_count;
    }
    printf("All processes successfully completed at total time: %d ms\n", current_time);
}

int main(void) {
    cq_enqueue(10);
    cq_enqueue(20);
    cq_enqueue(30);

    int choice, val;
    do {
        printf("\n============================================\n");
        printf("  Part R: Circular Queue & Ring Buffer Hub  \n");
        printf("============================================\n");
        printf("1. Enqueue (Modulo Wrap-Around)\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue State\n");
        printf("4. Round-Robin CPU Scheduler (Application)\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter integer to enqueue: ");
                if (scanf("%d", &val) == 1) cq_enqueue(val);
                break;
            case 2: cq_dequeue(); break;
            case 3: cq_display(); break;
            case 4: round_robin_simulation(); break;
            case 5: printf("Exiting Part R Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
