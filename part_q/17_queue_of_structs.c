/* part_q/q17.c
 * A queue of structures (student records).
 */
#include <stdio.h>
#include <string.h>
#define MAX 3

typedef struct { int id; char name[20]; } Student;

Student q[MAX];
int front = 0, rear = -1;

void enqueue(Student s) {
    if (rear == MAX - 1) { printf("Overflow\n"); return; }
    q[++rear] = s;
}

int main() {
    Student s;
    printf("Enter %d students (id name):\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d %s", &s.id, s.name);
        enqueue(s);
    }
    printf("Queue of students:\n");
    while (front <= rear)
        printf("ID=%d Name=%s\n", q[front].id, q[front++].name);
    return 0;
}
