/* BELLMAN-FORD ALGORITHM
Intuition -
The Bellman-Ford algorithm is used to find the shortest path from a single source to all other vertices in a graph, even if the graph contains negative-weight edges. The key idea is to iteratively relax all edges multiple times and update the shortest distance to each vertex. If after V-1 iterations (where V is the number of vertices) there is still an edge that can be relaxed, it indicates the presence of a negative-weight cycle.

Approach -
Initialization:
Set the distance to the source vertex S as 0 and all other vertices to a large value (representing infinity).

Relaxation:
For each vertex, repeat the process of checking every edge. If the distance to the destination vertex v through an edge (u, v) is shorter than the previously known distance, update the distance of v.

Detect Negative Cycle:
After performing V-1 iterations (where V is the number of vertices), perform one more iteration over all edges. If a distance can still be updated, it means there's a negative-weight cycle, and the algorithm returns -1 to indicate that.

Return Result:
If no negative cycle is found, return the shortest distance for all vertices.

This algorithm runs in O(V * E), where V is the number of vertices and E is the number of edges.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V, 100000000);
        distance[S] = 0;
        
        for (int i = 0; i < V - 1; i++) {
            for (auto& adj : edges) {
                int u = adj[0];
                int v = adj[1];
                int weight = adj[2];
                if (distance[u] != 100000000 && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            for (auto& adj : edges) {
                int u = adj[0];
                int v = adj[1];
                int weight = adj[2];
                if (distance[u] != 100000000 && distance[u] + weight < distance[v]) {
                    return {-1};
                }
            }
        }
        
        return distance;
    }
};

int main() {
    int V, E, S;
    cin >> V >> E >> S;
    
    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    
    Solution sol;
    vector<int> result = sol.bellman_ford(V, edges, S);
    
    if (result[0] == -1) {
        cout << "Negative weight cycle detected" << endl;
    } else {
        for (int i = 0; i < V; i++) {
            cout << "Shortest distance to vertex " << i << ": " << result[i] << endl;
        }
    }

    return 0;
}
