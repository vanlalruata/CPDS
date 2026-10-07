#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int nodeDepth[MAX];
int n;
int depthLimit;

/* Explicit tree representation */
int dlsChildren[MAX][MAX];
int dlsChildCount[MAX];

int dlsOrder[MAX];
int orderCount = 0;

/*--------------------------------------------------
  Recursive Depth-Limited Search and Tree Builder
--------------------------------------------------*/
void buildDLSTree(int u, int currentDepth)
{
    int v;

    visited[u] = 1;
    nodeDepth[u] = currentDepth;
    dlsOrder[orderCount++] = u;

    /* Base case: Do not expand if depth limit is reached */
    if (currentDepth >= depthLimit)
    {
        return;
    }

    /* Expand neighbors */
    for (v = 0; v < n; v++)
    {
        if (graph[u][v] == 1 && visited[v] == 0)
        {
            /* Edge (u -> v) becomes a tree edge */
            dlsChildren[u][dlsChildCount[u]++] = v;
            buildDLSTree(v, currentDepth + 1);
        }
    }
}

/*--------------------------------------------------
  Display Tree Hierarchy with Node Depths
--------------------------------------------------*/
void displayTree(int u, const char *prefix, int isLast)
{
    int i;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    /* Show node ID and current depth */
    if (nodeDepth[u] == depthLimit && dlsChildCount[u] == 0)
        printf("%d (depth: %d) [Cutoff]\n", u, nodeDepth[u]);
    else
        printf("%d (depth: %d)\n", u, nodeDepth[u]);

    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    for (i = 0; i < dlsChildCount[u]; i++)
    {
        displayTree(dlsChildren[u][i], newPrefix, i == dlsChildCount[u] - 1);
    }
}

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main(void)
{
    int i, j;
    int start;

    printf("Enter the number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("\nEnter the adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Enter the depth limit (L >= 0): ");
    scanf("%d", &depthLimit);

    /* Initialize tracking structures */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        dlsChildCount[i] = 0;
        nodeDepth[i] = 0;
    }

    /* 1. Build DLS Tree */
    buildDLSTree(start, 0);

    /* 2. Display the Tree */
    printf("\nDepth-Limited Search Tree (Limit = %d):\n\n", depthLimit);
    printf("%d (depth: 0)\n", start);
    for (i = 0; i < dlsChildCount[start]; i++)
    {
        displayTree(dlsChildren[start][i], "", i == dlsChildCount[start] - 1);
    }

    /* 3. Traversal Order */
    printf("\nDLS Traversal: ");
    for (i = 0; i < orderCount; i++)
    {
        printf("%d ", dlsOrder[i]);
    }
    printf("\n");

    return 0;
}