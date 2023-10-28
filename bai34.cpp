#include <bits/stdc++.h> 
using namespace std;

bool isHamiltonian(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int pos, int n) {
    if (pos == n) {
        // All vertices are visited once. Check if the last vertex is connected to the starting vertex.
        if (graph[path[n - 1]][path[0]] == 1) {
            return true;
        }
        return false;
    }

    for (int v = 1; v < n; v++) {
        if (!visited[v] && graph[path[pos - 1]][v] == 1) {
            path[pos] = v;
            visited[v] = true;

            if (isHamiltonian(graph, path, visited, pos + 1, n)) {
                return true;
            }

            path[pos] = -1; // Backtrack
            visited[v] = false;
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<int> path(n, -1);
        vector<bool> visited(n, false);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }

        path[0] = 0;
        visited[0] = true;

        if (isHamiltonian(graph, path, visited, 1, n)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}
