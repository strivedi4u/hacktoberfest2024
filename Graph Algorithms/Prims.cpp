/* MST USING PRIM'S ALGORITHM
Intuition -
Prim's algorithm is used to find the Minimum Spanning Tree (MST) of a weighted, connected, and undirected graph. The idea behind the algorithm is to grow the MST incrementally by selecting the edge with the smallest weight that connects a vertex in the MST to a vertex outside the MST. This continues until all vertices are included in the MST.

Approach - 
i)Priority Queue:
Use a min-heap (priority queue) to always select the edge with the smallest weight.

ii)Initialization:
Start with an arbitrary vertex (commonly vertex 0) and add its edges to the priority queue.

iii)Building the MST:
While there are still edges in the priority queue:
->Extract the edge with the smallest weight.
->If the vertex is not already included in the MST, add its weight to the total sum and mark it as visited.
->Push all adjacent edges of the newly added vertex that lead to unvisited vertices into the priority queue.
iv)Completion:
Continue this process until all vertices are included in the MST, at which point the sum of the weights of the edges in the MST is returned.

Time Complexity:
The time complexity of Prim's algorithm is O(ElogV), where E is the number of edges and V is the number of vertices.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        vector<int> vis(V, 0);
        int sum = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (vis[node] == 1) {
                continue;
            }
            sum += wt;
            vis[node] = 1;
            for (auto it : adj[node]) {
                if (!vis[it[0]]) {
                    pq.push({it[1], it[0]});
                }
            }
        }
        return sum;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Solution sol;
    cout << sol.spanningTree(V, adj) << endl;
    return 0;
}
