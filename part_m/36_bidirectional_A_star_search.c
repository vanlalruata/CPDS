#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 1000000000

int costMatrix[MAX][MAX];
int hFwd[MAX];
int hBwd[MAX];
int n;

/* Forward search state */
int distFwd[MAX];
int parentFwd[MAX];
int settledFwd[MAX];
int fwdChildren[MAX][MAX];
int fwdChildCount[MAX];

/* Backward search state */
int distBwd[MAX];
int parentBwd[MAX];
int settledBwd[MAX];
int bwdChildren[MAX][MAX];
int bwdChildCount[MAX];

/* Priority Queue Element */
typedef struct {
    int vertex;
    int g;
    int f;
    int parentNode;
} PQNode;

/* Priority Queues */
PQNode pqFwd[MAX * MAX];
int pqFwdSize = 0;

PQNode pqBwd[MAX * MAX];
int pqBwdSize = 0;

/* Priority Queue Operations */
void pushPQ(PQNode pq[], int *size, int v, int g, int f, int p) {
    pq[*size].vertex = v;
    pq[*size].g = g;
    pq[*size].f = f;
    pq[*size].parentNode = p;
    (*size)++;
}

PQNode popMinPQ(PQNode pq[], int *size) {
    int minIdx = 0;
    for (int i = 1; i < *size; i++) {
        if (pq[i].f < pq[minIdx].f || (pq[i].f == pq[minIdx].f && pq[i].g > pq[minIdx].g)) {
            minIdx = i;
        }
    }
    PQNode best = pq[minIdx];
    pq[minIdx] = pq[*size - 1];
    (*size)--;
    return best;
}

int getMinKey(PQNode pq[], int size) {
    if (size == 0) return INF;
    int minVal = pq[0].f;
    for (int i = 1; i < size; i++) {
        if (pq[i].f < minVal) {
            minVal = pq[i].f;
        }
    }
    return minVal;
}

/*--------------------------------------------------
  Display Tree Hierarchy with Metrics & Bridge Flag
--------------------------------------------------*/
void displayTree(int u, int children[MAX][MAX], int childCount[MAX],
                 int dist[], int h[], int parent[], const char *prefix,
                 int isLast, int bridgeU, int bridgeV) {
    printf("%s", prefix);
    if (isLast)
        printf("└── ");
    else
        printf("├── ");

    int fVal = dist[u] + h[u];

    if (u == bridgeU || u == bridgeV)
        printf("%d [f: %d, g: %d, h: %d] <-- [BRIDGE NODE]\n", u, fVal, dist[u], h[u]);
    else if (parent[u] != -1)
        printf("%d [f: %d, g: %d, h: %d]\n", u, fVal, dist[u], h[u]);
    else
        printf("%d [Root, f: %d, g: 0, h: %d]\n", u, fVal, h[u]);

    char newPrefix[300];
    if (isLast)
        snprintf(newPrefix, sizeof(newPrefix), "%s    ", prefix);
    else
        snprintf(newPrefix, sizeof(newPrefix), "%s│   ", prefix);

    for (int i = 0; i < childCount[u]; i++) {
        displayTree(children[u][i], children, childCount, dist, h, parent,
                    newPrefix, i == childCount[u] - 1, bridgeU, bridgeV);
    }
}

/*--------------------------------------------------
  Reconstruct and Print Complete Shortest Path
--------------------------------------------------*/
void printShortestPath(int src, int goal, int uStar, int vStar, int totalCost) {
    int path[MAX * 2];
    int pathLen = 0;

    /* Trace forward chain: src -> uStar */
    int fwdPath[MAX], fwdLen = 0;
    int curr = uStar;
    while (curr != -1) {
        fwdPath[fwdLen++] = curr;
        if (curr == src) break;
        curr = parentFwd[curr];
    }
    for (int i = fwdLen - 1; i >= 0; i--) {
        path[pathLen++] = fwdPath[i];
    }

    /* Trace backward chain: vStar -> goal */
    curr = (uStar == vStar) ? parentBwd[vStar] : vStar;
    while (curr != -1) {
        path[pathLen++] = curr;
        if (curr == goal) break;
        curr = parentBwd[curr];
    }

    printf("\nUnified Shortest Path: ");
    for (int i = 0; i < pathLen; i++) {
        printf("%d", path[i]);
        if (i < pathLen - 1) printf(" -> ");
    }
    printf("\nOptimal Total Cost: %d\n", totalCost);
}

/*--------------------------------------------------
  Bidirectional A* Algorithm
--------------------------------------------------*/
void bidirectionalAStar(int src, int goal) {
    for (int i = 0; i < n; i++) {
        distFwd[i] = INF;
        distBwd[i] = INF;
        parentFwd[i] = -1;
        parentBwd[i] = -1;
        settledFwd[i] = 0;
        settledBwd[i] = 0;
        fwdChildCount[i] = 0;
        bwdChildCount[i] = 0;
    }

    distFwd[src] = 0;
    pushPQ(pqFwd, &pqFwdSize, src, 0, hFwd[src], -1);

    distBwd[goal] = 0;
    pushPQ(pqBwd, &pqBwdSize, goal, 0, hBwd[goal], -1);

    int mu = INF;
    int bestU = -1, bestV = -1;

    if (src == goal) {
        mu = 0;
        bestU = src;
        bestV = goal;
    }

    while (pqFwdSize > 0 && pqBwdSize > 0) {
        int minF_Fwd = getMinKey(pqFwd, pqFwdSize);
        int minF_Bwd = getMinKey(pqBwd, pqBwdSize);

        /* Stopping condition: lower bound of unexplored paths meets or exceeds mu */
        if (minF_Fwd >= mu || minF_Bwd >= mu || (minF_Fwd + minF_Bwd >= mu)) {
            break;
        }

        /* 1. Step Forward */
        PQNode curFwd = popMinPQ(pqFwd, &pqFwdSize);
        int uFwd = curFwd.vertex;

        if (!settledFwd[uFwd]) {
            settledFwd[uFwd] = 1;

            if (curFwd.parentNode != -1) {
                int p = curFwd.parentNode;
                fwdChildren[p][fwdChildCount[p]++] = uFwd;
            }

            /* Relax outgoing forward edges: uFwd -> v */
            for (int v = 0; v < n; v++) {
                if (costMatrix[uFwd][v] > 0) {
                    int w = costMatrix[uFwd][v];
                    if (!settledFwd[v] && distFwd[uFwd] + w < distFwd[v]) {
                        distFwd[v] = distFwd[uFwd] + w;
                        parentFwd[v] = uFwd;
                        int fVal = distFwd[v] + hFwd[v];
                        pushPQ(pqFwd, &pqFwdSize, v, distFwd[v], fVal, uFwd);
                    }

                    if (settledBwd[v] && distFwd[uFwd] + w + distBwd[v] < mu) {
                        mu = distFwd[uFwd] + w + distBwd[v];
                        bestU = uFwd;
                        bestV = v;
                    }
                }
            }

            if (settledBwd[uFwd] && distFwd[uFwd] + distBwd[uFwd] < mu) {
                mu = distFwd[uFwd] + distBwd[uFwd];
                bestU = uFwd;
                bestV = uFwd;
            }
        }

        /* 2. Step Backward */
        PQNode curBwd = popMinPQ(pqBwd, &pqBwdSize);
        int uBwd = curBwd.vertex;

        if (!settledBwd[uBwd]) {
            settledBwd[uBwd] = 1;

            if (curBwd.parentNode != -1) {
                int p = curBwd.parentNode;
                bwdChildren[p][bwdChildCount[p]++] = uBwd;
            }

            /* Relax backward edges: incoming edges v -> uBwd */
            for (int v = 0; v < n; v++) {
                if (costMatrix[v][uBwd] > 0) {
                    int w = costMatrix[v][uBwd];
                    if (!settledBwd[v] && distBwd[uBwd] + w < distBwd[v]) {
                        distBwd[v] = distBwd[uBwd] + w;
                        parentBwd[v] = uBwd;
                        int fVal = distBwd[v] + hBwd[v];
                        pushPQ(pqBwd, &pqBwdSize, v, distBwd[v], fVal, uBwd);
                    }

                    if (settledFwd[v] && distFwd[v] + w + distBwd[uBwd] < mu) {
                        mu = distFwd[v] + w + distBwd[uBwd];
                        bestU = v;
                        bestV = uBwd;
                    }
                }
            }

            if (settledFwd[uBwd] && distFwd[uBwd] + distBwd[uBwd] < mu) {
                mu = distFwd[uBwd] + distBwd[uBwd];
                bestU = uBwd;
                bestV = uBwd;
            }
        }
    }

    if (mu >= INF) {
        printf("\nNo connecting path exists between %d and %d.\n", src, goal);
    } else {
        printf("\n=========================================\n");
        printf("       BIDIRECTIONAL A* RESULTS          \n");
        printf("=========================================\n");
        if (bestU == bestV)
            printf("Optimal meeting point: Node %d (Cost: %d)\n", bestU, mu);
        else
            printf("Optimal bridging edge: (%d -> %d) (Cost: %d)\n", bestU, bestV, mu);

        printf("\n1. Forward A* Tree (Source %d):\n\n", src);
        displayTree(src, fwdChildren, fwdChildCount, distFwd, hFwd, parentFwd, "", 1, bestU, bestV);

        printf("\n2. Backward A* Tree (Goal %d):\n\n", goal);
        displayTree(goal, bwdChildren, bwdChildCount, distBwd, hBwd, parentBwd, "", 1, bestU, bestV);

        printShortestPath(src, goal, bestU, bestV, mu);
    }
}

/*--------------------------------------------------
  Main Driver
--------------------------------------------------*/
int main(void) {
    int src, goal;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("\nEnter weighted adjacency matrix (%dx%d):\n", n, n);
    printf("(0 for no edge, positive integer for weight)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    printf("\nEnter forward heuristic hF(n) towards Goal (0 to %d):\n", n - 1);
    for (int i = 0; i < n; i++) {
        printf("hF(%d): ", i);
        scanf("%d", &hFwd[i]);
    }

    printf("\nEnter backward heuristic hB(n) towards Source (0 to %d):\n", n - 1);
    for (int i = 0; i < n; i++) {
        printf("hB(%d): ", i);
        scanf("%d", &hBwd[i]);
    }

    printf("\nEnter Source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    printf("Enter Goal vertex (0 to %d): ", n - 1);
    scanf("%d", &goal);

    bidirectionalAStar(src, goal);

    return 0;
}