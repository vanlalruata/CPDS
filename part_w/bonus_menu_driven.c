/**
 * bonus_menu_driven.c - Part W: Advanced Trees & Algorithmic Complexity Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *new_node(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int val) {
    if (!root) return new_node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

void inorder_traversal(Node *root) {
    if (!root) return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// Kth smallest element via inorder traversal
void find_kth_smallest_helper(Node *root, int k, int *count, int *result) {
    if (!root || *result != -1) return;
    find_kth_smallest_helper(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    find_kth_smallest_helper(root->right, k, count, result);
}

int get_kth_smallest(Node *root, int k) {
    int count = 0, result = -1;
    find_kth_smallest_helper(root, k, &count, &result);
    return result;
}

// Inorder predecessor and successor
void find_pre_suc(Node *root, Node **pre, Node **suc, int key) {
    if (!root) return;
    if (root->data == key) {
        if (root->left) {
            Node *tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            *pre = tmp;
        }
        if (root->right) {
            Node *tmp = root->right;
            while (tmp->left) tmp = tmp->left;
            *suc = tmp;
        }
        return;
    }
    if (key < root->data) {
        *suc = root;
        find_pre_suc(root->left, pre, suc, key);
    } else {
        *pre = root;
        find_pre_suc(root->right, pre, suc, key);
    }
}

// Mirror tree
Node *mirror_tree(Node *root) {
    if (!root) return NULL;
    Node *m = new_node(root->data);
    m->left = mirror_tree(root->right);
    m->right = mirror_tree(root->left);
    return m;
}

void free_all(Node *root) {
    if (!root) return;
    free_all(root->left);
    free_all(root->right);
    free(root);
}

void complexity_comparison_demo(void) {
    printf("\n--- Data Structure Operation Cost Tradeoff Table ---\n");
    printf("%-20s | %-12s | %-12s | %-12s\n", "Data Structure", "Search", "Insert", "Delete");
    printf("------------------------------------------------------------------\n");
    printf("%-20s | %-12s | %-12s | %-12s\n", "Unsorted Array", "O(N)", "O(1)", "O(N)");
    printf("%-20s | %-12s | %-12s | %-12s\n", "Sorted Array", "O(log N)", "O(N)", "O(N)");
    printf("%-20s | %-12s | %-12s | %-12s\n", "Singly Linked List", "O(N)", "O(1)", "O(N)");
    printf("%-20s | %-12s | %-12s | %-12s\n", "BST (Balanced)", "O(log N)", "O(log N)", "O(log N)");
    printf("%-20s | %-12s | %-12s | %-12s\n", "BST (Degenerate/Skew)", "O(N)", "O(N)", "O(N)");
}

int main(void) {
    Node *root = NULL;
    int keys[] = {50, 25, 75, 10, 30, 60, 90};
    for (int i = 0; i < 7; i++) root = insert(root, keys[i]);

    int choice, val;
    do {
        printf("\n============================================\n");
        printf("  Part W: Advanced BST & Complexity Hub     \n");
        printf("============================================\n");
        printf("1. Inorder Traversal (Sorted View)\n");
        printf("2. Find K-th Smallest Element in BST\n");
        printf("3. Find Inorder Predecessor & Successor\n");
        printf("4. Generate & Display Mirror Image Tree\n");
        printf("5. Data Structure Complexity Tradeoff Matrix\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("BST Inorder: "); inorder_traversal(root); printf("\n");
                break;
            case 2:
                printf("Enter k (1 to 7): ");
                if (scanf("%d", &val) == 1) {
                    int ans = get_kth_smallest(root, val);
                    if (ans != -1) printf("The %d-th smallest element is: %d\n", val, ans);
                    else printf("Invalid k or out of bounds.\n");
                }
                break;
            case 3:
                printf("Enter key to find predecessor and successor for: ");
                if (scanf("%d", &val) == 1) {
                    Node *pre = NULL, *suc = NULL;
                    find_pre_suc(root, &pre, &suc, val);
                    printf("Predecessor: %s\n", pre ? "" : "None");
                    if (pre) printf("%d\n", pre->data);
                    printf("Successor:   %s\n", suc ? "" : "None");
                    if (suc) printf("%d\n", suc->data);
                }
                break;
            case 4: {
                Node *m = mirror_tree(root);
                printf("Mirror Tree Inorder (Descending): ");
                inorder_traversal(m);
                printf("\n");
                free_all(m);
                break;
            }
            case 5:
                complexity_comparison_demo();
                break;
            case 6:
                printf("Exiting Part W Hub. Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    free_all(root);
    return 0;
}
