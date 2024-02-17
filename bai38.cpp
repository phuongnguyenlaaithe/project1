#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXM = 1000005;

struct Edge {
    int to, cap, rev;

    Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};

vector<Edge> graph[MAXN];
bool visited[MAXN];

void addEdge(int from, int to, int cap) {
    graph[from].push_back(Edge(to, cap, graph[to].size()));
    graph[to].push_back(Edge(from, 0, graph[from].size() - 1));
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    visited[v] = true;
    for (auto &e : graph[v]) {
        if (!visited[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow(int s, int t) {
    int flow = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        int f = dfs(s, t, INT_MAX);
        if (f == 0) break;
        flow += f;
    }
    return flow;
}

int main() {
    int N, M;
    cin >> N >> M;
    int s, t;
    cin >> s >> t;

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        addEdge(u, v, c);
    }

    int maxFlowValue = maxFlow(s, t);
    cout << maxFlowValue << endl;

    return 0;
}
