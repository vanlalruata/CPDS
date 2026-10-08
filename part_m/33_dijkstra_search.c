#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 1000000000

int costMatrix[MAX][MAX];
int dist[MAX];
int parent[MAX];
int settled[MAX];
int n;

/* Explicit Search Tree built from parent pointers */
int treeChildren[MAX][MAX];
int treeChildCount[MAX];

/* Array-based Min-Priority Queue */
typedef struct {
    int vertex;
    int cost;
    int parentNode;
} PQNode;

PQNode pq[MAX * MAX];
int pqSize = 0;

void pqPush(int v, int c, int p) {
    pq[pqSize].vertex = v;
    pq[pqSize].cost = c;
    pq[pqSize].parentNode = p;
    pqSize++;
}

PQNode pqPopMin(void) {
    int minIdx = 0;
    for (int i = 1; i < pqSize; i++) {
        if (pq[i].cost < pq[minIdx].cost) {
            minIdx = i;
        }
    }
    PQNode best = pq[minIdx];
    pq[minIdx] = pq[pqSize - 1];
    pqSize--;
    return best;
}

int isPQEmpty(void) {
    return pqSize == 0;
}

/*--------------------------------------------------
  Display Tree Hierarchy with Indentation
--------------------------------------------------*/
void displayTree(int u, const char *prefix, int isLast) {
    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (parent[u] != -1)
        printf("%d [edge: %d, g: %d]\n", u, costMatrix[parent[u]][u], dist[u]);
    else
        printf("%d [Root, g: 0]\n", u);

    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    for (int i = 0; i < treeChildCount[u]; i++) {
        displayTree(treeChildren[u][i], newPrefix, i == treeChildCount[u] - 1);
    }
}

/*--------------------------------------------------
  Dijkstra Algorithm
--------------------------------------------------*/
void dijkstra(int start, int order[], int *orderCount) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
        settled[i] = 0;
        treeChildCount[i] = 0;
    }

    dist[start] = 0;
    pqPush(start, 0, -1);

    while (!isPQEmpty()) {
        PQNode cur = pqPopMin();
        int u = cur.vertex;

        if (settled[u]) continue;

        settled[u] = 1;
        order[(*orderCount)++] = u;

        /* Connect to tree parent once settled */
        if (cur.parentNode != -1) {
            int p = cur.parentNode;
            treeChildren[p][treeChildCount[p]++] = u;
        }

        /* Relax outgoing edges */
        for (int v = 0; v < n; v++) {
            if (costMatrix[u][v] > 0 && !settled[v]) {
                int newCost = dist[u] + costMatrix[u][v];
                if (newCost < dist[v]) {
                    dist[v] = newCost;
                    parent[v] = u;
                    pqPush(v, newCost, u);
                }
            }
        }
    }
}

/*--------------------------------------------------
  Main Driver
--------------------------------------------------*/
int main(void) {
    int start;
    int order[MAX];
    int orderCount = 0;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("\nEnter weighted adjacency matrix (%dx%d):\n", n, n);
    printf("(0 for no edge, positive integer for edge weight)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    printf("\nEnter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(start, order, &orderCount);

    printf("\n=========================================\n");
    printf("         DIJKSTRA SHORTEST PATH TREE     \n");
    printf("=========================================\n\n");
    printf("%d [Root, g: 0]\n", start);
    for (int i = 0; i < treeChildCount[start]; i++) {
        displayTree(treeChildren[start][i], "", i == treeChildCount[start] - 1);
    }

    printf("\nExpansion Order: ");
    for (int i = 0; i < orderCount; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");

    return 0;
}