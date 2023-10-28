#include <bits/stdc++.h> 
using namespace std;

void DFS(vector<vector<int>>& graph, int currentNode, vector<bool>& visited) {
    visited[currentNode] = true;
    cout << currentNode << " ";

    // Sort the neighbors in lexicographic order
    vector<int> neighbors;
    for (int neighbor : graph[currentNode]) {
        if (!visited[neighbor]) {
            neighbors.push_back(neighbor);
        }
    }
    sort(neighbors.begin(), neighbors.end());

    for (int neighbor : neighbors) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1); // 1-based index
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }

    return 0;
}
