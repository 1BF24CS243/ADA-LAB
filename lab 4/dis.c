#include <stdio.h>
#define MAX 10
#define INF 999

int main() {
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    int n, i, j, u, v, min, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (enter 999 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize
    for(i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    // Dijkstra algorithm
    for(i = 0; i < n - 1; i++) {
        min = INF;

        // Find nearest unvisited vertex
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for(v = 0; v < n; v++) {
            if(!visited[v] && (dist[u] + cost[u][v] < dist[v])) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Output
    printf("\nShortest distances from vertex %d:\n", source);
    for(i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}

