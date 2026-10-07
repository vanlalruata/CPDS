#include <stdio.h>
#include <string.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

/* Explicit representation for the DFS Tree */
int dfsChildren[MAX][MAX];
int dfsChildCount[MAX];

/*--------------------------------------------------
  Run DFS and record tree edges (parent -> child)
--------------------------------------------------*/
void buildDFSTree(int u)
{
    int v;
    visited[u] = 1;

    for (v = 0; v < n; v++)
    {
        if (graph[u][v] == 1 && visited[v] == 0)
        {
            /* Edge (u -> v) is a Tree Edge */
            dfsChildren[u][dfsChildCount[u]++] = v;
            buildDFSTree(v);
        }
    }
}

/*--------------------------------------------------
  Display DFS Traversal Order
--------------------------------------------------*/
void printDFS(int u)
{
    int i;
    printf("%d ", u);
    for (i = 0; i < dfsChildCount[u]; i++)
    {
        printDFS(dfsChildren[u][i]);
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

    /* Construct indentation for child level */
    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    /* Recurse on recorded children */
    for (i = 0; i < dfsChildCount[u]; i++)
    {
        displayTree(dfsChildren[u][i], newPrefix, i == dfsChildCount[u] - 1);
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

    /* Initialize tree tracking structures */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        dfsChildCount[i] = 0;
    }

    /* 1. Build the DFS tree */
    buildDFSTree(start);

    /* 2. Print the tree visually */
    printf("\nDFS Tree:\n\n");
    printf("%d\n", start);
    for (i = 0; i < dfsChildCount[start]; i++)
    {
        displayTree(dfsChildren[start][i], "", i == dfsChildCount[start] - 1);
    }

    /* 3. Print the traversal order */
    printf("\nDFS Traversal: ");
    printDFS(start);
    printf("\n");

    return 0;
}