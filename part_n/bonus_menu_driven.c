/**
 * bonus_menu_driven.c - Part N: Singly and Circular Linked Lists Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node
typedef struct SNode {
    int data;
    struct SNode *next;
} SNode;

SNode *s_head = NULL;

void sll_display(void) {
    if (!s_head) {
        printf("Singly Linked List is EMPTY.\n");
        return;
    }
    printf("SLL: ");
    SNode *curr = s_head;
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void sll_insert_beginning(int val) {
    SNode *new_node = (SNode *)malloc(sizeof(SNode));
    new_node->data = val;
    new_node->next = s_head;
    s_head = new_node;
    printf("Inserted %d at beginning.\n", val);
}

void sll_insert_end(int val) {
    SNode *new_node = (SNode *)malloc(sizeof(SNode));
    new_node->data = val;
    new_node->next = NULL;
    if (!s_head) {
        s_head = new_node;
    } else {
        SNode *curr = s_head;
        while (curr->next) curr = curr->next;
        curr->next = new_node;
    }
    printf("Inserted %d at end.\n", val);
}

void sll_delete_by_value(int val) {
    if (!s_head) {
        printf("List is empty.\n");
        return;
    }
    if (s_head->data == val) {
        SNode *temp = s_head;
        s_head = s_head->next;
        free(temp);
        printf("Deleted node with value %d.\n", val);
        return;
    }
    SNode *curr = s_head;
    while (curr->next && curr->next->data != val) {
        curr = curr->next;
    }
    if (curr->next) {
        SNode *temp = curr->next;
        curr->next = temp->next;
        free(temp);
        printf("Deleted node with value %d.\n", val);
    } else {
        printf("Value %d not found in list.\n", val);
    }
}

void sll_reverse(void) {
    SNode *prev = NULL, *curr = s_head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    s_head = prev;
    printf("Singly Linked List reversed successfully.\n");
    sll_display();
}

// Circular Linked List
typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

CNode *c_last = NULL;

void cll_display(void) {
    if (!c_last) {
        printf("Circular Linked List is EMPTY.\n");
        return;
    }
    printf("CLL: ");
    CNode *curr = c_last->next;
    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != c_last->next);
    printf("(head)\n");
}

void cll_insert_end(int val) {
    CNode *new_node = (CNode *)malloc(sizeof(CNode));
    new_node->data = val;
    if (!c_last) {
        new_node->next = new_node;
        c_last = new_node;
    } else {
        new_node->next = c_last->next;
        c_last->next = new_node;
        c_last = new_node;
    }
    printf("Inserted %d into Circular List.\n", val);
}

int main(void) {
    // Initial nodes for SLL
    sll_insert_end(10);
    sll_insert_end(20);
    sll_insert_end(30);

    // Initial nodes for CLL
    cll_insert_end(100);
    cll_insert_end(200);
    cll_insert_end(300);

    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part N: Singly & Circular Linked List Hub \n");
        printf("============================================\n");
        printf("1. Display Singly Linked List\n");
        printf("2. SLL: Insert at Beginning\n");
        printf("3. SLL: Insert at End\n");
        printf("4. SLL: Delete Node by Value\n");
        printf("5. SLL: Reverse List\n");
        printf("6. Display Circular Linked List\n");
        printf("7. CLL: Insert Element at End\n");
        printf("8. Exit\n");
        printf("Enter choice (1-8): ");

        if (scanf("%d", &choice) != 1) break;

        int val;
        switch (choice) {
            case 1: sll_display(); break;
            case 2:
                printf("Enter value to insert at beginning: ");
                if (scanf("%d", &val) == 1) sll_insert_beginning(val);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                if (scanf("%d", &val) == 1) sll_insert_end(val);
                break;
            case 4:
                printf("Enter value to delete: ");
                if (scanf("%d", &val) == 1) sll_delete_by_value(val);
                break;
            case 5: sll_reverse(); break;
            case 6: cll_display(); break;
            case 7:
                printf("Enter value for circular list: ");
                if (scanf("%d", &val) == 1) cll_insert_end(val);
                break;
            case 8: printf("Exiting Part N Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 8);

    // Cleanup SLL
    while (s_head) {
        SNode *t = s_head;
        s_head = s_head->next;
        free(t);
    }
    // Cleanup CLL
    if (c_last) {
        CNode *curr = c_last->next;
        while (curr != c_last) {
            CNode *t = curr;
            curr = curr->next;
            free(t);
        }
        free(c_last);
    }

    return 0;
}
