/**
 * bonus_menu_driven.c - Part S: Binary Search Tree (BST) Hub
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode *create_node(int val) {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BSTNode *bst_insert(BSTNode *root, int val) {
    if (!root) return create_node(val);
    if (val < root->data) {
        root->left = bst_insert(root->left, val);
    } else if (val > root->data) {
        root->right = bst_insert(root->right, val);
    }
    return root;
}

BSTNode *bst_search(BSTNode *root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return bst_search(root->left, key);
    return bst_search(root->right, key);
}

BSTNode *find_min(BSTNode *root) {
    while (root && root->left) root = root->left;
    return root;
}

BSTNode *find_max(BSTNode *root) {
    while (root && root->right) root = root->right;
    return root;
}

BSTNode *bst_delete(BSTNode *root, int key) {
    if (!root) return NULL;

    if (key < root->data) {
        root->left = bst_delete(root->left, key);
    } else if (key > root->data) {
        root->right = bst_delete(root->right, key);
    } else {
        // Node found
        // Case 1 & 2: 0 or 1 child
        if (!root->left) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: 2 children - get inorder successor
        BSTNode *temp = find_min(root->right);
        root->data = temp->data;
        root->right = bst_delete(root->right, temp->data);
    }
    return root;
}

void inorder(BSTNode *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(BSTNode *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(BSTNode *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int tree_height(BSTNode *root) {
    if (!root) return 0;
    int lh = tree_height(root->left);
    int rh = tree_height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int count_nodes(BSTNode *root) {
    if (!root) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void free_tree(BSTNode *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void) {
    BSTNode *root = NULL;
    int initial_keys[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        root = bst_insert(root, initial_keys[i]);
    }

    int choice, val;
    do {
        printf("\n============================================\n");
        printf("  Part S: Binary Search Tree (BST) Hub      \n");
        printf("============================================\n");
        printf("1. Display Traversals (Inorder, Preorder, Postorder)\n");
        printf("2. Insert Key into BST\n");
        printf("3. Search for Key\n");
        printf("4. Delete Key from BST\n");
        printf("5. Find Min and Max Key\n");
        printf("6. Compute Tree Height & Total Nodes\n");
        printf("7. Exit\n");
        printf("Enter choice (1-7): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Inorder (Sorted):   "); inorder(root); printf("\n");
                printf("Preorder (Root 1st): "); preorder(root); printf("\n");
                printf("Postorder:          "); postorder(root); printf("\n");
                break;
            case 2:
                printf("Enter value to insert: ");
                if (scanf("%d", &val) == 1) {
                    root = bst_insert(root, val);
                    printf("Key %d inserted.\n", val);
                }
                break;
            case 3:
                printf("Enter key to search: ");
                if (scanf("%d", &val) == 1) {
                    BSTNode *found = bst_search(root, val);
                    if (found) printf("Key %d FOUND in BST!\n", val);
                    else printf("Key %d NOT found in BST.\n", val);
                }
                break;
            case 4:
                printf("Enter key to delete: ");
                if (scanf("%d", &val) == 1) {
                    root = bst_delete(root, val);
                    printf("Deleted %d (if present).\n", val);
                }
                break;
            case 5: {
                BSTNode *min_n = find_min(root);
                BSTNode *max_n = find_max(root);
                if (min_n && max_n)
                    printf("Minimum Key: %d | Maximum Key: %d\n", min_n->data, max_n->data);
                else
                    printf("Tree is empty.\n");
                break;
            }
            case 6:
                printf("Tree Height: %d | Total Nodes: %d\n", tree_height(root), count_nodes(root));
                break;
            case 7:
                printf("Exiting Part S Hub. Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    free_tree(root);
    return 0;
}
