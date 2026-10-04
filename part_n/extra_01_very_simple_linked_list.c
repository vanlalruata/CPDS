#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node n1 = {10, NULL};
    struct Node n2 = {20, NULL};
    struct Node n3 = {30, NULL};

    n1.next = &n2;
    n2.next = &n3;

    struct Node *temp = &n1;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}