/*
Question

Description:
Implement Breadth-First Search (BFS) traversal for a graph.
Input:
A graph represented as an adjacency list.
Output:
Print the nodes in the order of BFS traversal.
Example:

Input: Graph = {0: [1, 2], 1: [2], 2: [0, 3], 3: [3]}  
Output: 0 -> 1 -> 2 -> 3

*/
/*
Brute Force Approach
The brute force approach involves using a queue to manage the BFS traversal. The basic idea is to visit nodes level by level, starting from a given source node.

Here is a step-by-step explanation and the corresponding C++ code:

Graph Representation: We use an adjacency list to represent the graph.
BFS Traversal: We use a queue to perform BFS. We also maintain a boolean array to keep track of visited nodes to avoid cycles.
Step-by-Step Explanation:
Initialize the Graph: Use an adjacency list to store the graph. This can be done using a map of lists or vectors.
Initialize BFS Structures: Create a queue to hold the nodes to visit and a boolean array to mark nodes as visited.
Start BFS: Begin BFS from the starting node (usually node 0).
Visit Nodes: Dequeue a node, print it, and enqueue all its unvisited neighbors.
Repeat: Continue until the queue is empty.
Here's the C++ implementation:

cpp
Copy code
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

void BFS(unordered_map<int, list<int>>& graph, int start) {
    // Visited array to keep track of visited nodes
    vector<bool> visited(graph.size(), false);
    
    // Queue for BFS
    queue<int> q;
    
    // Start with the initial node
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        // Get all adjacent vertices of the dequeued vertex node
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    // Adjacency list representation of the graph
    unordered_map<int, list<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {3};
    
    // Perform BFS traversal starting from node 0
    cout << "BFS Traversal starting from node 0: ";
    BFS(graph, 0);
    
    return 0;
}
*/



/*
Efficient Approach
The brute force approach provided above is already quite efficient for most use cases. However, for very large graphs, there are a few optimizations that can be made:

Using a Set for Visited Nodes: Instead of using a boolean array, a set can be used to track visited nodes, which is especially useful if node indices are not contiguous.
Optimized Graph Representation: If the graph is static, adjacency lists can be stored in vectors of vectors for faster access.

Parallel Processing: For extremely large graphs, parallel processing can be employed to explore multiple branches simultaneously, although this is an advanced 
technique and might not be necessary for standard BFS tasks.


Explanation of the Optimized Approach:

Using a Set: The visited set replaces the boolean array, allowing us to efficiently check if a node has been visited, especially if node indices are not contiguous.
Graph Representation: The graph is still represented as an adjacency list using an unordered_map of lists.

This set-based approach is more flexible and can handle graphs with non-contiguous node indices or more complex structures. For standard BFS tasks, however, the first 
implementation is usually sufficient and more straightforward.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

void BFS(unordered_map<int, list<int>>& graph, int start) {
    // Set to keep track of visited nodes
    unordered_set<int> visited;
    
    // Queue for BFS
    queue<int> q;
    
    // Start with the initial node
    visited.insert(start);
    q.push(start);
    
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        // Get all adjacent vertices of the dequeued vertex node
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (auto neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    // Adjacency list representation of the graph
    unordered_map<int, list<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {3};
    
    // Perform BFS traversal starting from node 0
    cout << "BFS Traversal starting from node 0: ";
    BFS(graph, 0);
    
    return 0;
}
