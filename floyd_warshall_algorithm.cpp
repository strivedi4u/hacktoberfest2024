#include <iostream>
#include <limits.h> // For INT_MAX, to represent infinity

using namespace std;

const int V = 4; // Number of vertices (nodes) in the graph
#define INF INT_MAX // Infinity, for places where no path exists

// The heart of the Floyd-Warshall algorithm: It updates the distances between all pairs of nodes
void floydWarshall(int graph[V][V]) {
    // Step 1: Create a distance matrix to store the shortest distances between all pairs
    int dist[V][V];

    // Step 2: Initialize the distance matrix with the given graph values (initial distances)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j]; // Initially, shortest paths are the direct paths (or INF if no path)
        }
    }

    // Step 3: Start the main algorithm
    for (int k = 0; k < V; k++) { // 'k' is the intermediate node we're testing
        for (int i = 0; i < V; i++) { // For each pair of nodes (i, j)...
            for (int j = 0; j < V; j++) {
                // Only update if there's a path through 'k'
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Found a shorter path, update it!
                }
            }
        }
    }

    // Step 4: Output the results
    cout << "The shortest distances between every pair of vertices are as follows:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF "; // No path exists
            } else {
                cout << dist[i][j] << " "; // Shortest path between i and j
            }
        }
        cout << endl;
    }
}

int main() {
    // Example graph: adjacency matrix representation
    int graph[V][V] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    // Call the function to find the shortest paths
    floydWarshall(graph);

    return 0;
}