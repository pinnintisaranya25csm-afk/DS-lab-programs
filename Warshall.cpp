#include <stdio.h>
#define MAX 50
#define INF 999999

int main() {
    int n, dist[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d for no edge):\n", INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);

            if (i == j)
                dist[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF &&
                    dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] =
                        dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("All-pairs shortest distance matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
