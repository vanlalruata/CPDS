#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 999999

int costMatrix[MAX][MAX];
int dist[MAX];        /* Stores shortest cumulative cost g(n) */
int parent[MAX];      /* Tracks tree parent for each vertex */
int visited[MAX];     /* Marked 1 only when popped/expanded */
int n;

/* Explicit UCS tree representation */
int ucsChildren[MAX][MAX];
int ucsChildCount[MAX];

/* Priority Queue Element */
typedef struct {
    int vertex;
    int cost;
} PQNode;

PQNode pq[MAX * MAX];
int pqSize = 0;

void pqPush(int v, int c)
{
    pq[pqSize].vertex = v;
    pq[pqSize].cost = c;
    pqSize++;
}

PQNode pqPopMin(void)
{
    int minIndex = 0;
    int i;

    for (i = 1; i < pqSize; i++)
    {
        if (pq[i].cost < pq[minIndex].cost)
        {
            minIndex = i;
        }
    }

    PQNode best = pq[minIndex];
    pq[minIndex] = pq[pqSize - 1];
    pqSize--;

    return best;
}

int isPQEmpty(void)
{
    return pqSize == 0;
}

/*--------------------------------------------------
  Run Uniform-Cost Search and construct tree
--------------------------------------------------*/
void buildUCSTree(int start, int order[], int *orderCount)
{
    int i, v;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
        ucsChildCount[i] = 0;
    }

    dist[start] = 0;
    pqPush(start, 0);

    while (!isPQEmpty())
    {
        PQNode current = pqPopMin();
        int u = current.vertex;

        /* Skip if already finalized via a shorter path */
        if (visited[u])
            continue;

        visited[u] = 1;
        order[(*orderCount)++] = u;

        /* If this node has a parent, record the tree edge */
        if (parent[u] != -1)
        {
            int p = parent[u];
            ucsChildren[p][ucsChildCount[p]++] = u;
        }

        /* Relax outgoing edges */
        for (v = 0; v < n; v++)
        {
            if (costMatrix[u][v] > 0 && !visited[v])
            {
                int newCost = dist[u] + costMatrix[u][v];
                if (newCost < dist[v])
                {
                    dist[v] = newCost;
                    parent[v] = u;
                    pqPush(v, newCost);
                }
            }
        }
    }
}

/*--------------------------------------------------
  Display Tree Hierarchy with Cumulative Path Cost g(n)
--------------------------------------------------*/
void displayTree(int u, const char *prefix, int isLast)
{
    int i;

    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    /* Print vertex, its cumulative cost g(n), and the edge weight from parent */
    if (parent[u] != -1)
        printf("%d [edge: %d, g: %d]\n", u, costMatrix[parent[u]][u], dist[u]);
    else
        printf("%d [g: %d]\n", u, dist[u]);

    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    for (i = 0; i < ucsChildCount[u]; i++)
    {
        displayTree(ucsChildren[u][i], newPrefix, i == ucsChildCount[u] - 1);
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

    printf("\nEnter the weighted adjacency matrix (%dx%d):\n", n, n);
    printf("(Use 0 for no direct edge/self-loop, positive weights for edges)\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    printf("\nEnter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    /* 1. Build UCS Tree */
    buildUCSTree(start, traversalOrder, &orderCount);

    /* 2. Print visual tree */
    printf("\nUCS Tree:\n\n");
    printf("%d [Root, g: 0]\n", start);
    for (i = 0; i < ucsChildCount[start]; i++)
    {
        displayTree(ucsChildren[start][i], "", i == ucsChildCount[start] - 1);
    }

    /* 3. Print expansion order */
    printf("\nUCS Expansion Order: ");
    for (i = 0; i < orderCount; i++)
    {
        printf("%d ", traversalOrder[i]);
    }
    printf("\n");

    return 0;
}