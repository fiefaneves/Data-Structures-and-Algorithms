#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

struct Graph {
    vector<vector<pair<int, int>>> list;
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

int first(Graph* g, int v) {
    if (!g->list[v].empty()) {
        return g->list[v].front().second;
    }
    return -1;
}

int next(Graph* g, int v, int w) {
    for (auto i = g->list[v].begin(); i != g->list[v].end(); ++i) {
        if (i->second == w) {
            ++i;
            if (i != g->list[v].end()) {
                return i->second;
            }
            break;
        }
    }
    return -1;
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

int weight(Graph* g, int i, int j) {
    for (const auto& edge : g->list[i]) {
        if (edge.second == j) {
            return edge.first;
        }
    }
    return 0;
}

void setMark(Graph* g, int v, int val) {
    g->Mark[v] = val;
}

int getMark(Graph* g, int v) {
    return g->Mark[v];
}

bool DFSCycleCheck(Graph* g, int v, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (const auto& neighbor : g->list[v]) {
            if (!visited[neighbor.second] && DFSCycleCheck(g, neighbor.second, visited, recStack)) {
                return true;
            } else if (recStack[neighbor.second]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isAcyclic(Graph* g) {
    vector<bool> visited(n(g), false);
    vector<bool> recStack(n(g), false);
    for (int i = 0; i < n(g); ++i) {
        if (DFSCycleCheck(g, i, visited, recStack)) {
            return false;
        }
    }
    return true;
}

void toposort(Graph* g, int v, stack<int>& s) {
    setMark(g, v, 1);
    int w = first(g, v);
    while (w != -1) {
        if (getMark(g, w) == 0) {
            toposort(g, w, s);
        }
        w = next(g, v, w);
    }
    s.push(v);
}

void topologicalSort(Graph* g) {
    if (isAcyclic(g)) {
        stack<int> s;
        for (int i = 0; i < n(g); ++i) {
            if (getMark(g, i) == 0) {
                toposort(g, i, s);
            }
        }
        while (!s.empty()) {
            cout << s.top() + 1 << ' '; // Convert back to 1-based indexing for output
            s.pop();
        }
    } else {
        cout << "Sandro fails.";
    }
    cout << endl;
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
