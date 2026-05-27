#include <stdio.h>

#define MAX 20

int main() {
    int adj[MAX][MAX], indegree[MAX];
    int queue[MAX], front = 0, rear = 0;
    int n, i, j, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize indegree array
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    // Calculate indegree of each vertex
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Insert vertices with indegree 0 into queue
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Order: ");

    while(front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        count++;

        // Reduce indegree of adjacent vertices
        for(i = 0; i < n; i++) {
            if(adj[vertex][i] == 1) {
                indegree[i]--;

                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check for cycle
    if(count != n) {
        printf("\nGraph contains a cycle. Topological ordering not possible.\n");
    }

    return 0;
}              