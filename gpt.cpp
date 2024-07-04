#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

struct Graph {
    vector<vector<pair<int,int>>> list;
    int numEdge;
    int numVert;
    vector<int> Mark;

    Graph(int n) {
        numVert = n;
        numEdge = 0;
        list.resize(n);
        Mark.resize(n, 0);
    }
};

int n(Graph* g) {
    return g->numVert;
}

int e(Graph* g) {
    return g->numEdge;
}

void setEdge(Graph* g, int i, int j, int wt) {
    for (auto& edge : g->list[i]) {
        if (edge.second == j) {
            edge.first = wt;
            return;
        }
    }
    g->list[i].emplace_back(wt, j);
    g->numEdge++;
}

void setMark(Graph* g, int v, int val) {
    g->Mark[v] = val;
}

int getMark(Graph* g, int v) {
    return g->Mark[v];
}

bool isAcyclic(Graph* g) {
    vector<int> inDegree(n(g), 0);
    for (int i = 0; i < n(g); ++i) {
        for (auto& edge : g->list[i]) {
            inDegree[edge.second]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n(g); ++i) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    int count = 0;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        for (auto& edge : g->list[u]) {
            if (--inDegree[edge.second] == 0) {
                pq.push(edge.second);
            }
        }
        count++;
    }

    return (count == n(g));
}

void topologicalSort(Graph* g) {
    vector<int> inDegree(n(g), 0);
    for (int i = 0; i < n(g); ++i) {
        for (auto& edge : g->list[i]) {
            inDegree[edge.second]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n(g); ++i) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> topoOrder;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        topoOrder.push_back(u);

        for (auto& edge : g->list[u]) {
            if (--inDegree[edge.second] == 0) {
                pq.push(edge.second);
            }
        }
    }

    if ((int)topoOrder.size() != n(g)) {
        cout << "Sandro fails." << endl;
    } else {
        for (int v : topoOrder) {
            cout << v + 1 << ' '; // Convert back to 1-based indexing for output
        }
        cout << endl;
    }
}

int main() {
    int numVertices;
    cin >> numVertices;
    int numEdges;
    cin >> numEdges;

    Graph* g = new Graph(numVertices);

    for (int it = 0; it < numEdges; ++it) {
        int i, j;
        cin >> i >> j;
        setEdge(g, i - 1, j - 1, 1); // Convert to 0-based indexing
    }

    topologicalSort(g);

    delete g;
    return 0;
}
