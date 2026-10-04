/**
 * bonus_menu_driven.c - Part O: Doubly Linked List (DLL) Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

DNode *dll_head = NULL;
DNode *dll_tail = NULL;

void display_forward(void) {
    if (!dll_head) {
        printf("DLL is EMPTY.\n");
        return;
    }
    printf("DLL Forward:  NULL <-> ");
    DNode *curr = dll_head;
    while (curr) {
        printf("[%d] <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void display_backward(void) {
    if (!dll_tail) {
        printf("DLL is EMPTY.\n");
        return;
    }
    printf("DLL Backward: NULL <-> ");
    DNode *curr = dll_tail;
    while (curr) {
        printf("[%d] <-> ", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}

void insert_beginning(int val) {
    DNode *node = (DNode *)malloc(sizeof(DNode));
    node->data = val;
    node->prev = NULL;
    node->next = dll_head;
    if (dll_head) {
        dll_head->prev = node;
    } else {
        dll_tail = node;
    }
    dll_head = node;
    printf("Inserted %d at beginning.\n", val);
}

void insert_end(int val) {
    DNode *node = (DNode *)malloc(sizeof(DNode));
    node->data = val;
    node->next = NULL;
    node->prev = dll_tail;
    if (dll_tail) {
        dll_tail->next = node;
    } else {
        dll_head = node;
    }
    dll_tail = node;
    printf("Inserted %d at end.\n", val);
}

void delete_node(int val) {
    if (!dll_head) {
        printf("DLL is empty.\n");
        return;
    }
    DNode *curr = dll_head;
    while (curr && curr->data != val) {
        curr = curr->next;
    }
    if (!curr) {
        printf("Node with value %d not found.\n", val);
        return;
    }
    if (curr == dll_head) {
        dll_head = curr->next;
        if (dll_head) dll_head->prev = NULL;
        else dll_tail = NULL;
    } else if (curr == dll_tail) {
        dll_tail = curr->prev;
        if (dll_tail) dll_tail->next = NULL;
        else dll_head = NULL;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    free(curr);
    printf("Deleted node with value %d.\n", val);
}

// Browser navigation history simulation using DLL
typedef struct WebPage {
    char url[64];
    struct WebPage *prev;
    struct WebPage *next;
} WebPage;

void browser_history_simulator(void) {
    WebPage *current = NULL;
    int sub_choice;
    char buffer[64];

    printf("\n--- Browser History Simulator (DLL Application) ---\n");
    do {
        printf("\nCurrent Page: %s\n", current ? current->url : "[No pages visited]");
        printf("1. Visit New URL\n2. Back\n3. Forward\n4. Return to DLL Menu\nEnter choice: ");
        if (scanf("%d", &sub_choice) != 1) break;

        if (sub_choice == 1) {
            printf("Enter URL: ");
            scanf(" %63s", buffer);
            WebPage *page = (WebPage *)malloc(sizeof(WebPage));
            strcpy(page->url, buffer);
            page->next = NULL;
            page->prev = current;
            if (current) {
                // Clear any forward history
                WebPage *fwd = current->next;
                while (fwd) {
                    WebPage *tmp = fwd;
                    fwd = fwd->next;
                    free(tmp);
                }
                current->next = page;
            }
            current = page;
            printf("Visited: %s\n", current->url);
        } else if (sub_choice == 2) {
            if (current && current->prev) {
                current = current->prev;
                printf("Navigated back to: %s\n", current->url);
            } else {
                printf("Cannot go back: At start of history.\n");
            }
        } else if (sub_choice == 3) {
            if (current && current->next) {
                current = current->next;
                printf("Navigated forward to: %s\n", current->url);
            } else {
                printf("Cannot go forward: At end of history.\n");
            }
        }
    } while (sub_choice != 4);

    // Cleanup browser history
    if (current) {
        while (current->prev) current = current->prev;
        while (current) {
            WebPage *t = current;
            current = current->next;
            free(t);
        }
    }
}

int main(void) {
    insert_end(10);
    insert_end(20);
    insert_end(30);

    int choice, val;
    do {
        printf("\n============================================\n");
        printf("  Part O: Doubly Linked List (DLL) Hub      \n");
        printf("============================================\n");
        printf("1. Display Forward (Head to Tail)\n");
        printf("2. Display Backward (Tail to Head)\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete Node by Value\n");
        printf("6. Browser History Simulator (Application)\n");
        printf("7. Exit\n");
        printf("Enter choice (1-7): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: display_forward(); break;
            case 2: display_backward(); break;
            case 3:
                printf("Enter value to insert at beginning: ");
                if (scanf("%d", &val) == 1) insert_beginning(val);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                if (scanf("%d", &val) == 1) insert_end(val);
                break;
            case 5:
                printf("Enter value to delete: ");
                if (scanf("%d", &val) == 1) delete_node(val);
                break;
            case 6: browser_history_simulator(); break;
            case 7: printf("Exiting Part O Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    // Free DLL
    while (dll_head) {
        DNode *t = dll_head;
        dll_head = dll_head->next;
        free(t);
    }

    return 0;
}
