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

int e(Graph *g){
    return g->numEdge;
}

void setEdge(Graph *g, int i, int j, int wt){
    g->list[i].push_back(make_pair(wt, j));
    g->list[j].push_back(make_pair(wt, i));
    g->numEdge++;
}

int weight(Graph *g, int i, int j){
    for (auto edge : g->list[i]){
        if (edge.second == j){
            return edge.first;
        }
    }
    return 0;
}

void setMark(Graph *g, int v, int val){
    g->Mark[v] = val;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

void Dijkstra(Graph *g, int s, vector<int> &D){
    vector<int> P(n(g));
    priority_queue<element, vector<element>, greater<element>> pq;
    for (int i = 0; i < n(g); i++){
        D[i] = INF;
        P[i] = 0;
        setMark(g, i, 0);
    }
    pq.push({0, s, s});
    D[s] = 0;
    for (int i = 0; i < n(g); i++){
        element t;
        do{
            if (pq.empty()){return;}
            t = pq.top();
            pq.pop();
        }while (!getMark(g,t.to)==0);
        
        setMark(g, t.to, 1);
        P[t.to] = t.from;

        for (auto e : g->list[t.to]){
            if (getMark(g, e.second) != 1 && D[e.second] > D[t.to]+weight(g, t.to, e.second)){
                D[e.second] = D[t.to]+weight(g, t.to, e.second);
                pq.push({D[e.second], t.to, e.second});
            }
        }
    }
}

int main(){
    int cases; cin >> cases;
    int n, m , S, T;
    int x, y, wt;
    for (int i = 0; i < cases; i++){
        cout << "Case #" << i+1 << ": ";
        cin >> n >> m >> S >> T;
        Graph *g = new Graph(n);
        for (int j = 0; j < m; j++){
            cin >> x >> y >> wt;
            setEdge(g, x, y, wt);
        }
        vector<int> Dist(n);
        Dijkstra(g, S, Dist);
        if (Dist[T] != INF){
            cout << Dist[T];
        }
        else{
            cout << "unreachable";
        }
        cout << '\n';
        delete g;
    }
    return 0;
}