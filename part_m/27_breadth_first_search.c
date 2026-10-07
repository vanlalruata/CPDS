#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

/* Explicit representation for the BFS Tree */
int bfsChildren[MAX][MAX];
int bfsChildCount[MAX];

/* BFS Queue */
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int vertex)
{
    queue[rear++] = vertex;
}

int dequeue(void)
{
    return queue[front++];
}

int isQueueEmpty(void)
{
    return front == rear;
}

/*--------------------------------------------------
  Run BFS, collect traversal order, and build tree
--------------------------------------------------*/
void buildBFSTree(int start, int bfsOrder[], int *orderCount)
{
    int u, v;

    visited[start] = 1;
    enqueue(start);

    while (!isQueueEmpty())
    {
        u = dequeue();
        bfsOrder[(*orderCount)++] = u;

        for (v = 0; v < n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                /* Edge (u -> v) is a BFS Tree Edge */
                bfsChildren[u][bfsChildCount[u]++] = v;
                enqueue(v);
            }
        }
    }
}

/*--------------------------------------------------
  Display Tree Hierarchy with Box-Drawing Glyphs
--------------------------------------------------*/
void displayTree(int u, const char *prefix, int isLast)
{
    int i;

    /* Print indentation branch */
    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    printf("%d\n", u);

    /* Construct indentation for next level */
    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    /* Recurse on recorded children */
    for (i = 0; i < bfsChildCount[u]; i++)
    {
        displayTree(bfsChildren[u][i], newPrefix, i == bfsChildCount[u] - 1);
    }
}

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main(void)
{
    int i, j;
    int start;
    int bfsOrder[MAX];
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

    printf("\nEnter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    /* Initialize tracking structures */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        bfsChildCount[i] = 0;
    }

    /* 1. Build BFS Tree and record traversal */
    buildBFSTree(start, bfsOrder, &orderCount);

    /* 2. Print the tree visually */
    printf("\nBFS Tree:\n\n");
    printf("%d\n", start);
    for (i = 0; i < bfsChildCount[start]; i++)
    {
        displayTree(bfsChildren[start][i], "", i == bfsChildCount[start] - 1);
    }

    /* 3. Print the BFS traversal order */
    printf("\nBFS Traversal: ");
    for (i = 0; i < orderCount; i++)
    {
        printf("%d ", bfsOrder[i]);
    }
    printf("\n");

    return 0;
}