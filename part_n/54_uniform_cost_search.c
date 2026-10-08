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

/* --- Multi-way Tree Node for UCS --- */
typedef struct ChildNode ChildNode;

typedef struct TreeNode {
    int vertex;
    int edgeWeight;
    int cost;          /* Cumulative path cost g(n) */
    ChildNode *childrenHead;
    ChildNode *childrenTail;
} TreeNode;

struct ChildNode {
    TreeNode *node;
    struct ChildNode *next;
};

/* --- Sorted Priority Queue Node (keyed on gVal) --- */
typedef struct PQNode {
    int vertex;
    int gVal;
    TreeNode *parentTree;
    int edgeWeight;
    struct PQNode *next;
} PQNode;

/* --- Dynamic Traversal Order List --- */
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

void addEdge(Graph *g, int src, int dest, int weight) {
    AdjListNode *newNode = createAdjNode(dest, weight);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
}

TreeNode* createTreeNode(int vertex, int edgeWeight, int cost) {
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    t->vertex = vertex;
    t->edgeWeight = edgeWeight;
    t->cost = cost;
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

    /* Insert in ascending order of cumulative path cost gVal */
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

/* --- Dynamic Traversal Logging --- */
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

/* --- UCS Tree Construction --- */
TreeNode* buildUCSTree(Graph *g, int start, ListNode **orderHead, ListNode **orderTail) {
    int *dist = (int*)malloc(g->numVertices * sizeof(int));
    int *settled = (int*)calloc(g->numVertices, sizeof(int));

    for (int i = 0; i < g->numVertices; i++) {
        dist[i] = INF;
    }

    PQNode *pq = NULL;
    dist[start] = 0;

    TreeNode *root = createTreeNode(start, 0, 0);

    /* Map each settled vertex directly to its allocated TreeNode */
    TreeNode **treeMap = (TreeNode**)calloc(g->numVertices, sizeof(TreeNode*));
    treeMap[start] = root;

    pqPush(&pq, start, 0, NULL, 0);

    while (!isPQEmpty(pq)) {
        PQNode current = pqPop(&pq);
        int u = current.vertex;

        /* Skip duplicate entries if already finalized via a shorter path */
        if (settled[u]) {
            continue;
        }

        settled[u] = 1;
        appendOrder(orderHead, orderTail, u);

        /* Connect to tree parent once settled */
        if (current.parentTree != NULL) {
            TreeNode *node = createTreeNode(u, current.edgeWeight, current.gVal);
            addChild(current.parentTree, node);
            treeMap[u] = node;
        }

        /* Relax outgoing edges */
        AdjListNode *adj = g->adjLists[u];
        while (adj) {
            int v = adj->dest;
            int weight = adj->weight;

            if (!settled[v]) {
                int newCost = current.gVal + weight;
                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    pqPush(&pq, v, newCost, treeMap[u], weight);
                }
            }
            adj = adj->next;
        }
    }

    free(dist);
    free(settled);
    free(treeMap);

    return root;
}

/* --- Visual Tree Display with Box Drawing --- */
void displayTree(TreeNode *root, const char *prefix, int isLast) {
    if (!root) return;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (root->cost == 0 && root->edgeWeight == 0)
        printf("%d [Root, g=0]\n", root->vertex);
    else
        printf("%d [edge: %d, g: %d]\n", root->vertex, root->edgeWeight, root->cost);

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

/* --- Cleanup Helpers --- */
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
    int src, dest, weight, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) return 1;

    Graph *g = createGraph(vertices);

    printf("Enter number of directed edges: ");
    if (scanf("%d", &edges) != 1) return 1;

    printf("Enter each edge as (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(g, src, dest, weight);
    }

    printf("Enter start vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    ListNode *orderHead = NULL, *orderTail = NULL;
    TreeNode *ucsRoot = buildUCSTree(g, start, &orderHead, &orderTail);

    /* Render UCS Tree */
    printf("\nUniform-Cost Search Tree:\n\n");
    printf("%d [Root, g=0]\n", start);
    ChildNode *child = ucsRoot->childrenHead;
    while (child) {
        displayTree(child->node, "", child->next == NULL);
        child = child->next;
    }

    /* Print Expansion Sequence */
    printf("\nUCS Expansion Order: ");
    ListNode *curr = orderHead;
    while (curr) {
        printf("%d ", curr->vertex);
        curr = curr->next;
    }
    printf("\n");

    /* Cleanup dynamic structures */
    freeOrderList(orderHead);
    freeTree(ucsRoot);
    freeGraph(g);

    return 0;
}