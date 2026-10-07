#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int nodeDepth[MAX];
int n;

/* Explicit tree representation per iteration */
int iddfsChildren[MAX][MAX];
int iddfsChildCount[MAX];

int traversalOrder[MAX];
int orderCount = 0;

/* Flag to detect if any child was pruned due to depth limit */
int anyCutoffOccurred = 0;

/*--------------------------------------------------
  Depth-Limited Search Subroutine for a Given Limit
--------------------------------------------------*/
void dlsTreeBuilder(int u, int currentDepth, int limit)
{
    int v;

    visited[u] = 1;
    nodeDepth[u] = currentDepth;
    traversalOrder[orderCount++] = u;

    /* Base case: reached iteration limit */
    if (currentDepth >= limit)
    {
        /* Check if node had outgoing unvisited neighbors cut off */
        for (v = 0; v < n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                anyCutoffOccurred = 1;
                break;
            }
        }
        return;
    }

    /* Expand neighbors */
    for (v = 0; v < n; v++)
    {
        if (graph[u][v] == 1 && visited[v] == 0)
        {
            iddfsChildren[u][iddfsChildCount[u]++] = v;
            dlsTreeBuilder(v, currentDepth + 1, limit);
        }
    }
}

/*--------------------------------------------------
  Display Tree Hierarchy with Depths and Cutoff Notes
--------------------------------------------------*/
void displayTree(int u, int limit, const char *prefix, int isLast)
{
    int i;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (nodeDepth[u] == limit && iddfsChildCount[u] == 0)
        printf("%d (depth: %d) [Cutoff/Leaf]\n", u, nodeDepth[u]);
    else
        printf("%d (depth: %d)\n", u, nodeDepth[u]);

    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    for (i = 0; i < iddfsChildCount[u]; i++)
    {
        displayTree(iddfsChildren[u][i], limit, newPrefix, i == iddfsChildCount[u] - 1);
    }
}

/*--------------------------------------------------
  Main IDDFS Driver
--------------------------------------------------*/
int main(void)
{
    int i, j;
    int start;
    int limit;

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

    printf("\n=========================================\n");
    printf("  ITERATIVE DEEPENING DFS (IDDFS) TRACE  \n");
    printf("=========================================\n");

    /* Increment limit from 0 up to n - 1 */
    for (limit = 0; limit < n; limit++)
    {
        /* Reset tracking for new iteration */
        for (i = 0; i < n; i++)
        {
            visited[i] = 0;
            iddfsChildCount[i] = 0;
            nodeDepth[i] = 0;
        }
        orderCount = 0;
        anyCutoffOccurred = 0;

        /* Execute DLS for current depth limit */
        dlsTreeBuilder(start, 0, limit);

        /* Print Tree for this iteration */
        printf("\n-----------------------------------------\n");
        printf(">>> ITERATION: Depth Limit = %d\n", limit);
        printf("-----------------------------------------\n\n");

        printf("%d (depth: 0)\n", start);
        for (i = 0; i < iddfsChildCount[start]; i++)
        {
            displayTree(iddfsChildren[start][i], limit, "", i == iddfsChildCount[start] - 1);
        }

        /* Print traversal order */
        printf("\nTraversal Order (Limit %d): ", limit);
        for (i = 0; i < orderCount; i++)
        {
            printf("%d ", traversalOrder[i]);
        }
        printf("\n");

        /* If no nodes were cut off, the entire reachable component is explored */
        if (!anyCutoffOccurred)
        {
            printf("\n[Notice] No nodes pruned at depth %d. Entire component explored; terminating early.\n", limit);
            break;
        }
    }

    return 0;
}