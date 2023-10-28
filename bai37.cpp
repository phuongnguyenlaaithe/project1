#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

vector<Edge> edges;
vector<int> parent;

int find(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int minSpanningTreeWeight = 0;
    int edgesAdded = 0;

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        int parentU = find(u);
        int parentV = find(v);

        if (parentU != parentV) {
            parent[parentU] = parentV;
            minSpanningTreeWeight += w;
            edgesAdded++;
            if (edgesAdded == N - 1) {
                break;
            }
        }
    }

    cout << minSpanningTreeWeight << endl;

    return 0;
}
