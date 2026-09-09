#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


// =====================================================
// INSERT NODE AT A GIVEN POSITION
// =====================================================

void insert(struct Node **head, int value, int position)
{
    struct Node *newNode;
    struct Node *temp;
    int i;

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


    // List is empty
    if(*head == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }


    // Find the node before insertion position
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


// =====================================================
// DELETE NODE FROM A GIVEN POSITION
// =====================================================

void deleteNode(struct Node **head, int position)
{
    struct Node *temp;
    struct Node *deleteNode;
    int i;


    // Check if list is empty
    if(*head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }


    // Delete first node
    if(position == 1)
    {
        deleteNode = *head;

        *head = (*head)->next;

        printf("Deleted value: %d\n", deleteNode->data);

        free(deleteNode);

        return;
    }


    // Find node before the node to be deleted
    temp = *head;

    for(i = 1; i < position - 1; i++)
    {
        if(temp->next == NULL)
        {
            printf("Invalid position.\n");
            return;
        }

        temp = temp->next;
    }


    // Check whether position exists
    if(temp->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }


    // Store node to be deleted
    deleteNode = temp->next;


    // Remove node from list
    temp->next = deleteNode->next;


    printf("Deleted value: %d\n", deleteNode->data);

    free(deleteNode);
}


// =====================================================
// DISPLAY LINKED LIST
// =====================================================

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


// =====================================================
// SORT LINKED LIST
// =====================================================

void sortList(struct Node *head)
{
    struct Node *current;
    struct Node *index;
    int temp;

    if(head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    current = head;

    while(current != NULL)
    {
        index = current->next;

        while(index != NULL)
        {
            if(current->data > index->data)
            {
                // Swap data
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }

            index = index->next;
        }

        current = current->next;
    }

    printf("Linked list sorted successfully.\n");
}


// =====================================================
// FREE LINKED LIST
// =====================================================

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


// =====================================================
// MAIN
// =====================================================

int main()
{
    struct Node *head = NULL;

    int choice;
    int value;
    int position;


    do
    {
        printf("\n==============================\n");
        printf("       LINKED LIST MENU\n");
        printf("==============================\n");

        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Sort\n");
        printf("5. Exit\n");

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

                printf("Enter position to delete: ");
                scanf("%d", &position);

                if(position < 1)
                {
                    printf("Position must be 1 or greater.\n");
                }
                else
                {
                    deleteNode(&head, position);
                }

                break;


            case 3:

                display(head);

                break;


            case 4:

                sortList(head);

                break;


            case 5:

                freeList(head);

                printf("Program terminated.\n");

                break;


            default:

                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 5);


    return 0;
}