#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int INF = INT_MAX;

void bfs(vector<vector<int>>& adj, vector<int>& dist, vector<int>& parent, int start, int end) {
    queue<int> operation_order;

    operation_order.push(start);
    dist[start] = 0;
    parent[start] = -1;

    while(!operation_order.empty()) {
        auto v = operation_order.front(); operation_order.pop();

        for (auto u : adj[v]) {
            if (dist[u] != INF) continue;

            dist[u] = dist[v]+1;
            parent[u] = v;
            operation_order.push(u);
            
            if (u == end) break;
        }
    }
}

int solve() {

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);

    int x, y;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (vector<int>& e : adj) {
        sort(e.begin(), e.end());
    }

    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        
        vector<int> dist(n, INF);
        vector<int> parent(n, -2);

        bfs(adj, dist, parent, x, y);
    
        stack<int> answ;

        if (parent[y] != -2) {
            while(parent[y] != -1) {
                answ.push(y);
                y = parent[y];
            } answ.push(x);
        } else {
            cout << -1 << endl;
            return 1;
        }

        while(1) {
            cout << answ.top(); answ.pop();
            if (!answ.empty()) cout << ' ';
            else {cout << endl; break; }
        }
    } 

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c = 0;
    int tc; cin >> tc; while (tc--) {
        cout << "Caso " << ++c << endl;
        solve();
    }

    return 0;
}