#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a connected, undirected, and weighted graph
class Graph {
public:
    int V, E; // V is the number of vertices, E is the number of edges
    vector<Edge> edges; // All edges

    // Constructor
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    // Kruskal's algorithm to find MST
    void kruskalMST();
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a node (with path compression optimization)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to unite two subsets by rank
void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare function for sorting edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find MST
void Graph::kruskalMST() {
    vector<Edge> result; // Store the result MST
    int e = 0; // Number of edges in MST
    int i = 0; // Initial index for sorted edges

    // Step 1: Sort all edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    // Allocate memory for subsets for union-find
    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 2: Pick the smallest edge and check if it forms a cycle
    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't form a cycle, include it in the result
        if (x != y) {
            result.push_back(nextEdge);
            Union(subsets, x, y);
            e++;
        }
    }

    // Step 3: Print the result
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }

    delete[] subsets; // Free memory
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph g(V, E);

    // Adding edges to the graph (src, dest, weight)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    // Perform Kruskal's algorithm to find the MST
    g.kruskalMST();

    return 0;
}