#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 1000
#define MAX_INPUT 100

typedef struct No {
    int vertice;
    struct No* proximo;
} No;

typedef struct Grafo {
    int numVertices;
    No** listasAdj;
    bool* visitado;
} Grafo;

No* criaNo(int v) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = v;
    novoNo->proximo = NULL;
    return novoNo;
}

Grafo* criaGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;
    grafo->listasAdj = (No**)malloc(vertices * sizeof(No*));
    grafo->visitado = (bool*)malloc(vertices * sizeof(bool));
    
    for (int i = 0; i < vertices; i++) {
        grafo->listasAdj[i] = NULL;
        grafo->visitado[i] = false;
    }
    return grafo;
}

void adicionaAresta(Grafo* grafo, int origem, int destino) {
    No* novoNo = criaNo(destino);
    novoNo->proximo = grafo->listasAdj[origem];
    grafo->listasAdj[origem] = novoNo;

    novoNo = criaNo(origem);
    novoNo->proximo = grafo->listasAdj[destino];
    grafo->listasAdj[destino] = novoNo;
}

bool temCicloUtil(Grafo* grafo, int v, int pai) {
    grafo->visitado[v] = true;
    
    No* listaAdj = grafo->listasAdj[v];
    No* temp = listaAdj;
    
    while (temp != NULL) {
        int verticeAdj = temp->vertice;
        
        if (!grafo->visitado[verticeAdj]) {
            if (temCicloUtil(grafo, verticeAdj, v)) {
                return true;
            }
        } else if (verticeAdj != pai) {
            return true;
        }
        temp = temp->proximo;
    }
    return false;
}

bool temCiclo(Grafo* grafo) {
    for (int i = 0; i < grafo->numVertices; i++) {
        if (!grafo->visitado[i]) {
            if (temCicloUtil(grafo, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E, origem, destino;
    char input[MAX_INPUT];
    
    printf("Digite o número de vértices: ");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%d", &V);
    printf("Número de vértices lido: %d\n", V);  // Diagnóstico

    Grafo* grafo = criaGrafo(V);
    
    printf("Digite o número de arestas: ");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%d", &E);
    printf("Número de arestas lido: %d\n", E);  // Diagnóstico
    
    for (int i = 0; i < E; i++) {
        printf("Digite a aresta %d (origem destino): ", i + 1);
        fgets(input, MAX_INPUT, stdin);
        sscanf(input, "%d %d", &origem, &destino);
        printf("Aresta lida: %d -> %d\n", origem, destino);  // Diagnóstico
        adicionaAresta(grafo, origem, destino);
    }
    
    printf("Analisando o grafo...\n");
    
    if (temCiclo(grafo)) {
        printf("Saída: 1 (O grafo contém um ciclo)\n");
    } else {
        printf("Saída: 0 (O grafo não contém um ciclo)\n");
    }

    return 0;
}
