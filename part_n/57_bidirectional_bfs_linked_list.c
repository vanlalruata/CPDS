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
    AdjListNode **fwdAdjLists;
    AdjListNode **bwdAdjLists;
} Graph;

/* --- Multi-way Tree Node for Search Trees --- */
typedef struct ChildNode ChildNode;

typedef struct TreeNode {
    int vertex;
    ChildNode *childrenHead;
    ChildNode *childrenTail;
} TreeNode;

struct ChildNode {
    TreeNode *node;
    struct ChildNode *next;
};

/* --- Linked List Queue Node & Queue --- */
typedef struct QueueNode {
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

/* --- Linked List for Path Output --- */
typedef struct PathNode {
    int vertex;
    struct PathNode *next;
} PathNode;

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
    g->fwdAdjLists = (AdjListNode**)calloc(vertices, sizeof(AdjListNode*));
    g->bwdAdjLists = (AdjListNode**)calloc(vertices, sizeof(AdjListNode*));
    return g;
}

void addEdge(Graph *g, int src, int dest) {
    /* Forward edge: src -> dest */
    AdjListNode *fwdNode = createAdjNode(dest);
    fwdNode->next = g->fwdAdjLists[src];
    g->fwdAdjLists[src] = fwdNode;

    /* Backward reverse edge: dest -> src */
    AdjListNode *bwdNode = createAdjNode(src);
    bwdNode->next = g->bwdAdjLists[dest];
    g->bwdAdjLists[dest] = bwdNode;
}

TreeNode* createTreeNode(int vertex) {
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    t->vertex = vertex;
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

/* --- Dynamic Queue Operations --- */
Queue* createQueue(void) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, TreeNode *node) {
    QueueNode *qn = (QueueNode*)malloc(sizeof(QueueNode));
    qn->treeNode = node;
    qn->next = NULL;
    if (q->rear == NULL) {
        q->front = qn;
        q->rear = qn;
    } else {
        q->rear->next = qn;
        q->rear = qn;
    }
}

TreeNode* dequeue(Queue *q) {
    if (isQueueEmpty(q)) return NULL;
    QueueNode *temp = q->front;
    TreeNode *res = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return res;
}

/* --- Visual Tree Display with Intersection Highlighting --- */
void displayTree(TreeNode *root, const char *prefix, int isLast, int intersectNode) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (root->vertex == intersectNode)
        printf("%d [INTERSECTION POINT]\n", root->vertex);
    else
        printf("%d\n", root->vertex);

    char newPrefix[512];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    ChildNode *curr = root->childrenHead;
    while (curr) {
        displayTree(curr->node, newPrefix, curr->next == NULL, intersectNode);
        curr = curr->next;
    }
}

/* --- Path Reconstructor Using Linked List --- */
void reconstructPath(int *fwdParent, int *bwdParent, int src, int goal, int meet) {
    PathNode *head = NULL;

    /* Build backward chain: meet -> goal */
    int curr = bwdParent[meet];
    while (curr != -1) {
        PathNode *node = (PathNode*)malloc(sizeof(PathNode));
        node->vertex = curr;
        node->next = head;
        head = node;
        curr = bwdParent[curr];
    }

    /* Reverse backward segment in-place so it flows meet -> ... -> goal */
    PathNode *prev = NULL, *bwdHead = head, *nxt = NULL;
    while (bwdHead) {
        nxt = bwdHead->next;
        bwdHead->next = prev;
        prev = bwdHead;
        bwdHead = nxt;
    }
    PathNode *bwdList = prev;

    /* Prepend meeting node */
    PathNode *meetNode = (PathNode*)malloc(sizeof(PathNode));
    meetNode->vertex = meet;
    meetNode->next = bwdList;
    head = meetNode;

    /* Prepend forward chain: source -> meet */
    curr = fwdParent[meet];
    while (curr != -1) {
        PathNode *node = (PathNode*)malloc(sizeof(PathNode));
        node->vertex = curr;
        node->next = head;
        head = node;
        curr = fwdParent[curr];
    }

    /* Print reconstructed path */
    printf("\nUnified Shortest Path: ");
    PathNode *p = head;
    int edges = 0;
    while (p) {
        printf("%d", p->vertex);
        if (p->next) {
            printf(" -> ");
            edges++;
        }
        p = p->next;
    }
    printf(" (Length: %d edges)\n", edges);

    /* Free linked list path */
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
        AdjListNode *curr = g->fwdAdjLists[i];
        while (curr) {
            AdjListNode *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        curr = g->bwdAdjLists[i];
        while (curr) {
            AdjListNode *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(g->fwdAdjLists);
    free(g->bwdAdjLists);
    free(g);
}

/* --- Main Driver --- */
int main(void) {
    int vertices, edges;
    int src, dest, start, goal;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) return 1;

    Graph *g = createGraph(vertices);

    printf("Enter number of directed edges: ");
    if (scanf("%d", &edges) != 1) return 1;

    printf("Enter each edge as (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }

    printf("Enter Source vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);
    printf("Enter Goal vertex (0 to %d): ", vertices - 1);
    scanf("%d", &goal);

    int *visitedFwd = (int*)calloc(vertices, sizeof(int));
    int *visitedBwd = (int*)calloc(vertices, sizeof(int));
    int *parentFwd = (int*)malloc(vertices * sizeof(int));
    int *parentBwd = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        parentFwd[i] = -1;
        parentBwd[i] = -1;
    }

    TreeNode *fwdRoot = createTreeNode(start);
    TreeNode *bwdRoot = createTreeNode(goal);

    Queue *qFwd = createQueue();
    Queue *qBwd = createQueue();

    visitedFwd[start] = 1;
    visitedBwd[goal] = 1;
    enqueue(qFwd, fwdRoot);
    enqueue(qBwd, bwdRoot);

    int meetNode = -1;

    if (start == goal) {
        meetNode = start;
    }

    while (!isQueueEmpty(qFwd) && !isQueueEmpty(qBwd) && meetNode == -1) {
        /* Step Forward */
        TreeNode *currFwd = dequeue(qFwd);
        int uFwd = currFwd->vertex;

        AdjListNode *fwdEdge = g->fwdAdjLists[uFwd];
        while (fwdEdge) {
            int v = fwdEdge->dest;
            if (!visitedFwd[v]) {
                visitedFwd[v] = 1;
                parentFwd[v] = uFwd;
                TreeNode *childNode = createTreeNode(v);
                addChild(currFwd, childNode);
                enqueue(qFwd, childNode);

                if (visitedBwd[v]) {
                    meetNode = v;
                    break;
                }
            }
            fwdEdge = fwdEdge->next;
        }

        if (meetNode != -1) break;

        /* Step Backward */
        TreeNode *currBwd = dequeue(qBwd);
        int uBwd = currBwd->vertex;

        AdjListNode *bwdEdge = g->bwdAdjLists[uBwd];
        while (bwdEdge) {
            int v = bwdEdge->dest;
            if (!visitedBwd[v]) {
                visitedBwd[v] = 1;
                parentBwd[v] = uBwd;
                TreeNode *childNode = createTreeNode(v);
                addChild(currBwd, childNode);
                enqueue(qBwd, childNode);

                if (visitedFwd[v]) {
                    meetNode = v;
                    break;
                }
            }
            bwdEdge = bwdEdge->next;
        }
    }

    if (meetNode == -1) {
        printf("\nNo path exists between %d and %d.\n", start, goal);
    } else {
        printf("\n=========================================\n");
        printf("     BIDIRECTIONAL BFS RESULTS           \n");
        printf("=========================================\n");
        printf("Frontiers met at vertex: %d\n", meetNode);

        printf("\n1. Forward Tree (Source %d):\n\n", start);
        printf("%d%s\n", start, start == meetNode ? " [INTERSECTION POINT]" : "");
        ChildNode *fChild = fwdRoot->childrenHead;
        while (fChild) {
            displayTree(fChild->node, "", fChild->next == NULL, meetNode);
            fChild = fChild->next;
        }

        printf("\n2. Backward Tree (Goal %d):\n\n", goal);
        printf("%d%s\n", goal, goal == meetNode ? " [INTERSECTION POINT]" : "");
        ChildNode *bChild = bwdRoot->childrenHead;
        while (bChild) {
            displayTree(bChild->node, "", bChild->next == NULL, meetNode);
            bChild = bChild->next;
        }

        reconstructPath(parentFwd, parentBwd, start, goal, meetNode);
    }

    /* Cleanup queues */
    while (!isQueueEmpty(qFwd)) dequeue(qFwd);
    while (!isQueueEmpty(qBwd)) dequeue(qBwd);
    free(qFwd);
    free(qBwd);

    /* Free memory */
    free(visitedFwd);
    free(visitedBwd);
    free(parentFwd);
    free(parentBwd);
    freeTree(fwdRoot);
    freeTree(bwdRoot);
    freeGraph(g);

    return 0;
}