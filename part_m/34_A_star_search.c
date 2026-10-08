#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 1000000000

int costMatrix[MAX][MAX];
int heuristic[MAX];
int gCost[MAX];
int parent[MAX];
int settled[MAX];
int n;

/* Explicit Search Tree */
int treeChildren[MAX][MAX];
int treeChildCount[MAX];

/* Priority Queue Element */
typedef struct {
    int vertex;
    int g;
    int f;
    int parentNode;
} PQNode;

PQNode pq[MAX * MAX];
int pqSize = 0;

void pqPush(int v, int g, int f, int p) {
    pq[pqSize].vertex = v;
    pq[pqSize].g = g;
    pq[pqSize].f = f;
    pq[pqSize].parentNode = p;
    pqSize++;
}

PQNode pqPopMin(void) {
    int minIdx = 0;
    for (int i = 1; i < pqSize; i++) {
        if (pq[i].f < pq[minIdx].f || (pq[i].f == pq[minIdx].f && pq[i].g > pq[minIdx].g)) {
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
  Display Tree Hierarchy with f = g + h Annotations
--------------------------------------------------*/
void displayTree(int u, const char *prefix, int isLast, int goal) {
    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    if (u == goal)
        printf("%d [f: %d, g: %d, h: %d] <-- [GOAL REACHED]\n", u, gCost[u] + heuristic[u], gCost[u], heuristic[u]);
    else if (parent[u] != -1)
        printf("%d [f: %d, g: %d, h: %d, edge: %d]\n", u, gCost[u] + heuristic[u], gCost[u], heuristic[u], costMatrix[parent[u]][u]);
    else
        printf("%d [Root, f: %d, g: 0, h: %d]\n", u, heuristic[u], heuristic[u]);

    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    for (int i = 0; i < treeChildCount[u]; i++) {
        displayTree(treeChildren[u][i], newPrefix, i == treeChildCount[u] - 1, goal);
    }
}

/*--------------------------------------------------
  Reconstruct and Print Shortest Path
--------------------------------------------------*/
void printPath(int start, int goal) {
    int path[MAX];
    int len = 0;
    int curr = goal;

    while (curr != -1) {
        path[len++] = curr;
        if (curr == start) break;
        curr = parent[curr];
    }

    printf("\nOptimal Path: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\nTotal Path Cost: %d\n", gCost[goal]);
}

/*--------------------------------------------------
  A* Search Algorithm
--------------------------------------------------*/
int aStar(int start, int goal, int order[], int *orderCount) {
    for (int i = 0; i < n; i++) {
        gCost[i] = INF;
        parent[i] = -1;
        settled[i] = 0;
        treeChildCount[i] = 0;
    }

    gCost[start] = 0;
    pqPush(start, 0, heuristic[start], -1);

    while (!isPQEmpty()) {
        PQNode cur = pqPopMin();
        int u = cur.vertex;

        if (settled[u]) continue;

        settled[u] = 1;
        order[(*orderCount)++] = u;

        if (cur.parentNode != -1) {
            int p = cur.parentNode;
            treeChildren[p][treeChildCount[p]++] = u;
        }

        /* Goal reached */
        if (u == goal) {
            return 1;
        }

        /* Relax outgoing edges */
        for (int v = 0; v < n; v++) {
            if (costMatrix[u][v] > 0 && !settled[v]) {
                int tentativeG = gCost[u] + costMatrix[u][v];
                if (tentativeG < gCost[v]) {
                    gCost[v] = tentativeG;
                    parent[v] = u;
                    int fVal = tentativeG + heuristic[v];
                    pqPush(v, tentativeG, fVal, u);
                }
            }
        }
    }

    return 0;
}

/*--------------------------------------------------
  Main Driver
--------------------------------------------------*/
int main(void) {
    int start, goal;
    int order[MAX];
    int orderCount = 0;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("\nEnter weighted adjacency matrix (%dx%d):\n", n, n);
    printf("(0 for no edge, positive integer for weight)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    printf("\nEnter heuristic h(n) towards goal for each vertex (0 to %d):\n", n - 1);
    for (int i = 0; i < n; i++) {
        printf("h(%d): ", i);
        scanf("%d", &heuristic[i]);
    }

    printf("\nEnter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("Enter goal vertex (0 to %d): ", n - 1);
    scanf("%d", &goal);

    int found = aStar(start, goal, order, &orderCount);

    if (!found && start != goal) {
        printf("\nNo path found from %d to %d.\n", start, goal);
    } else {
        printf("\n=========================================\n");
        printf("               A* SEARCH TREE            \n");
        printf("=========================================\n\n");
        displayTree(start, "", 1, goal);

        printf("\nA* Expansion Order: ");
        for (int i = 0; i < orderCount; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");

        printPath(start, goal);
    }

    return 0;
}