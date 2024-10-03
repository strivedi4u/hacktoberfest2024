#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100 // Maximum number of vertices in the graph

// Node structure to represent an edge with a weight
typedef struct Node {
    int vertex; // The vertex number
    int weight; // The weight of the edge
} Node;

// Graph structure to hold the number of vertices and adjacency matrix
typedef struct Graph {
    int numVertices; // Total number of vertices in the graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to represent weights of edges
} Graph;

// Function to create a graph with a specified number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph)); // Allocate memory for the graph
    graph->numVertices = vertices; // Set the number of vertices in the graph

    // Initialize the adjacency matrix with infinite weights
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph->adjMatrix[i][j] = 0; // No self-loops, so distance is 0
            } else {
                graph->adjMatrix[i][j] = INT_MAX; // Initialize to "infinity" for non-adjacent vertices
            }
        }
    }
    return graph; // Return the created graph
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight; // Set weight for edge from src to dest
    graph->adjMatrix[dest][src] = weight; // Set weight for edge from dest to src (undirected graph)
}

// Function to perform Prim's algorithm to find the Minimum Spanning Tree (MST)
void primMST(Graph* graph) {
    int parent[MAX_VERTICES]; // Array to store the MST
    int key[MAX_VERTICES]; // Minimum weight edge to add to the MST
    int visited[MAX_VERTICES]; // Track visited vertices

    // Initialize all keys to infinite, parent to -1, and visited to false
    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INT_MAX; // Set key to "infinity" initially
        visited[i] = 0; // Mark all vertices as not visited
        parent[i] = -1; // Initialize parent to -1 (no parent)
    }
    
    key[0] = 0; // Starting from the first vertex, set its key to 0

    // Process all vertices in the graph
    for (int count = 0; count < graph->numVertices - 1; count++) {
        // Find the vertex with the minimum key value that has not been visited
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v]; // Update minimum key value
                minIndex = v; // Set the vertex index for the minimum key
            }
        }
        visited[minIndex] = 1; // Mark the chosen vertex as visited

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < graph->numVertices; v++) {
            // Check if there is an edge between minIndex and v, and if v is not visited
            if (graph->adjMatrix[minIndex][v] && !visited[v] && graph->adjMatrix[minIndex][v] < key[v]) {
                parent[v] = minIndex; // Update parent of v
                key[v] = graph->adjMatrix[minIndex][v]; // Update key value
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < graph->numVertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph->adjMatrix[i][parent[i]]);
    }
}

// Main function to demonstrate the graph and Prim's algorithm
int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    // Perform Prim's algorithm to find the MST
    primMST(graph);

    // Free the allocated memory for the graph
    free(graph);
    return 0;
}