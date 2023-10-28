#include <bits/stdc++.h> 
using namespace std;

void BFS(vector<vector<int>>& graph, int startNode, vector<bool>& visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Sort the neighbors in lexicographic order
        vector<int> neighbors;
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                neighbors.push_back(neighbor);
                visited[neighbor] = true;
            }
        }
        sort(neighbors.begin(), neighbors.end());

        for (int neighbor : neighbors) {
            q.push(neighbor);
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
            BFS(graph, i, visited);
        }
    }

    return 0;
}
