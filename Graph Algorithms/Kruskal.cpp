/* KRUSKAL ALGORITHM
Intuition -
Kruskal's algorithm is used to find the Minimum Spanning Tree (MST) of a weighted, connected, and undirected graph. The main idea is to sort all the edges in non-decreasing order of their weights and add them one by one to the MST, ensuring that no cycles are formed. The process continues until we have included V−1 edges in the MST, where V is the number of vertices.

Approach -
i)Edge Sorting:
Start by sorting all the edges in ascending order based on their weights.

ii)Union-Find Data Structure:
Use a union-find (disjoint-set) data structure to efficiently manage and check for cycles while adding edges to the MST.

iii)Building the MST:
Iterate through the sorted edges:
->For each edge, check if the vertices it connects are in the same component using the union-find structure.
->If they are not in the same component, add the edge to the MST and union the components.
iv)Completion:
Stop when V−1 edges are included in the MST, at which point the sum of the weights of the edges in the MST is returned.

Time Complexity:
The time complexity of Kruskal's algorithm is O(ElogE+ElogV), where E is the number of edges and V is the number of vertices.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        DisjointSet ds(V);
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        int sum = 0;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (ds.find(u) != ds.find(v)) {
                ds.unionSet(u, v);
                sum += weight;
            }
        }
        return sum;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    Solution sol;
    cout << sol.spanningTree(V, edges) << endl;
    return 0;
}
