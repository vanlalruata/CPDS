#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

/* --- Weighted Adjacency List for Graph --- */
typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode *next;
} AdjListNode;

typedef struct Graph {
    int numVertices;
    AdjListNode **adjLists;
} Graph;

/* --- Multi-way Tree Node for A* Search Tree --- */
typedef struct ChildNode ChildNode;

typedef struct TreeNode {
    int vertex;
    int gVal;          /* Cost from start */
    int hVal;          /* Estimated cost to goal */
    int fVal;          /* Total estimated cost f = g + h */
    int edgeWeight;    /* Incoming branch cost */
    ChildNode *childrenHead;
    ChildNode *childrenTail;
} TreeNode;

struct ChildNode {
    TreeNode *node;
    struct ChildNode *next;
};

/* --- Sorted Linked List Priority Queue (Keyed on fVal) --- */
typedef struct PQNode {
    int vertex;
    int gVal;
    int fVal;
    int edgeWeight;
    TreeNode *parentTree;
    struct PQNode *next;
} PQNode;

/* --- Dynamic Linked List for Optimal Path Output --- */
typedef struct PathNode {
    int vertex;
    struct PathNode *next;
} PathNode;

/* --- Traversal Record List --- */
typedef struct ListNode {
    int vertex;
    struct ListNode *next;
} ListNode;

/* --- Allocators & Graph Helpers --- */
AdjListNode* createAdjNode(int dest, int weight) {
    AdjListNode *newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->numVertices = vertices;
    g->adjLists = (AdjListNode**)calloc(vertices, sizeof(AdjListNode*));
    return g;
}

void addDirectedEdge(Graph *g, int src, int dest, int weight) {
    AdjListNode *newNode = createAdjNode(dest, weight);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
}

TreeNode* createTreeNode(int vertex, int gVal, int hVal, int edgeWeight) {
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    t->vertex = vertex;
    t->gVal = gVal;
    t->hVal = hVal;
    t->fVal = gVal + hVal;
    t->edgeWeight = edgeWeight;
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
void pqPush(PQNode **head, int vertex, int gVal, int fVal, int edgeWeight, TreeNode *parentTree) {
    PQNode *newNode = (PQNode*)malloc(sizeof(PQNode));
    newNode->vertex = vertex;
    newNode->gVal = gVal;
    newNode->fVal = fVal;
    newNode->edgeWeight = edgeWeight;
    newNode->parentTree = parentTree;
    newNode->next = NULL;

    /* Sort ascending by fVal; if tied, favor larger gVal (closer to goal) */
    if (*head == NULL || fVal < (*head)->fVal || (fVal == (*head)->fVal && gVal > (*head)->gVal)) {
        newNode->next = *head;
        *head = newNode;
    } else {
        PQNode *curr = *head;
        while (curr->next != NULL && 
              (curr->next->fVal < fVal || (curr->next->fVal == fVal && curr->next->gVal >= gVal))) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

PQNode pqPop(PQNode **head) {
    PQNode res = { -1, INF, INF, 0, NULL, NULL };
    if (*head == NULL) return res;

    PQNode *temp = *head;
    res = *temp;
    *head = (*head)->next;
    free(temp);
    return res;
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

/* --- Visual Tree Display with f = g + h Annotations --- */
void displayTree(TreeNode *root, const char *prefix, int isLast, int goal) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (root->vertex == goal)
        printf("%d [f: %d, g: %d, h: %d] <-- [GOAL REACHED]\n", root->vertex, root->fVal, root->gVal, root->hVal);
    else
        printf("%d [f: %d, g: %d, h: %d, edge: %d]\n", root->vertex, root->fVal, root->gVal, root->hVal, root->edgeWeight);

    char newPrefix[512];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    ChildNode *curr = root->childrenHead;
    while (curr) {
        displayTree(curr->node, newPrefix, curr->next == NULL, goal);
        curr = curr->next;
    }
}

/* --- Optimal Path Printer --- */
void printPath(int *parent, int start, int goal, int totalCost) {
    PathNode *head = NULL;
    int curr = goal;

    while (curr != -1) {
        PathNode *node = (PathNode*)malloc(sizeof(PathNode));
        node->vertex = curr;
        node->next = head;
        head = node;
        if (curr == start) break;
        curr = parent[curr];
    }

    printf("\nOptimal Path: ");
    PathNode *p = head;
    while (p) {
        printf("%d", p->vertex);
        if (p->next) printf(" -> ");
        p = p->next;
    }
    printf("\nTotal Path Cost g(Goal): %d\n", totalCost);

    while (head) {
        PathNode *tmp = head;
        head = head->next;
        free(tmp);
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
    int src, dest, weight, start, goal;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) return 1;

    Graph *g = createGraph(vertices);
    int *h = (int*)malloc(vertices * sizeof(int));

    printf("Enter heuristic values h(n) towards the goal for each node (0 to %d):\n", vertices - 1);
    for (int i = 0; i < vertices; i++) {
        printf("h(%d): ", i);
        scanf("%d", &h[i]);
    }

    printf("Enter number of directed edges: ");
    if (scanf("%d", &edges) != 1) return 1;

    printf("Enter each edge as (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addDirectedEdge(g, src, dest, weight);
    }

    printf("Enter Source vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);
    printf("Enter Goal vertex (0 to %d): ", vertices - 1);
    scanf("%d", &goal);

    int *gCost = (int*)malloc(vertices * sizeof(int));
    int *settled = (int*)calloc(vertices, sizeof(int));
    int *parent = (int*)malloc(vertices * sizeof(int));
    TreeNode **treeMap = (TreeNode**)calloc(vertices, sizeof(TreeNode*));

    for (int i = 0; i < vertices; i++) {
        gCost[i] = INF;
        parent[i] = -1;
    }

    PQNode *pq = NULL;
    ListNode *orderHead = NULL, *orderTail = NULL;

    gCost[start] = 0;
    TreeNode *aStarRoot = createTreeNode(start, 0, h[start], 0);
    treeMap[start] = aStarRoot;

    pqPush(&pq, start, 0, 0 + h[start], 0, NULL);

    int goalFound = 0;

    while (!isPQEmpty(pq)) {
        PQNode cur = pqPop(&pq);
        int u = cur.vertex;

        if (settled[u]) continue;

        settled[u] = 1;
        appendOrder(&orderHead, &orderTail, u);

        if (cur.parentTree != NULL) {
            TreeNode *node = createTreeNode(u, cur.gVal, h[u], cur.edgeWeight);
            addChild(cur.parentTree, node);
            treeMap[u] = node;
        }

        /* Optimal termination upon expanding the goal node */
        if (u == goal) {
            goalFound = 1;
            break;
        }

        /* Relax outgoing edges */
        AdjListNode *edge = g->adjLists[u];
        while (edge) {
            int v = edge->dest;
            int w = edge->weight;

            if (!settled[v]) {
                int tentativeG = gCost[u] + w;
                if (tentativeG < gCost[v]) {
                    gCost[v] = tentativeG;
                    parent[v] = u;
                    int fVal = tentativeG + h[v];
                    pqPush(&pq, v, tentativeG, fVal, w, treeMap[u]);
                }
            }
            edge = edge->next;
        }
    }

    if (!goalFound && start != goal) {
        printf("\nNo path found from %d to %d.\n", start, goal);
    } else {
        printf("\n=========================================\n");
        printf("              A* SEARCH TREE             \n");
        printf("=========================================\n\n");
        displayTree(aStarRoot, "", 1, goal);

        printf("\nA* Expansion Order: ");
        ListNode *curr = orderHead;
        while (curr) {
            printf("%d ", curr->vertex);
            curr = curr->next;
        }
        printf("\n");

        printPath(parent, start, goal, gCost[goal]);
    }

    /* Cleanup remaining items */
    while (!isPQEmpty(pq)) pqPop(&pq);
    freeOrderList(orderHead);
    free(gCost);
    free(settled);
    free(parent);
    free(treeMap);
    free(h);
    freeTree(aStarRoot);
    freeGraph(g);

    return 0;
}