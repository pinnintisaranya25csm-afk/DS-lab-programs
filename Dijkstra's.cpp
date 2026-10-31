#include <stdio.h>
#define MAX 50
#define INF 999999

int main() {
    int n, graph[MAX][MAX];
    int dist[MAX], visited[MAX] = {0};
    int parent[MAX];
    int start, destination;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix (0 for no edge):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter start and destination (0 to %d): ", n - 1);
    scanf("%d%d", &start, &destination);

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INF)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 &&
                !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[destination] == INF) {
        printf("No path exists\n");
        return 0;
    }

    printf("Shortest distance: %d\n", dist[destination]);

    int path[MAX], length = 0;

    for (int v = destination; v != -1; v = parent[v])
        path[length++] = v;

    printf("Shortest path: ");

    for (int i = length - 1; i >= 0; i--) {
        printf("%d", path[i]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\n");
    return 0;
}
