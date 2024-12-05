#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];

void BFS(int start, int vertices) {
    int queue[MAX], front = 0, rear = -1;
    int current;

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}


void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;


    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            DFS(i, vertices);
        }
    }
}

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

int main() {
    int vertices, edges, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the start vertex for BFS and DFS: ");
    scanf("%d", &start);

    BFS(start, vertices);

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    DFS(start, vertices);
    printf("\n");

    return 0;
}
