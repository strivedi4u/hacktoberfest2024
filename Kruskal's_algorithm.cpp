#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

class DisjointSet {
public:
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

    void unionSets(int u, int v) {
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

private:
    vector<int> parent, rank;
};

class KruskalMST {
public:
    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    void findMST(int n) {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        DisjointSet ds(n);
        vector<Edge> mst;

        for (const auto &edge : edges) {
            if (ds.find(edge.u) != ds.find(edge.v)) {
                ds.unionSets(edge.u, edge.v);
                mst.push_back(edge);
            }
        }

        for (const auto &edge : mst) {
            cout << edge.u << " - " << edge.v << ": " << edge.weight << endl;
        }
    }

private:
    vector<Edge> edges;
};

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    KruskalMST mst;
    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        mst.addEdge(u, v, weight);
    }

    mst.findMST(n);
    return 0;
}
