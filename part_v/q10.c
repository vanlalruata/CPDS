/* part_v/q10.c — Stack using array */
#include <stdio.h>
#define N 100

int stack[N], top = -1;

void push(int v) {
    if (top == N - 1) { printf("Overflow\n"); return; }
    stack[++top] = v;
}
int pop() {
    if (top == -1) { printf("Underflow\n"); return -1; }
    return stack[top--];
}
void display() {
    for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
    printf("\n");
}

int main(void) {
    int ch, v;
    do {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("val: "); scanf("%d", &v); push(v); break;
            case 2: v = pop(); if (v != -1) printf("Popped %d\n", v); break;
            case 3: display(); break;
        }
    } while (ch != 4);
    return 0;
}
