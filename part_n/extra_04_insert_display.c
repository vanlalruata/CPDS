#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert a node at a given position
void insert(struct Node **head, int value, int position)
{
    struct Node *newNode;
    struct Node *temp;
    int i;

    // Create a new node
    newNode = calloc(1, sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning
    if(position == 1)
    {
        newNode->next = *head;
        *head = newNode;

        printf("Node inserted successfully.\n");
        return;
    }

    // If list is empty
    if(*head == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    // Find the node before the insertion position
    temp = *head;

    for(i = 1; i < position - 1; i++)
    {
        if(temp->next == NULL)
        {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }

        temp = temp->next;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

// Display the linked list
void display(struct Node *head)
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    printf("\nLinked List:\n");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Free the linked list
void freeList(struct Node *head)
{
    struct Node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;

    int choice;
    int value;
    int position;

    do
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &position);

                if(position < 1)
                {
                    printf("Position must be 1 or greater.\n");
                }
                else
                {
                    insert(&head, value, position);
                }

                break;

            case 2:
                display(head);
                break;

            case 3:
                freeList(head);
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}