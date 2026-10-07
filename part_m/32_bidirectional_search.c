#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int n;

/* Visited flags: 1 if visited by that direction */
int visitedForward[MAX];
int visitedBackward[MAX];

/* Parents for path reconstruction */
int parentForward[MAX];
int parentBackward[MAX];

/* Explicit representation for both search trees */
int fwdChildren[MAX][MAX];
int fwdChildCount[MAX];

int bwdChildren[MAX][MAX];
int bwdChildCount[MAX];

/* FIFO Queues */
int qFwd[MAX], fFwd = 0, rFwd = 0;
int qBwd[MAX], fBwd = 0, rBwd = 0;

void pushFwd(int v) { qFwd[rFwd++] = v; }
int popFwd(void)    { return qFwd[fFwd++]; }
int emptyFwd(void)  { return fFwd == rFwd; }

void pushBwd(int v) { qBwd[rBwd++] = v; }
int popBwd(void)    { return qBwd[fBwd++]; }
int emptyBwd(void)  { return fBwd == rBwd; }

/*--------------------------------------------------
  Display Tree Hierarchy
--------------------------------------------------*/
void displayTree(int u, int children[MAX][MAX], int count[MAX],
                 const char *prefix, int isLast, int intersectionNode)
{
    int i;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (u == intersectionNode)
        printf("%d [INTERSECTION POINT]\n", u);
    else
        printf("%d\n", u);

    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    for (i = 0; i < count[u]; i++)
    {
        displayTree(children[u][i], children, count, newPrefix,
                    i == count[u] - 1, intersectionNode);
    }
}

/*--------------------------------------------------
  Reconstruct and print connecting path
--------------------------------------------------*/
void printPath(int source, int goal, int meetNode)
{
    int path[MAX * 2];
    int pathLen = 0;
    int curr;

    /* Trace forward path: source -> meetNode */
    int fwdPath[MAX], fwdLen = 0;
    curr = meetNode;
    while (curr != -1)
    {
        fwdPath[fwdLen++] = curr;
        curr = parentForward[curr];
    }
    /* Reverse forward trace so it goes source -> meetNode */
    for (int i = fwdLen - 1; i >= 0; i--)
    {
        path[pathLen++] = fwdPath[i];
    }

    /* Trace backward path: meetNode -> goal */
    curr = parentBackward[meetNode];
    while (curr != -1)
    {
        path[pathLen++] = curr;
        curr = parentBackward[curr];
    }

    /* Print final united path */
    printf("\nUnified Shortest Path: ");
    for (int i = 0; i < pathLen; i++)
    {
        printf("%d", path[i]);
        if (i < pathLen - 1)
            printf(" -> ");
    }
    printf(" (Length: %d edges)\n", pathLen - 1);
}

/*--------------------------------------------------
  Bidirectional BFS Core Routine
--------------------------------------------------*/
int bidirectionalSearch(int src, int goal)
{
    int i, v;

    for (i = 0; i < n; i++)
    {
        visitedForward[i] = 0;
        visitedBackward[i] = 0;
        parentForward[i] = -1;
        parentBackward[i] = -1;
        fwdChildCount[i] = 0;
        bwdChildCount[i] = 0;
    }

    if (src == goal)
    {
        visitedForward[src] = 1;
        visitedBackward[goal] = 1;
        return src;
    }

    visitedForward[src] = 1;
    pushFwd(src);

    visitedBackward[goal] = 1;
    pushBwd(goal);

    while (!emptyFwd() && !emptyBwd())
    {
        /* 1. Step Forward Search by one node */
        int uFwd = popFwd();
        for (v = 0; v < n; v++)
        {
            /* Forward edge: uFwd -> v */
            if (graph[uFwd][v] == 1 && !visitedForward[v])
            {
                visitedForward[v] = 1;
                parentForward[v] = uFwd;
                fwdChildren[uFwd][fwdChildCount[uFwd]++] = v;
                pushFwd(v);

                /* Frontier collision check */
                if (visitedBackward[v])
                    return v;
            }
        }

        /* 2. Step Backward Search by one node */
        int uBwd = popBwd();
        for (v = 0; v < n; v++)
        {
            /* Backward edge: graph[v][uBwd] for directed graphs,
               or graph[uBwd][v] for undirected graphs */
            if (graph[v][uBwd] == 1 && !visitedBackward[v])
            {
                visitedBackward[v] = 1;
                parentBackward[v] = uBwd;
                bwdChildren[uBwd][bwdChildCount[uBwd]++] = v;
                pushBwd(v);

                /* Frontier collision check */
                if (visitedForward[v])
                    return v;
            }
        }
    }

    return -1; /* No path exists */
}

/*--------------------------------------------------
  Main Driver
--------------------------------------------------*/
int main(void)
{
    int i, j;
    int src, goal;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("\nEnter the adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter Source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    printf("Enter Goal vertex (0 to %d): ", n - 1);
    scanf("%d", &goal);

    int meetNode = bidirectionalSearch(src, goal);

    if (meetNode == -1)
    {
        printf("\nNo connecting path found between %d and %d.\n", src, goal);
        return 0;
    }

    printf("\n=========================================\n");
    printf("     BIDIRECTIONAL SEARCH RESULTS        \n");
    printf("=========================================\n");
    printf("Frontiers met at vertex: %d\n", meetNode);

    /* Forward Tree Display */
    printf("\n1. Forward Tree (from Source %d):\n\n", src);
    if (src == meetNode)
        printf("%d [INTERSECTION POINT]\n", src);
    else
        printf("%d\n", src);

    for (i = 0; i < fwdChildCount[src]; i++)
    {
        displayTree(fwdChildren[src][i], fwdChildren, fwdChildCount,
                    "", i == fwdChildCount[src] - 1, meetNode);
    }

    /* Backward Tree Display */
    printf("\n2. Backward Tree (from Goal %d):\n\n", goal);
    if (goal == meetNode)
        printf("%d [INTERSECTION POINT]\n", goal);
    else
        printf("%d\n", goal);

    for (i = 0; i < bwdChildCount[goal]; i++)
    {
        displayTree(bwdChildren[goal][i], bwdChildren, bwdChildCount,
                    "", i == bwdChildCount[goal] - 1, meetNode);
    }

    /* Print combined path */
    printPath(src, goal, meetNode);

    return 0;
}