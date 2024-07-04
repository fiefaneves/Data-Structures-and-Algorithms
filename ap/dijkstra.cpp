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

int n(Graph *g){
    return g->numVert;
}

int e(Graph *g){
    return g->numEdge;
}

int first(Graph *g, int v){
    if (!g->list[v].empty()){
        return g->list[v].front().second;
    }
    return -1; 
}

int next(Graph *g, int v, int w){
    for (auto i = g->list[v].begin(); i != g->list[v].end(); i++){
        if (i->second == w){
            i++;
            if (i != g->list[v].end()){
                return i->second;
            }
            break;
        }
    }
    return -1; 
}

void setEdge(Graph *g, int i, int j, int wt){
    for (auto edge : g->list[i]){
        if (edge.second == j){
            edge.first = wt;
            return;
        }        
    }
    g->list[i].push_back(make_pair(wt, j));
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

struct element{
    int dist;
    int from;
    int to;
};


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

        auto w = first(g, t.to);
        while (w < n(g)){
            if (getMark(g, w) != 1 && D[w] > D[t.to]+weight(g, t.to, w)){
                D[w] = D[t.to]+weight(g, t.to, w);
            }
            w = next(g, t.to, w);            
        }        
    }
}

int main(){

}