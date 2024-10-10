/* FLOYD WARSHALL'S ALGORITHM
Intuition -
The Floyd-Warshall algorithm is used to find the shortest path between all pairs of vertices in a graph. The algorithm works by iteratively improving the path between two vertices by introducing an intermediate vertex. If a shorter path exists through this intermediate vertex, the current shortest path is updated. This approach allows it to handle both positive and negative edge weights (as long as there are no negative-weight cycles).

Approach -
Initialization:
Replace all occurrences of -1 in the matrix with a large value (INF) to represent that there is no direct path between the vertices.

Relaxation using an Intermediate Vertex:
For each pair of vertices (i, j), check if going through another vertex k offers a shorter path from i to j. If matrix[i][j] can be reduced by taking the path through k (matrix[i][k] + matrix[k][j]), update matrix[i][j].

Restoration:
After processing, revert any distance that remains INF back to -1, meaning no path exists between those vertices.

Time Complexity:
The algorithm runs in O(n³), where n is the number of vertices in the graph.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        const int INF = 1e8;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) matrix[i][j] = INF;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (matrix[k][j] == INF) continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INF) matrix[i][j] = -1;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    sol.shortest_distance(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
