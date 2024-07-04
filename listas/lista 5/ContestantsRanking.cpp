#include <bits/stdc++.h>

const int INF = INT_MAX; //a large number to represent infinity
//if the graphs has weights

using namespace std;

struct Graph{
    //pair<weight, edge>
    vector<vector<pair<int,string>>> list;  //adjacency list
    int numEdge;   //n of edges
    int numVert; //n of vertices
    vector<int> Mark;    // auxiliary marking array

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
    return -1; //nao tem vizinhos
}

int next(Graph *g, int v, int w){
    // if (g->list[v].size() > 0){

    // }
    for (auto i = g->list[v].begin(); i != g->list[v].end(); i++){
        if (i->second == w){
            i++;
            if (i != g->list[v].end()){
                return i->second;
            }
            break;
        }
    }
    return -1; // nao tem mais vizinhos
}

bool isEdge(Graph *g, int i, int j){
    for (auto &edge : g->list[i]){
        if (edge.second == j){
            return true;
        }
    }
    return false;
}

void setEdge(Graph *g, string i, string j){
    g->list[i].push_back(make_pair(wt, j));
    g->numEdge++;
    
}

void setMark(Graph *g, int v, int val){
    g->Mark[v] = val;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

queue<pair<int, int>> Dist(Graph *g, int start){
    queue<pair<int, int>> Q;
    Q.push({0, start});
    setMark(g, start, 0);
    while (Q.size() > 0){
        auto [dist, top] = Q.front();
        Q.pop();
        for (auto e : g->list[top]){
            if (getMark(g, e.second)==0){
                setMark(g, e.second, dist+1);
                Q.push({dist+1, e.second});
            }
        }
    }
    return Q;
}

int main(){
    int tests; cin >> tests;
    int teams;
    string name1, name2, name3;
    
    for (int i = 0; i < tests; i++){
        cin >> teams;
        Graph *g = new Graph(teams*3);
        for (int j = 0; j < teams; j++){
            cin >> name1 >> name2 >> name3;
        }

        delete(g);
        
    }
    return 0;
}