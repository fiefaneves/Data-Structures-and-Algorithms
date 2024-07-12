#include <bits/stdc++.h>

const int INF = INT_MAX;

using namespace std;

struct Graph{
    vector<vector<pair<int,int>>> list;  
    int numEdge;  
    int numVert; 
    vector<int> Mark;  

    Graph(int n){
        numVert = n;
        numEdge = 0;
        list.resize(n);
        Mark.resize(n, 0);
    }
};

struct element{
    int dist;
    int from; //p
    int to; //v

    bool operator>(const element& other) const {
        return dist > other.dist;
    }
};

int n(Graph *g){
    return g->numVert;
}

void setEdge(Graph *g, int i, int j, int wt){
    g->list[i].push_back(make_pair(wt, j));
    g->list[j].push_back(make_pair(wt, i));
    g->numEdge++;
}

void setMark(Graph *g, int v, int val){
    g->Mark[v] = val;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

void solve(Graph *g){
    priority_queue<element, vector<element>, greater<element>> pq;
    pq.push({0, 0, 0});

    int maxEdgeWeight = 0;
    int edgesUsed = 0;

    while (!pq.empty()){
        element t = pq.top();
        pq.pop();

        if (getMark(g, t.to)==1) continue;
        setMark(g, t.to, 1);
        maxEdgeWeight = max(maxEdgeWeight, t.dist);
        edgesUsed++;

        for (auto& e : g->list[t.to]){
            if (getMark(g, e.second) != 1){
                pq.push({e.first, t.to, e.second});
            }
        }
    }

    if (edgesUsed == n(g)){
        cout << maxEdgeWeight << '\n';
    } else{
        cout << "IMPOSSIBLE" << '\n';
    }
}

int main(){
    int n, m;
    int x, y, wt;
    while (cin >> n >> m){
        if (n == 0 && m == 0) break;
        Graph *g = new Graph(n);
        for (int i = 0; i < m; i++){
            cin >> x >> y >> wt;
            setEdge(g, x, y, wt);
        }
        solve(g);
        delete g;
    }
    return 0;
}