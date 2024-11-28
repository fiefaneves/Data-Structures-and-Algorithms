#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

struct Graph{
    vector<vector<pair<int, int> > > list;
    int numEdge;
    int numVert;
    vector<int> indegree;

    Graph(int n){
        numVert = n;
        numEdge = 0;
        list.resize(n);
        indegree.resize(n, 0);
    }
};

int n(Graph *g){
    return g->numVert;
}

void setEdge(Graph *g, int i, int j, int wt){
    for (auto &edge : g->list[i]){
        if (edge.second == j){
            edge.first = wt;
            return;
        }
    }
    g->list[i].push_back(make_pair(wt, j));
    g->numEdge++;
    g->indegree[j]++;
}

void topologicalSort(Graph *g){
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n(g); i++){
        if (g->indegree[i] == 0){
            pq.push(i);
        }
    }

    vector<int> topoSorted;
    while (!pq.empty()){
        int v = pq.top();
        pq.pop();
        topoSorted.push_back(v);

        for (auto &edge : g->list[v]){
            if (--g->indegree[edge.second] == 0){
                pq.push(edge.second);
            }
        }
    }

    if ((int)topoSorted.size() != n(g)){
        cout << "Sandro fails.";
    }
    else{
        for (int v : topoSorted){
            cout << v + 1 << ' ';
        }
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int i, j;
    Graph *g = new Graph(n);
    for (int it = 0; it < m; it++){
        cin >> i;
        cin >> j;
        setEdge(g, i - 1, j - 1, 1);
    }
    topologicalSort(g);
    delete g;
    return 0;
}