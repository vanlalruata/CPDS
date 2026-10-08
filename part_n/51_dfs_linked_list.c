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

/* --- Multi-way Tree Node for DFS Tree --- */
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

/* --- Helper Allocators --- */
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

/* --- DFS Tree Construction --- */
void buildDFSTree(Graph *g, int u, int *visited, TreeNode *currTreeNode) {
    visited[u] = 1;

    AdjListNode *curr = g->adjLists[u];
    while (curr) {
        int v = curr->dest;
        if (!visited[v]) {
            TreeNode *childNode = createTreeNode(v);
            addChild(currTreeNode, childNode);
            buildDFSTree(g, v, visited, childNode);
        }
        curr = curr->next;
    }
}

/* --- Dynamic Visual Tree Display --- */
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

/* --- DFS Traversal Print --- */
void printDFS(TreeNode *root) {
    if (!root) return;
    printf("%d ", root->vertex);
    ChildNode *curr = root->childrenHead;
    while (curr) {
        printDFS(curr->node);
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

/* --- Main Driver --- */
int main(void) {
    int vertices, edges;
    int src, dest, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0) return 1;

    Graph *g = createGraph(vertices);

    printf("Enter number of directed/undirected edges: ");
    if (scanf("%d", &edges) != 1) return 1;

    printf("Enter each edge as (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }

    printf("Enter start vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    int *visited = (int*)calloc(vertices, sizeof(int));
    TreeNode *dfsRoot = createTreeNode(start);

    buildDFSTree(g, start, visited, dfsRoot);

    printf("\nDFS Tree:\n\n");
    printf("%d\n", start);
    ChildNode *child = dfsRoot->childrenHead;
    while (child) {
        displayTree(child->node, "", child->next == NULL);
        child = child->next;
    }

    printf("\nDFS Traversal Order: ");
    printDFS(dfsRoot);
    printf("\n");

    /* Cleanup */
    free(visited);
    freeTree(dfsRoot);
    freeGraph(g);

    return 0;
}