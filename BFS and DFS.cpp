#include <stdio.h>
#define MAX 50

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter number of roads: ");
    scanf("%d", &edges);

    printf("Enter road connections (city indices 0 to %d):\n", n - 1);

    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter starting city index: ");
    scanf("%d", &start);

    BFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS: ");
    DFS(start);
    printf("\n");

    return 0;
}
