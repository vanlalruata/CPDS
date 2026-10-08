#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

/* --- Weighted Adjacency List for Directed Graphs --- */
typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode *next;
} AdjListNode;

typedef struct Graph {
    int numVertices;
    AdjListNode **fwdAdj;
    AdjListNode **bwdAdj;
} Graph;

/* --- Multi-way Tree Node for Forward and Backward Search Trees --- */
typedef struct ChildNode ChildNode;

typedef struct TreeNode {
    int vertex;
    int cost;          /* Cumulative path cost g(n) */
    int edgeWeight;    /* Incoming tree edge weight */
    ChildNode *childrenHead;
    ChildNode *childrenTail;
} TreeNode;

struct ChildNode {
    TreeNode *node;
    struct ChildNode *next;
};

/* --- Sorted Priority Queue Node (Keyed on gVal) --- */
typedef struct PQNode {
    int vertex;
    int gVal;
    TreeNode *parentTree;
    int edgeWeight;
    struct PQNode *next;
} PQNode;

/* --- Path Linked List --- */
typedef struct PathNode {
    int vertex;
    struct PathNode *next;
} PathNode;

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
    g->fwdAdj = (AdjListNode**)calloc(vertices, sizeof(AdjListNode*));
    g->bwdAdj = (AdjListNode**)calloc(vertices, sizeof(AdjListNode*));
    return g;
}

void addDirectedEdge(Graph *g, int src, int dest, int weight) {
    AdjListNode *fwd = createAdjNode(dest, weight);
    fwd->next = g->fwdAdj[src];
    g->fwdAdj[src] = fwd;

    AdjListNode *bwd = createAdjNode(src, weight);
    bwd->next = g->bwdAdj[dest];
    g->bwdAdj[dest] = bwd;
}

TreeNode* createTreeNode(int vertex, int cost, int edgeWeight) {
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    t->vertex = vertex;
    t->cost = cost;
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

/* --- Linked List Min-Priority Queue Operations --- */
void pqPush(PQNode **head, int vertex, int gVal, TreeNode *parentTree, int edgeWeight) {
    PQNode *newNode = (PQNode*)malloc(sizeof(PQNode));
    newNode->vertex = vertex;
    newNode->gVal = gVal;
    newNode->parentTree = parentTree;
    newNode->edgeWeight = edgeWeight;
    newNode->next = NULL;

    if (*head == NULL || gVal < (*head)->gVal) {
        newNode->next = *head;
        *head = newNode;
    } else {
        PQNode *curr = *head;
        while (curr->next != NULL && curr->next->gVal <= gVal) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

PQNode pqPop(PQNode **head) {
    PQNode res = { -1, INF, NULL, 0, NULL };
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

int pqMinKey(PQNode *head) {
    if (head == NULL) return INF;
    return head->gVal;
}

/* --- Visual Tree Display with Bridging Node Highlights --- */
void displayTree(TreeNode *root, const char *prefix, int isLast, int bridgeU, int bridgeV) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (root->vertex == bridgeU || root->vertex == bridgeV)
        printf("%d [cost: %d, edge: %d] <-- [BRIDGE NODE]\n", root->vertex, root->cost, root->edgeWeight);
    else
        printf("%d [cost: %d, edge: %d]\n", root->vertex, root->cost, root->edgeWeight);

    char newPrefix[512];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    ChildNode *curr = root->childrenHead;
    while (curr) {
        displayTree(curr->node, newPrefix, curr->next == NULL, bridgeU, bridgeV);
        curr = curr->next;
    }
}

/* --- Reconstruct Shortest Path Through the Optimal Bridge Edge --- */
void printOptimalPath(int *parentFwd, int *parentBwd, int src, int goal, int uStar, int vStar, int totalCost) {
    PathNode *head = NULL;

    /* Build backward chain: from goal back to vStar */
    int curr = goal;
    while (curr != -1) {
        PathNode *node = (PathNode*)malloc(sizeof(PathNode));
        node->vertex = curr;
        node->next = head;
        head = node;
        if (curr == vStar) break;
        curr = parentBwd[curr];
    }

    /* Reverse the backward segment so it flows from vStar to goal */
    PathNode *prev = NULL, *bwdHead = head, *nxt = NULL;
    while (bwdHead) {
        nxt = bwdHead->next;
        bwdHead->next = prev;
        prev = bwdHead;
        bwdHead = nxt;
    }
    PathNode *bwdList = prev;

    /* If bridge is a single node (uStar == vStar), drop the duplicate head */
    if (uStar == vStar && bwdList != NULL) {
        PathNode *dup = bwdList;
        bwdList = bwdList->next;
        free(dup);
    }

    /* Build forward chain: from uStar back to src */
    head = bwdList;
    curr = uStar;
    while (curr != -1) {
        PathNode *node = (PathNode*)malloc(sizeof(PathNode));
        node->vertex = curr;
        node->next = head;
        head = node;
        if (curr == src) break;
        curr = parentFwd[curr];
    }

    printf("\nUnified Shortest Path: ");
    PathNode *p = head;
    while (p) {
        printf("%d", p->vertex);
        if (p->next) printf(" -> ");
        p = p->next;
    }
    printf("\nOptimal Total Cost: %d\n", totalCost);

    while (head) {
        PathNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

/* --- Memory Cleanup Helpers --- */
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
        AdjListNode *curr = g->fwdAdj[i];
        while (curr) {
            AdjListNode *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        curr = g->bwdAdj[i];
        while (curr) {
            AdjListNode *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(g->fwdAdj);
    free(g->bwdAdj);
    free(g);
}

/* --- Main Driver --- */
int main(void) {
    int vertices, edges;
    int src, dest, weight, start, goal;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) return 1;

    Graph *g = createGraph(vertices);

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

    int *distFwd = (int*)malloc(vertices * sizeof(int));
    int *distBwd = (int*)malloc(vertices * sizeof(int));
    int *settledFwd = (int*)calloc(vertices, sizeof(int));
    int *settledBwd = (int*)calloc(vertices, sizeof(int));
    int *parentFwd = (int*)malloc(vertices * sizeof(int));
    int *parentBwd = (int*)malloc(vertices * sizeof(int));

    TreeNode **treeMapFwd = (TreeNode**)calloc(vertices, sizeof(TreeNode*));
    TreeNode **treeMapBwd = (TreeNode**)calloc(vertices, sizeof(TreeNode*));

    for (int i = 0; i < vertices; i++) {
        distFwd[i] = INF;
        distBwd[i] = INF;
        parentFwd[i] = -1;
        parentBwd[i] = -1;
    }

    PQNode *pqFwd = NULL;
    PQNode *pqBwd = NULL;

    distFwd[start] = 0;
    TreeNode *fwdRoot = createTreeNode(start, 0, 0);
    treeMapFwd[start] = fwdRoot;
    pqPush(&pqFwd, start, 0, NULL, 0);

    distBwd[goal] = 0;
    TreeNode *bwdRoot = createTreeNode(goal, 0, 0);
    treeMapBwd[goal] = bwdRoot;
    pqPush(&pqBwd, goal, 0, NULL, 0);

    int mu = INF;
    int bestU = -1, bestV = -1;

    if (start == goal) {
        mu = 0;
        bestU = start;
        bestV = goal;
    }

    while (!isPQEmpty(pqFwd) && !isPQEmpty(pqBwd)) {
        /* Termination Condition: top keys sum exceeds shortest path candidate mu */
        if (pqMinKey(pqFwd) + pqMinKey(pqBwd) >= mu) {
            break;
        }

        /* 1. Expand Forward Step */
        PQNode curFwd = pqPop(&pqFwd);
        int uFwd = curFwd.vertex;

        if (!settledFwd[uFwd]) {
            settledFwd[uFwd] = 1;

            if (curFwd.parentTree != NULL) {
                TreeNode *tNode = createTreeNode(uFwd, curFwd.gVal, curFwd.edgeWeight);
                addChild(curFwd.parentTree, tNode);
                treeMapFwd[uFwd] = tNode;
            }

            /* Relax forward edges */
            AdjListNode *edge = g->fwdAdj[uFwd];
            while (edge) {
                int v = edge->dest;
                int w = edge->weight;

                if (!settledFwd[v] && distFwd[uFwd] + w < distFwd[v]) {
                    distFwd[v] = distFwd[uFwd] + w;
                    parentFwd[v] = uFwd;
                    pqPush(&pqFwd, v, distFwd[v], treeMapFwd[uFwd], w);
                }

                /* Check connecting edge for potential mu update */
                if (settledBwd[v] && distFwd[uFwd] + w + distBwd[v] < mu) {
                    mu = distFwd[uFwd] + w + distBwd[v];
                    bestU = uFwd;
                    bestV = v;
                }
                edge = edge->next;
            }

            if (settledBwd[uFwd] && distFwd[uFwd] + distBwd[uFwd] < mu) {
                mu = distFwd[uFwd] + distBwd[uFwd];
                bestU = uFwd;
                bestV = uFwd;
            }
        }

        /* 2. Expand Backward Step */
        PQNode curBwd = pqPop(&pqBwd);
        int uBwd = curBwd.vertex;

        if (!settledBwd[uBwd]) {
            settledBwd[uBwd] = 1;

            if (curBwd.parentTree != NULL) {
                TreeNode *tNode = createTreeNode(uBwd, curBwd.gVal, curBwd.edgeWeight);
                addChild(curBwd.parentTree, tNode);
                treeMapBwd[uBwd] = tNode;
            }

            /* Relax backward edges (incoming original edges) */
            AdjListNode *edge = g->bwdAdj[uBwd];
            while (edge) {
                int v = edge->dest;
                int w = edge->weight;

                if (!settledBwd[v] && distBwd[uBwd] + w < distBwd[v]) {
                    distBwd[v] = distBwd[uBwd] + w;
                    parentBwd[v] = uBwd;
                    pqPush(&pqBwd, v, distBwd[v], treeMapBwd[uBwd], w);
                }

                /* Check reverse connecting edge (v -> uBwd in original graph) */
                if (settledFwd[v] && distFwd[v] + w + distBwd[uBwd] < mu) {
                    mu = distFwd[v] + w + distBwd[uBwd];
                    bestU = v;
                    bestV = uBwd;
                }
                edge = edge->next;
            }

            if (settledFwd[uBwd] && distFwd[uBwd] + distBwd[uBwd] < mu) {
                mu = distFwd[uBwd] + distBwd[uBwd];
                bestU = uBwd;
                bestV = uBwd;
            }
        }
    }

    if (mu >= INF) {
        printf("\nNo connecting path exists between %d and %d.\n", start, goal);
    } else {
        printf("\n=========================================\n");
        printf("    BIDIRECTIONAL DIJKSTRA RESULTS       \n");
        printf("=========================================\n");
        if (bestU == bestV)
            printf("Optimal meeting point: Node %d (Shortest Cost: %d)\n", bestU, mu);
        else
            printf("Optimal bridging edge: (%d -> %d) (Shortest Cost: %d)\n", bestU, bestV, mu);

        printf("\n1. Forward Shortest-Path Tree (Source %d):\n\n", start);
        displayTree(fwdRoot, "", 1, bestU, bestV);

        printf("\n2. Backward Shortest-Path Tree (Goal %d):\n\n", goal);
        displayTree(bwdRoot, "", 1, bestU, bestV);

        printOptimalPath(parentFwd, parentBwd, start, goal, bestU, bestV, mu);
    }

    /* Cleanup priority queues */
    while (!isPQEmpty(pqFwd)) pqPop(&pqFwd);
    while (!isPQEmpty(pqBwd)) pqPop(&pqBwd);

    /* Free allocations */
    free(distFwd);
    free(distBwd);
    free(settledFwd);
    free(settledBwd);
    free(parentFwd);
    free(parentBwd);
    free(treeMapFwd);
    free(treeMapBwd);
    freeTree(fwdRoot);
    freeTree(bwdRoot);
    freeGraph(g);

    return 0;
}