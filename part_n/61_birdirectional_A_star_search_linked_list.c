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
    AdjListNode **fwdAdj;
    AdjListNode **bwdAdj;
} Graph;

/* --- Multi-way Tree Node for Forward & Backward Trees --- */
typedef struct ChildNode ChildNode;

typedef struct TreeNode {
    int vertex;
    int gVal;
    int hVal;
    int fVal;
    int edgeWeight;
    ChildNode *childrenHead;
    ChildNode *childrenTail;
} TreeNode;

struct ChildNode {
    TreeNode *node;
    struct ChildNode *next;
};

/* --- Sorted Linked List Priority Queue Node (Keyed on fVal) --- */
typedef struct PQNode {
    int vertex;
    int gVal;
    int fVal;
    int edgeWeight;
    TreeNode *parentTree;
    struct PQNode *next;
} PQNode;

/* --- Linked List for Path Output --- */
typedef struct PathNode {
    int vertex;
    struct PathNode *next;
} PathNode;

/* --- Allocators & Helpers --- */
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

    /* Sort ascending by fVal; break ties with larger gVal */
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

int pqMinKey(PQNode *head) {
    if (head == NULL) return INF;
    return head->fVal;
}

/* --- Visual Tree Display with Bridging Node Identification --- */
void displayTree(TreeNode *root, const char *prefix, int isLast, int bridgeU, int bridgeV) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (root->vertex == bridgeU || root->vertex == bridgeV)
        printf("%d [f: %d, g: %d, h: %d] <-- [BRIDGE NODE]\n", root->vertex, root->fVal, root->gVal, root->hVal);
    else
        printf("%d [f: %d, g: %d, h: %d, edge: %d]\n", root->vertex, root->fVal, root->gVal, root->hVal, root->edgeWeight);

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

/* --- Reconstruct and Display Path --- */
void printOptimalPath(int *parentFwd, int *parentBwd, int src, int goal, int uStar, int vStar, int totalCost) {
    PathNode *head = NULL;

    /* Build backward chain: from goal to vStar */
    int curr = goal;
    while (curr != -1) {
        PathNode *node = (PathNode*)malloc(sizeof(PathNode));
        node->vertex = curr;
        node->next = head;
        head = node;
        if (curr == vStar) break;
        curr = parentBwd[curr];
    }

    /* Reverse backward segment so it flows vStar -> ... -> goal */
    PathNode *prev = NULL, *bwdHead = head, *nxt = NULL;
    while (bwdHead) {
        nxt = bwdHead->next;
        bwdHead->next = prev;
        prev = bwdHead;
        bwdHead = nxt;
    }
    PathNode *bwdList = prev;

    /* If bridge is a single meeting node, avoid duplicating it */
    if (uStar == vStar && bwdList != NULL) {
        PathNode *dup = bwdList;
        bwdList = bwdList->next;
        free(dup);
    }

    /* Prepend forward chain: uStar back to src */
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

    int *hFwd = (int*)malloc(vertices * sizeof(int));
    int *hBwd = (int*)malloc(vertices * sizeof(int));

    printf("Enter forward heuristic hF(n) towards Goal for each vertex (0 to %d):\n", vertices - 1);
    for (int i = 0; i < vertices; i++) {
        printf("hF(%d): ", i);
        scanf("%d", &hFwd[i]);
    }

    printf("Enter backward heuristic hB(n) towards Start for each vertex (0 to %d):\n", vertices - 1);
    for (int i = 0; i < vertices; i++) {
        printf("hB(%d): ", i);
        scanf("%d", &hBwd[i]);
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
    TreeNode *fwdRoot = createTreeNode(start, 0, hFwd[start], 0);
    treeMapFwd[start] = fwdRoot;
    pqPush(&pqFwd, start, 0, 0 + hFwd[start], 0, NULL);

    distBwd[goal] = 0;
    TreeNode *bwdRoot = createTreeNode(goal, 0, hBwd[goal], 0);
    treeMapBwd[goal] = bwdRoot;
    pqPush(&pqBwd, goal, 0, 0 + hBwd[goal], 0, NULL);

    int mu = INF;
    int bestU = -1, bestV = -1;

    if (start == goal) {
        mu = 0;
        bestU = start;
        bestV = goal;
    }

    while (!isPQEmpty(pqFwd) && !isPQEmpty(pqBwd)) {
        int minF_Fwd = pqMinKey(pqFwd);
        int minF_Bwd = pqMinKey(pqBwd);

        /* Stopping condition: lower bound of unexplored paths meets or exceeds mu */
        if (minF_Fwd >= mu || minF_Bwd >= mu || (minF_Fwd + minF_Bwd >= mu)) {
            break;
        }

        /* 1. Step Forward */
        PQNode curFwd = pqPop(&pqFwd);
        int uFwd = curFwd.vertex;

        if (!settledFwd[uFwd]) {
            settledFwd[uFwd] = 1;

            if (curFwd.parentTree != NULL) {
                TreeNode *tNode = createTreeNode(uFwd, curFwd.gVal, hFwd[uFwd], curFwd.edgeWeight);
                addChild(curFwd.parentTree, tNode);
                treeMapFwd[uFwd] = tNode;
            }

            AdjListNode *edge = g->fwdAdj[uFwd];
            while (edge) {
                int v = edge->dest;
                int w = edge->weight;

                if (!settledFwd[v] && distFwd[uFwd] + w < distFwd[v]) {
                    distFwd[v] = distFwd[uFwd] + w;
                    parentFwd[v] = uFwd;
                    int fVal = distFwd[v] + hFwd[v];
                    pqPush(&pqFwd, v, distFwd[v], fVal, w, treeMapFwd[uFwd]);
                }

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

        /* 2. Step Backward */
        PQNode curBwd = pqPop(&pqBwd);
        int uBwd = curBwd.vertex;

        if (!settledBwd[uBwd]) {
            settledBwd[uBwd] = 1;

            if (curBwd.parentTree != NULL) {
                TreeNode *tNode = createTreeNode(uBwd, curBwd.gVal, hBwd[uBwd], curBwd.edgeWeight);
                addChild(curBwd.parentTree, tNode);
                treeMapBwd[uBwd] = tNode;
            }

            AdjListNode *edge = g->bwdAdj[uBwd];
            while (edge) {
                int v = edge->dest;
                int w = edge->weight;

                if (!settledBwd[v] && distBwd[uBwd] + w < distBwd[v]) {
                    distBwd[v] = distBwd[uBwd] + w;
                    parentBwd[v] = uBwd;
                    int fVal = distBwd[v] + hBwd[v];
                    pqPush(&pqBwd, v, distBwd[v], fVal, w, treeMapBwd[uBwd]);
                }

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
        printf("       BIDIRECTIONAL A* RESULTS          \n");
        printf("=========================================\n");
        if (bestU == bestV)
            printf("Optimal meeting point: Node %d (Cost: %d)\n", bestU, mu);
        else
            printf("Optimal bridging edge: (%d -> %d) (Cost: %d)\n", bestU, bestV, mu);

        printf("\n1. Forward A* Tree (Source %d):\n\n", start);
        displayTree(fwdRoot, "", 1, bestU, bestV);

        printf("\n2. Backward A* Tree (Goal %d):\n\n", goal);
        displayTree(bwdRoot, "", 1, bestU, bestV);

        printOptimalPath(parentFwd, parentBwd, start, goal, bestU, bestV, mu);
    }

    /* Cleanup queues */
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
    free(hFwd);
    free(hBwd);
    freeTree(fwdRoot);
    freeTree(bwdRoot);
    freeGraph(g);

    return 0;
}