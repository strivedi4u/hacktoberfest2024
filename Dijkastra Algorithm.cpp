#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (int i = 0; i < V; i++) {
        for (auto &vec : adj[i]) {
            int v = vec[0];
            int w = vec[1];
            graph[i][v] = w;
        }
    }

    vector<int> vis(V, 0);
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;
    for (int count = 0; count < V; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!vis[i] && (u == -1 || dist[u] > dist[i])) {
                u = i;
            }
        }
        vis[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!vis[v] && graph[u][v] != 0) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    return dist;
}

int main() {
    int V, E, S;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> S;

    vector<int> result = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
