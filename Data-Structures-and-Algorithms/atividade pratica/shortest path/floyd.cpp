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

int first(Graph *g, int v){
    if (!g->list[v].empty()){
        return g->list[v].front().second;
    }
    return INF; 
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
    return INF; 
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

void floyd(Graph *g, vector<vector<int>> &D){
    for (int i = 0; i < n(g); i++){
        for (int j = 0; j < n(g); j++){
            if (i == j){
                D[i][j] = 0;
            }
            else{
                if (weight(g, i, j)!=0){
                    D[i][j] = weight(g, i, j);
                }
                else{
                    D[i][j] = INF;
                }
            }
        }
    }
    for (int k = 0; k < n(g); k++){
        for (int i = 0; i < n(g); i++){
            for (int j = 0; j < n(g); j++){
                if (D[i][k]!=INF && D[k][j]!=INF && D[i][j]>D[i][k]+D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;
    Graph *g = new Graph(n);
    int a, b, wt;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> wt;
        setEdge(g, a, b, wt);
    }
    vector<vector<int>> Dist(n, vector<int>(n, 0));
    floyd(g, Dist);
    // for (int i = 0; i < (int)Dist.size(); i++){
    //     cout << Dist[i] << ' ';
    // }
    cout << '\n';
    delete g;
    return 0;
}