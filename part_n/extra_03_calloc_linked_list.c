#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *temp;
    struct Node *newNode;

    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        // Allocate memory using calloc
        newNode = calloc(1, sizeof(struct Node));

        if(newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        newNode->data = value;
        newNode->next = NULL;

        // First node
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            // Go to the last node
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            // Attach new node
            temp->next = newNode;
        }
    }

    // Display the linked list
    printf("\nLinked List:\n");

    temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    // Free allocated memory
    temp = head;

    while(temp != NULL)
    {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}