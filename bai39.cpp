#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MAXN = 100001;

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

vector<Edge> graph[MAXN];
vector<int> dist(MAXN, INF);

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s);

    if (dist[t] == INF)
        cout << -1 << endl;
    else
        cout << dist[t] << endl;

    return 0;
}
