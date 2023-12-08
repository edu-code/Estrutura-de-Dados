#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define V 5 // Número de vértices no grafo

struct Edge {
    int src, dest;
    double latitude_src, longitude_src;
    double latitude_dest, longitude_dest;
    double distance;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Result {
    int src, dest;
    double distance;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest,
             double lat1, double lon1, double lat2, double lon2) {
    graph->edges[src].src = src;
    graph->edges[src].dest = dest;
    graph->edges[src].latitude_src = lat1;
    graph->edges[src].longitude_src = lon1;
    graph->edges[src].latitude_dest = lat2;
    graph->edges[src].longitude_dest = lon2;

    graph->edges[dest].src = dest;
    graph->edges[dest].dest = src;
    graph->edges[dest].latitude_src = lat2;
    graph->edges[dest].longitude_src = lon2;
    graph->edges[dest].latitude_dest = lat1;
    graph->edges[dest].longitude_dest = lon1;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    graph->edges[src].distance = sqrt(dlat * dlat + dlon * dlon);
    graph->edges[dest].distance = graph->edges[src].distance;
}

void primMST(struct Graph* graph) {
    int* inMST = (int*)malloc(V * sizeof(int));
    struct Result* result = (struct Result*)malloc((V - 1) * sizeof(struct Result));

    // Inicializa todos os vértices como não incluídos na MST
    for (int i = 0; i < V; i++) {
        inMST[i] = 0;
    }

    // O primeiro vértice é sempre incluído na MST
    inMST[0] = 1;

    // Variável para rastrear o número de arestas incluídas na MST
    int edgeCount = 0;

    while (edgeCount < V - 1) {
        double minDistance = INFINITY;
        int minIndex = -1;

        // Procura a aresta de menor peso que conecta um vértice na MST a um fora da MST
        for (int i = 0; i < graph->E; i++) {
            if (inMST[graph->edges[i].src] && !inMST[graph->edges[i].dest] && graph->edges[i].distance < minDistance) {
                minDistance = graph->edges[i].distance;
                minIndex = i;
            }
        }

        // Adiciona a aresta encontrada à MST
        inMST[graph->edges[minIndex].dest] = 1;
        result[edgeCount].src = graph->edges[minIndex].src;
        result[edgeCount].dest = graph->edges[minIndex].dest;
        result[edgeCount].distance = graph->edges[minIndex].distance;
        edgeCount++;
    }

    // Imprime a Árvore Geradora Mínima com informações de geolocalização
    printf("Aresta   Distância\n");
    for (int i = 0; i < V - 1; i++) {
        printf("%d - %d    %f\n", result[i].src, result[i].dest, result[i].distance);
    }

    free(inMST);
    free(result);
}

int main() {
    struct Graph* graph = createGraph(V, 7);

    addEdge(graph, 0, 1, 40.7128, -74.0060, 34.0522, -118.2437);
    addEdge(graph, 0, 2, 40.7128, -74.0060, 41.8781, -87.6298);
    addEdge(graph, 1, 2, 34.0522, -118.2437, 41.8781, -87.6298);
    addEdge(graph, 1, 3, 34.0522, -118.2437, 37.7749, -122.4194);
    addEdge(graph, 2, 4, 41.8781, -87.6298, 29.7604, -95.3698);
    addEdge(graph, 3, 4, 37.7749, -122.4194, 29.7604, -95.3698);
    addEdge(graph, 2, 3, 41.8781, -87.6298, 37.7749, -122.4194);

    primMST(graph);

    free(graph->edges);
    free(graph);

    return 0;
}
// Aplicações e Estrutura de Dados:
// Este algoritmo é útil em aplicações onde é necessário construir uma rede eficiente, minimizando a distância 
// total entre os pontos. Exemplos incluem redes de comunicação, sistemas de distribuição, ou qualquer situação 
// em que seja essencial conectar pontos geográficos otimizando distâncias.
// Exemplo de Aplicação:
// No exemplo fornecido, os vértices representam cidades com coordenadas de latitude e longitude. O algoritmo 
// de Prim é usado para encontrar a conexão mais eficiente entre as cidades, minimizando a distância total 
// percorrida.
// No código modificado, é implementado o algoritmo de Prim, a função de encontrar a Árvore Geradora Mínima e imprimir as arestas
// selecionadas com suas distâncias.