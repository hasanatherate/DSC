#include <stdio.h>
#include <stdlib.h>

int a[10][10], visited[10], n;

// Breadth-First Search function, explores level by level
void BFS(int u) {
    int f, r, q[10], v;
    printf("The nodes visited from %d: ", u);
    f = 0;
    r = -1;
    q[++r] = u;
    visited[u] = 1;

    while (f <= r) {
        u = q[f++];
        for (v = 0; v < n; v++) {
            if (a[u][v] == 1 && visited[v] == 0) {
                printf("%d ", v);
                visited[v] = 1;
                q[++r] = v;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int i, j, s1;

    printf("\nGRAPH TRAVERSALS USING ADJACENCY MATRIX\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize visited array to 0
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Adjacency matrix is used to represent the graph
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nGRAPH TRAVERSALS USING ADJACENCY MATRIX\n");
    printf("\nReachable nodes using BFS\n");
    printf("Enter the Source Node: ");
    scanf("%d", &s1);

    BFS(s1);

    return 0;
}
