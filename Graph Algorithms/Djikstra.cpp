/* DJIKSTRA ALGORITHM
Intuition -
Dijkstra's algorithm is used to find the shortest path from a source vertex to all other vertices in a graph. The algorithm works by iteratively selecting the node with the minimum tentative distance (weight) and exploring its neighbors, updating their distances if a shorter path is found through the selected node.

In this specific implementation:

We need to maintain a visited array to track which nodes have already been processed.
The weight array stores the shortest known distance from the source to each node. Initially, all distances are set to infinity (INT_MAX) except for the source node, which is set to 0.
We need to repeatedly select the unvisited node with the minimum weight (using the getMinWeightNode function) and update the weights of its neighbors if a shorter path is found.
The process continues until all nodes have been visited and their shortest distances from the source are determined.


Approach-

Data Structures:

visited[]: An array that keeps track of whether a node has already been processed.
weight[]: An array that holds the current shortest distance from the source to each node.
mp: A map that represents the graph, where each node points to a list of pairs. Each pair contains a neighboring node and the weight of the edge connecting them.
Initialization:

Set all distances to infinity (INT_MAX) except for the source node, which is initialized to 0.
The visited array is initialized to all 0s (i.e., no node has been visited yet).
Main Loop:

In each iteration, find the unvisited node with the minimum weight using the getMinWeightNode function.
For the selected node, check each of its neighbors. If the sum of the current node's weight and the edge weight is less than the known weight of the neighbor, update the neighbor's weight.
Mark the current node as visited and repeat until all nodes are processed.
Helper Function:

The getMinWeightNode function iterates over all nodes to find the unvisited node with the smallest weight.
Final Output:
Once the algorithm finishes, the weight[] array will contain the shortest distances from the source node to all other nodes, which is returned as the result.

Detailed Steps in the Code :
getMinWeightNode: This function iterates through the weight[] array to find the unvisited node with the minimum weight and returns it.

dijkstra_helper: This is the main Dijkstra algorithm implementation:

It initializes the visited[] and weight[] arrays.
It then repeatedly selects the node with the smallest weight (using getMinWeightNode), explores its neighbors, and updates their weights if a shorter path is found.
Once all nodes have been processed, it returns the weight[] array as a vector.
dijkstra: This function converts the adjacency list representation into the map<int, vector<pair<int,int>>> format used in the dijkstra_helper function. It then calls dijkstra_helper to get the shortest path result.*/

#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <climits>
using namespace std;

class Solution {
public:
    int getMinWeightNode(int* weight, int* visited, int n) {
        int min_node = -1;
        int min_val = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && min_val > weight[i]) {
                min_node = i;
                min_val = weight[i];
            }
        }
        return min_node;
    }

    vector<int> dijkstra_helper(map<int, vector<pair<int,int>>>& mp, int n, int s) {
        int visited[n];
        int weight[n];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            weight[i] = INT_MAX;
        }

        weight[s] = 0;
        int count = n;
        while (count) {
            int node = getMinWeightNode(weight, visited, n);
            if (node == -1) break;
            for (int i = 0; i < mp[node].size(); i++) {
                int neighbor = mp[node][i].first;
                int edge_weight = mp[node][i].second;
                if (!visited[neighbor] && (edge_weight + weight[node] < weight[neighbor])) {
                    weight[neighbor] = edge_weight + weight[node];
                }
            }
            visited[node] = 1;
            count--;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(weight[i]);
        }
        return ans;
    }

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        map<int, vector<pair<int,int>>> mp;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int vertex = adj[i][j][0];
                int weight = adj[i][j][1];
                mp[i].push_back({vertex, weight});
            }
        }
        return dijkstra_helper(mp, V, S);
    }
};

int main() {
    int V, E, source;
    cin >> V >> E;
    
    vector<vector<int>> adj[V];
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> source;

    Solution sol;
    vector<int> result = sol.dijkstra(V, adj, source);

    for (int i = 0; i < result.size(); i++) {
        cout << "Shortest distance to vertex " << i << ": " << result[i] << endl;
    }

    return 0;
}
