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

/* --- Multi-way Tree Node for IDDFS Iterations --- */
typedef struct ChildNode ChildNode;

typedef struct TreeNode {
    int vertex;
    int depth;
    int isCutoff;
    ChildNode *childrenHead;
    ChildNode *childrenTail;
} TreeNode;

struct ChildNode {
    TreeNode *node;
    struct ChildNode *next;
};

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

TreeNode* createTreeNode(int vertex, int depth) {
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    t->vertex = vertex;
    t->depth = depth;
    t->isCutoff = 0;
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

/* --- Deallocation Helpers --- */
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

void freeOrderList(ListNode *head) {
    while (head) {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
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

/* --- Visual Tree Display with Box Drawing --- */
void displayTree(TreeNode *root, const char *prefix, int isLast) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (root->isCutoff)
        printf("%d (depth: %d) [Cutoff/Pruned]\n", root->vertex, root->depth);
    else
        printf("%d (depth: %d)\n", root->vertex, root->depth);

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

/* --- Core Depth-Limited Subroutine for IDDFS --- */
void runDLS(Graph *g, int u, int currentDepth, int limit,
            int *visited, TreeNode *currTree,
            ListNode **orderHead, ListNode **orderTail, int *anyCutoff) {
    visited[u] = 1;
    appendOrder(orderHead, orderTail, u);

    if (currentDepth >= limit) {
        AdjListNode *probe = g->adjLists[u];
        while (probe) {
            if (!visited[probe->dest]) {
                currTree->isCutoff = 1;
                *anyCutoff = 1;
                break;
            }
            probe = probe->next;
        }
        return;
    }

    AdjListNode *curr = g->adjLists[u];
    while (curr) {
        int v = curr->dest;
        if (!visited[v]) {
            TreeNode *childNode = createTreeNode(v, currentDepth + 1);
            addChild(currTree, childNode);
            runDLS(g, v, currentDepth + 1, limit, visited, childNode, orderHead, orderTail, anyCutoff);
        }
        curr = curr->next;
    }
}

/* --- Main Driver --- */
int main(void) {
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) return 1;

    Graph *g = createGraph(vertices);

    printf("Enter number of edges: ");
    if (scanf("%d", &edges) != 1) return 1;

    printf("Enter each edge as (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }

    printf("Enter start vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    printf("\n=========================================\n");
    printf("  ITERATIVE DEEPENING DFS (IDDFS) TRACE  \n");
    printf("=========================================\n");

    /* Increment limit from 0 up to vertices - 1 */
    for (int limit = 0; limit < vertices; limit++) {
        int *visited = (int*)calloc(vertices, sizeof(int));
        TreeNode *root = createTreeNode(start, 0);
        ListNode *orderHead = NULL, *orderTail = NULL;
        int anyCutoff = 0;

        /* Execute DLS for current depth iteration */
        runDLS(g, start, 0, limit, visited, root, &orderHead, &orderTail, &anyCutoff);

        printf("\n-----------------------------------------\n");
        printf(">>> ITERATION: Depth Limit = %d\n", limit);
        printf("-----------------------------------------\n\n");

        printf("%d (depth: 0)%s\n", start, root->isCutoff ? " [Cutoff/Pruned]" : "");
        ChildNode *child = root->childrenHead;
        while (child) {
            displayTree(child->node, "", child->next == NULL);
            child = child->next;
        }

        printf("\nTraversal Order (Limit %d): ", limit);
        ListNode *curr = orderHead;
        while (curr) {
            printf("%d ", curr->vertex);
            curr = curr->next;
        }
        printf("\n");

        /* Deallocate resources for this iteration */
        free(visited);
        freeTree(root);
        freeOrderList(orderHead);

        /* Early stop if no edge was pruned */
        if (!anyCutoff) {
            printf("\n[Notice] No branches pruned at depth %d. Entire reachable subgraph explored.\n", limit);
            break;
        }
    }

    freeGraph(g);
    return 0;
}