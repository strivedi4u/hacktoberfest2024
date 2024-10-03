#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <algorithm>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<int>* adj; // Adjacency list

    // Helper function for Tarjan's algorithm
    void SCCUtil(int u, int disc[], int low[], stack<int>& stk, bool stackMember[]);

public:
    // Constructor
    Graph(int V);

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // Function to find and print all SCCs
    void findSCCs();
};

// Constructor to initialize the graph
Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

// Add an edge to the directed graph
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

// A recursive function that finds and prints SCCs using DFS traversal
// u: current vertex, disc[]: discovery times of visited vertices
// low[]: earliest visited vertex reachable from subtree
// stk: To store all connected vertices, stackMember[]: is a member of the stack
void Graph::SCCUtil(int u, int disc[], int low[], stack<int>& stk, bool stackMember[]) {
    static int time = 0; // Global time for discovery times

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    stk.push(u);
    stackMember[u] = true;

    // Go through all vertices adjacent to this one
    for (int v : adj[u]) {
        if (disc[v] == -1) { // If v is not visited
            SCCUtil(v, disc, low, stk, stackMember);

            // Check if the subtree rooted at v has a connection back to one of its ancestors
            low[u] = min(low[u], low[v]);
        }
        else if (stackMember[v]) { // If v is in the stack, it's part of the current SCC
            low[u] = min(low[u], disc[v]);
        }
    }

    // If u is a root node, pop the stack and print an SCC
    if (low[u] == disc[u]) {
        cout << "SCC: ";
        while (stk.top() != u) {
            int v = stk.top();
            cout << v << " ";
            stackMember[v] = false;
            stk.pop();
        }
        cout << u << endl; // Pop the root of SCC
        stackMember[u] = false;
        stk.pop();
    }
}

// Function to find and print all SCCs
void Graph::findSCCs() {
    int* disc = new int[V];        // Discovery times of vertices
    int* low = new int[V];         // Earliest visited vertex reachable
    bool* stackMember = new bool[V]; // To check if a vertex is in the stack
    stack<int> stk;

    // Initialize discovery times and low values
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
        stackMember[i] = false;
    }

    // Call the recursive helper function for all vertices
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            SCCUtil(i, disc, low, stk, stackMember);
        }
    }

    // Clean up
    delete[] disc;
    delete[] low;
    delete[] stackMember;
}

// Main function to test the algorithm
int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Strongly Connected Components in the given graph:\n";
    g.findSCCs();

    return 0;
}