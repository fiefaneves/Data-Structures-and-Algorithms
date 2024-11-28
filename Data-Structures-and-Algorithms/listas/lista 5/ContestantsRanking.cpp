#include <bits/stdc++.h>

const int INF = INT_MAX;

using namespace std;

struct Graph{
    map<string, unordered_set<string>> list;
    int numEdge;
    int numVert;
    map<string,int> Mark;

    Graph(){
        numEdge = 0;
    }
};

int n(Graph *g){
    return g->numVert;
}

int e(Graph *g){
    return g->numEdge;
}

string first(Graph *g, string v){
    if (!g->list[v].empty()){
        return *(g->list[v].begin());
    }
    return "";
}

string next(Graph *g, string v, string w){
    for (auto i = g->list[v].begin(); i != g->list[v].end(); i++){
        if (*i == w){
            i++;
            if (i != g->list[v].end()){
                return *i;
            }
            break;
        }
    }
    return "";
}

void setMark(Graph *g, string v, int val){
    g->Mark[v] = val;
}

int getMark(Graph *g, string v){
    return g->Mark[v];
}

void setEdge(Graph *g, string i, string j){
    g->list[i].insert(j);
    g->list[j].insert(i);
    setMark(g, i, INF);
    setMark(g, j, INF);
    g->numEdge++;
}

//visitado >= 0
//nao visitado = INF
void BFS(Graph *g, string start){
    queue<pair<string, int>> Q;
    Q.push({start,0});
    setMark(g, start, 0);
    while (Q.size() > 0){
        auto [v, d] = Q.front();
        Q.pop();
        auto w = first(g, v);
        while (w != ""){
            if (getMark(g, w) == INF){
                setMark(g, w, d+1);
                Q.push({w, d+1});
            }
            w = next(g, v, w);
        }
    }
}

int main(){
    int tests; cin >> tests;
    int teams;
    string name1, name2, name3;
    
    for (int i = 0; i < tests; i++){
        cin >> teams;
        Graph *g = new Graph();
        for (int j = 0; j < teams; j++){
            cin >> name1 >> name2 >> name3;
            setEdge(g, name1, name2);
            setEdge(g, name1, name3);
            setEdge(g, name2, name3);
        }
        BFS(g, "Ahmad");

        vector<pair<int, string>> answ;
        
        for (auto [k, v] : g->Mark){
            answ.push_back({v,k});    
        }

        stable_sort(answ.begin(), answ.end());
        cout << answ.size() << '\n';
        for (auto [v, k] : answ) {
            if (v == INF){
                cout << k << ' ' << "undefined" << '\n';
            }
            else{
                cout << k << ' ' << v << '\n';
            }
        }

        delete(g);
    }
    return 0;
}
