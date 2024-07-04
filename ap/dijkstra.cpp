#include <bits/stdc++.h>

const int INF = INT_MAX;

using namespace std;

struct Graph{
    //pair<weight, edge>
    vector<vector<pair<int,int>>> list;  //adjacency list
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

void setEdge(Graph *g, int i, int j, int wt){
    // if (wt == 0){
    //     cout << 'error' << '\n';
    //     return;
    // }
    for (auto edge : g->list[i]){
        if (edge.second == j){
            edge.first = wt;
            return;
        }        
    }
    g->list[i].push_back(make_pair(wt, j));
    g->numEdge++;
}

void delEdge(Graph *g, int i, int j){
    for (auto it = g->list[i].begin(); it != g->list[i].end(); it++){
        if (it->second == j){
            g->list[i].erase(it);
            g->numEdge--;
            return;
        }
    }
}

bool isEdge(Graph *g, int i, int j){
    for (auto edge : g->list[i]){
        if (edge.second == j){
            return true;
        }
    }
    return false;
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

// void print(Graph *g){

// }

//UNVISITED = 0
//VISITED = 1
void graphTraverse(Graph *g){
    int cont = 0;
    for (int v = 0; v < n(g); v++){
        setMark(g, v, 0);
    }
    for (int v = 0; v < n(g); v++){
        if (getMark(g, v) == 0){
            cont++; //if cont==1 -> graph = conexo else -> graph = desconexo
            //traverse(g, v); //DFS or BFS
        }
    }
}

//depth-first search
//finding articulation points
void DFS(Graph *g, int v){
    //preVisit(g, v);
    setMark(g, v, 1);
    int w = first(g, v);
    while (w < n(g)){ //while (w != -1){
        if (getMark(g, w) == 0){
            DFS(g, w);
        }
        w = next(g, v, w);
    }
    //posVisit(g, v);
}

//breadth-first search
//finding a path with the fewest number of edges between two given vertices
void BFS(Graph *g, int start){
    int v;
    int w;
    queue<int> Q;
    Q.push(start);
    setMark(g, start, 1);
    while (Q.size() > 0){
        v = Q.front();
        Q.pop();
        //preVisit(g, v);
        w = first(g, v);
        while (w < n(g)){ //while (w != -1){
            if (getMark(g, w) == 0){
                setMark(g, w, 1);
                Q.push(w);
            }
            w = next(g, v, w);
        }
        //posVisit(g, v);
    }
}

int components(Graph *g){
    int c = 0;
    for (int i = 0; i < n(g); i++){
        if(getMark(g, i) == 0){
            BFS(g, i);
            c++;
        }
    }
    return c;
}

bool isDisc(Graph *g){
    BFS(g, 0);
    for (int i = 0; i < n(g); i++){
        if (getMark(g, i) == 0){
            return true;
        }
    }
    return false;
}

queue<pair<int, int>> Dist(Graph *g, int start){
    queue<pair<int, int>> Q;
    Q.push({0, start});
    setMark(g, start, 0);
    while (Q.size() > 0){ //while (w != -1){
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

void toposort(Graph *g, int v, stack<int> &s){
    setMark(g, v, 1);
    int w = first(g, v);
    while (w != -1){
        if (getMark(g, w) == 0){
            toposort(g, w, s);
        }
        w = next(g, v, w);
    }
    s.push(v);
}

void topologicalSort(Graph *g){
    stack<int> s;
    for (int i = 0; i < n(g); ++i){
        if (getMark(g, i) == 0){ 
            toposort(g, i, s); 
        }
    }
    while (!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

void Dijkstra(Graph *g, int s, vector<int> &D){
    vector<int> P(n(g));
    for (int i = 0; i < n(g); i++){
        D[i] = INF;
        P[i] = 0;
        setMark(g, i, 0);
    }
    
}

int main(){

}