#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Adjacency List Node for Graph --- */
typedef struct AdjListNode {
    int dest;
    struct AdjListNode *next;
} AdjListNode;

typedef struct Graph {
    int numVertices;
    AdjListNode **adjLists;
} Graph;

/* --- Multi-way Tree Node for Best-First Search --- */
typedef struct ChildNode ChildNode;

typedef struct TreeNode {
    int vertex;
    int hVal;
    ChildNode *childrenHead;
    ChildNode *childrenTail;
} TreeNode;

struct ChildNode {
    TreeNode *node;
    struct ChildNode *next;
};

/* --- Sorted Linked List Priority Queue --- */
typedef struct PQNode {
    TreeNode *treeNode;
    int hVal;
    struct PQNode *next;
} PQNode;

/* --- Dynamic Traversal Order List --- */
typedef struct ListNode {
    int vertex;
    struct ListNode *next;
} ListNode;

/* --- Allocators & Graph Helpers --- */
AdjListNode* createAdjNode(int dest) {
    AdjListNode *newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;
    g->adjLists = (AdjListNode**)calloc(vertices, sizeof(AdjListNode*));
    return g;
}

void addEdge(Graph *g, int src, int dest) {
    AdjListNode *newNode = createAdjNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
}

TreeNode* createTreeNode(int vertex, int hVal) {
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    t->vertex = vertex;
    t->hVal = hVal;
    t->childrenHead = NULL;
    t->childrenTail = NULL;
    return t;
}

void addChild(TreeNode *parent, TreeNode *child) {
    ChildNode *cn = (ChildNode*)malloc(sizeof(ChildNode));
    cn->node = child;
    cn->next = NULL;
    if (!parent->childrenHead) {
        parent->childrenHead = cn;
        parent->childrenTail = cn;
    } else {
        parent->childrenTail->next = cn;
        parent->childrenTail = cn;
    }
}

/* --- Linked List Priority Queue Operations --- */
void pqInsert(PQNode **head, TreeNode *node, int hVal) {
    PQNode *newNode = (PQNode*)malloc(sizeof(PQNode));
    newNode->treeNode = node;
    newNode->hVal = hVal;
    newNode->next = NULL;

    /* Insert in ascending order of h(n) */
    if (*head == NULL || hVal < (*head)->hVal) {
        newNode->next = *head;
        *head = newNode;
    } else {
        PQNode *curr = *head;
        while (curr->next != NULL && curr->next->hVal <= hVal) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

TreeNode* pqPop(PQNode **head) {
    if (*head == NULL) return NULL;
    PQNode *temp = *head;
    TreeNode *node = temp->treeNode;
    *head = (*head)->next;
    free(temp);
    return node;
}

int isPQEmpty(PQNode *head) {
    return head == NULL;
}

/* --- Traversal Recording List --- */
void appendOrder(ListNode **head, ListNode **tail, int vertex) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

/* --- Best-First Search Tree Construction --- */
void buildBestFirstTree(Graph *g, int start, int *heuristic, int *visited,
                        TreeNode *root, ListNode **orderHead, ListNode **orderTail) {
    PQNode *pq = NULL;

    visited[start] = 1;
    pqInsert(&pq, root, heuristic[start]);

    while (!isPQEmpty(pq)) {
        TreeNode *currTree = pqPop(&pq);
        int u = currTree->vertex;
        appendOrder(orderHead, orderTail, u);

        AdjListNode *adj = g->adjLists[u];
        while (adj) {
            int v = adj->dest;
            if (!visited[v]) {
                visited[v] = 1;
                TreeNode *childNode = createTreeNode(v, heuristic[v]);
                addChild(currTree, childNode);
                pqInsert(&pq, childNode, heuristic[v]);
            }
            adj = adj->next;
        }
    }
}

/* --- Visual Tree Display with Box Drawing --- */
void displayTree(TreeNode *root, const char *prefix, int isLast) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    printf("%d (h=%d)\n", root->vertex, root->hVal);

    char newPrefix[512];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    ChildNode *curr = root->childrenHead;
    while (curr) {
        displayTree(curr->node, newPrefix, curr->next == NULL);
        curr = curr->next;
    }
}

/* --- Memory Cleanup --- */
void freeTree(TreeNode *root) {
    if (!root) return;
    ChildNode *curr = root->childrenHead;
    while (curr) {
        ChildNode *tmp = curr;
        curr = curr->next;
        freeTree(tmp->node);
        free(tmp);
    }
    free(root);
}

void freeGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        AdjListNode *curr = g->adjLists[i];
        while (curr) {
            AdjListNode *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(g->adjLists);
    free(g);
}

void freeOrderList(ListNode *head) {
    while (head) {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* --- Main Driver --- */
int main(void) {
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) return 1;

    Graph *g = createGraph(vertices);
    int *heuristic = (int*)malloc(vertices * sizeof(int));

    printf("Enter heuristic h(n) for each vertex (0 to %d):\n", vertices - 1);
    for (int i = 0; i < vertices; i++) {
        printf("h(%d): ", i);
        scanf("%d", &heuristic[i]);
    }

    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1) return 1;

    printf("Enter each edge as (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }

    printf("Enter start vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    int *visited = (int*)calloc(vertices, sizeof(int));
    TreeNode *bestRoot = createTreeNode(start, heuristic[start]);
    ListNode *orderHead = NULL, *orderTail = NULL;

    /* Build Best-First Tree */
    buildBestFirstTree(g, start, heuristic, visited, bestRoot, &orderHead, &orderTail);

    /* Render Tree */
    printf("\nBest-First Search Tree:\n\n");
    printf("%d (h=%d)\n", start, heuristic[start]);
    ChildNode *child = bestRoot->childrenHead;
    while (child) {
        displayTree(child->node, "", child->next == NULL);
        child = child->next;
    }

    /* Print traversal order */
    printf("\nBest-First Search Traversal Order: ");
    ListNode *curr = orderHead;
    while (curr) {
        printf("%d ", curr->vertex);
        curr = curr->next;
    }
    printf("\n");

    /* Free all resources */
    free(visited);
    free(heuristic);
    freeOrderList(orderHead);
    freeTree(bestRoot);
    freeGraph(g);

    return 0;
}