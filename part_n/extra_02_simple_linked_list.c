#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node n1, n2, n3;

    // Store data
    n1.data = 10;
    n2.data = 20;
    n3.data = 30;

    // Connect the nodes
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    // Start from first node
    struct Node *temp = &n1;

    // Display linked list
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}