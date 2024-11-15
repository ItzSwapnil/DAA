//
// Write a program for DFS and BFS
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Graph {
    int adj[MAX][MAX];
    int visited[MAX];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // For undirected graph
}

void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adj[vertex][i] == 1 && !graph->visited[i]) {
            DFS(graph, i);
        }
    }
}

void BFS(Graph* graph, int startVertex) {
    int queue[MAX], front = -1, rear = -1;
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adj[currentVertex][i] == 1 && !graph->visited[i]) {
                graph->visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("DFS: ");
    DFS(graph, 0);
    printf("\n");

    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }

    printf("BFS: ");
    BFS(graph, 0);
    printf("\n");

    free(graph);
    return 0;
}


/*

    Output:
DFS: 0 1 3 4 2
BFS: 0 1 2 3 4

 */