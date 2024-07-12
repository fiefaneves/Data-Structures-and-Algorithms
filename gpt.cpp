#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, weight;
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

void solve() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        vector<bool> visited(n, false);
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        pq.push({0, 0, 0});

        int maxEdgeWeight = 0;
        int edgesUsed = 0;

        while (!pq.empty()) {
            Edge current = pq.top();
            pq.pop();

            if (visited[current.to]) continue;
            visited[current.to] = true;
            maxEdgeWeight = max(maxEdgeWeight, current.weight);
            edgesUsed++;

            for (auto& [next, weight] : graph[current.to]) {
                if (!visited[next]) {
                    pq.push({current.to, next, weight});
                }
            }
        }

        if (edgesUsed == n) {
            cout << maxEdgeWeight << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
