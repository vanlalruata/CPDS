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

/* --- Multi-way Tree Node for BFS Tree --- */
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

/* --- Linked List Queue Node & Queue for BFS --- */
typedef struct QueueNode {
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

/* --- Linked List Traversal Recording List --- */
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

/* --- Record Traversal Order via Linked List --- */
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

/* --- BFS Tree Construction --- */
void buildBFSTree(Graph *g, int start, int *visited, TreeNode *root,
                  ListNode **orderHead, ListNode **orderTail) {
    Queue *q = createQueue();

    visited[start] = 1;
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        TreeNode *currTree = dequeue(q);
        int u = currTree->vertex;
        appendOrder(orderHead, orderTail, u);

        AdjListNode *adj = g->adjLists[u];
        while (adj) {
            int v = adj->dest;
            if (!visited[v]) {
                visited[v] = 1;
                TreeNode *childNode = createTreeNode(v);
                addChild(currTree, childNode);
                enqueue(q, childNode);
            }
            adj = adj->next;
        }
    }

    free(q);
}

/* --- Visual Tree Display --- */
void displayTree(TreeNode *root, const char *prefix, int isLast) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    printf("%d\n", root->vertex);

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
    TreeNode *bfsRoot = createTreeNode(start);
    ListNode *orderHead = NULL, *orderTail = NULL;

    /* Build BFS Tree */
    buildBFSTree(g, start, visited, bfsRoot, &orderHead, &orderTail);

    /* Render Tree */
    printf("\nBFS Tree:\n\n");
    printf("%d\n", start);
    ChildNode *child = bfsRoot->childrenHead;
    while (child) {
        displayTree(child->node, "", child->next == NULL);
        child = child->next;
    }

    /* Print traversal recorded dynamically */
    printf("\nBFS Traversal Order: ");
    ListNode *curr = orderHead;
    while (curr) {
        printf("%d ", curr->vertex);
        curr = curr->next;
    }
    printf("\n");

    /* Free all dynamic allocations */
    free(visited);
    freeOrderList(orderHead);
    freeTree(bfsRoot);
    freeGraph(g);

    return 0;
}