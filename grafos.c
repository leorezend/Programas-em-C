#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    bool* visited;
} Graph;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

bool isCyclicUtil(Graph* graph, int v, int parent) {
    graph->visited[v] = true;
    
    Node* adjList = graph->adjLists[v];
    Node* temp = adjList;
    
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        
        if (!graph->visited[adjVertex]) {
            if (isCyclicUtil(graph, adjVertex, v)) {
                return true;
            }
        } else if (adjVertex != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool isCycle(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (isCyclicUtil(graph, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5; // Número de vértices
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 1);

    if (isCycle(graph)) {
        printf("1\n"); // O grafo contém um ciclo
    } else {
        printf("0\n"); // O grafo não contém um ciclo
    }

    return 0;
}
