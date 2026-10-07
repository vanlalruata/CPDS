#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int heuristic[MAX];
int visited[MAX];
int n;

/* Explicit tree representation */
int bestChildren[MAX][MAX];
int bestChildCount[MAX];

/* Priority Queue Element */
typedef struct {
    int vertex;
    int hVal;
} PQNode;

PQNode pq[MAX * MAX];
int pqSize = 0;

/* Insert into Min-Priority Queue based on heuristic value */
void pqPush(int v, int h)
{
    pq[pqSize].vertex = v;
    pq[pqSize].hVal = h;
    pqSize++;
}

/* Extract node with lowest heuristic value */
int pqPopMin(void)
{
    int minIndex = 0;
    int i;

    for (i = 1; i < pqSize; i++)
    {
        if (pq[i].hVal < pq[minIndex].hVal)
        {
            minIndex = i;
        }
    }

    int bestVertex = pq[minIndex].vertex;

    /* Remove element by swapping with the last element */
    pq[minIndex] = pq[pqSize - 1];
    pqSize--;

    return bestVertex;
}

int isPQEmpty(void)
{
    return pqSize == 0;
}

/*--------------------------------------------------
  Run Greedy Best-First Search and build tree
--------------------------------------------------*/
void buildBestFirstTree(int start, int order[], int *orderCount)
{
    int u, v;

    visited[start] = 1;
    pqPush(start, heuristic[start]);

    while (!isPQEmpty())
    {
        u = pqPopMin();
        order[(*orderCount)++] = u;

        for (v = 0; v < n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                /* (u -> v) becomes a tree edge */
                bestChildren[u][bestChildCount[u]++] = v;
                pqPush(v, heuristic[v]);
            }
        }
    }
}

/*--------------------------------------------------
  Display Tree Hierarchy with Node Heuristics
--------------------------------------------------*/
void displayTree(int u, const char *prefix, int isLast)
{
    int i;

    /* Print tree branch */
    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    /* Print node ID and its heuristic cost */
    printf("%d (h=%d)\n", u, heuristic[u]);

    /* Indentation for child level */
    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    /* Recurse on children */
    for (i = 0; i < bestChildCount[u]; i++)
    {
        displayTree(bestChildren[u][i], newPrefix, i == bestChildCount[u] - 1);
    }
}

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main(void)
{
    int i, j;
    int start;
    int traversalOrder[MAX];
    int orderCount = 0;

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

    printf("\nEnter heuristic values h(n) for each vertex (0 to %d):\n", n - 1);
    for (i = 0; i < n; i++)
    {
        printf("h(%d): ", i);
        scanf("%d", &heuristic[i]);
    }

    printf("\nEnter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    /* Initialize tracking arrays */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        bestChildCount[i] = 0;
    }

    /* 1. Build Best-First Search Tree */
    buildBestFirstTree(start, traversalOrder, &orderCount);

    /* 2. Print visually */
    printf("\nBest-First Search Tree:\n\n");
    printf("%d (h=%d)\n", start, heuristic[start]);
    for (i = 0; i < bestChildCount[start]; i++)
    {
        displayTree(bestChildren[start][i], "", i == bestChildCount[start] - 1);
    }

    /* 3. Print traversal sequence */
    printf("\nBest-First Search Traversal: ");
    for (i = 0; i < orderCount; i++)
    {
        printf("%d ", traversalOrder[i]);
    }
    printf("\n");

    return 0;
}