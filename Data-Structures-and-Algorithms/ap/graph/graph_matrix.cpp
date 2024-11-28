#include <bits/stdc++.h>

#define endl '\n'

const int INF = 1e9; //a large number to represent infinity
//if the graphs has weights

using namespace std;

struct Graph{
    vector<vector<int>> matrix;  //adjacency matrix
    int numEdge;   //n of edges
    int numVert; //n of vertices
    vector<int> Mark;    // auxiliary marking array
};

Graph *create_graph(int n){
    Graph *g = new Graph;
    g->Mark = vector<int>(n, 0);
    g->matrix = vector<vector<int>>(n, vector<int>(n, 0));
    g->numEdge = 0;
    g->numVert = n;
    return g;
}

int n(Graph *g){
    return g->numVert;
}

int e(Graph *g){
    return g->numEdge;
}

int first(Graph *g, int v){
    for (int i = 0; i < n(g); i++){
        if (g->matrix[v][i] != 0){
            return i;
        }        
    }
    return n(g);
}

int next(Graph *g, int v, int w){
    for (int i = w+1; i < n(g); i++){
        if (g->matrix[v][i] != 0){
            return i;
        }
    }
    return n(g);
}

void setEdge(Graph *g, int i, int j, int wt){
    // if (wt == 0){
    //     cout << 'error' << '\n';
    //     return;
    // }
    if (g->matrix[i][j] == 0){
        g->numEdge++;
    }
    g->matrix[i][j] = wt;
    g->matrix[j][i] = wt; //não dirigido
}

void delEdge(Graph *g, int i, int j){
    if (g->matrix[i][j] != 0){
        g->numEdge--; 
        g->matrix[i][j] = 0;  
    }
}

bool isEdge(Graph *g, int i, int j){
    return g->matrix[i][j] != 0;
}

int weight(Graph *g, int i, int j){ //if it is a weighted graph (use INF)
    return g->matrix[i][j];
}

void setMark(Graph *g, int v, int val){
    g->Mark[v] = val;
}

int getMark(Graph *g, int v){
    return g->Mark[v];
}

// void print(Graph *g){

// }

//depth-first search
//finding articulation points
void DFS(Graph *g, int v){
    //preVisit(g, v);
    cout << v << ' ';
    setMark(g, v, 1);
    int w = first(g, v);
    while (w < n(g)){
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
        cout << v << ' ';
        w = first(g, v);
        while (w < n(g)){
            if (getMark(g, w) == 0){
                setMark(g, w, 1);
                Q.push(w);
            }
            w = next(g, v, w);
        }
        //posVisit(g, v);
    }
}

void toposort(Graph *g, int v, stack<int> s){
    setMark(g, v, 1);
    int w = first(g, v);
    while (w < n(g)){
        if (getMark(g, w) == 0){
            toposort(g, w, s);
        }
        w = next(g, v, w);
    }
    s.push(v);
}

//UNVISITED = 0
//VISITED = 1
void graphTraverseBFS(Graph *g, int u){
    for (int v = 0; v < n(g); v++){
        setMark(g, v, 0);
    }
    for (int i = u; i < n(g); i++){
        if (getMark(g, i) == 0){
            BFS(g, i);
        }
    }
}

void graphTraverseDFS(Graph *g, int u){
    for (int v = 0; v < n(g); v++){
        setMark(g, v, 0);
    }
    for (int v = u; v < n(g); v++){
        if (getMark(g, v) == 0){
            DFS(g, v);
        }
    }
}

int main(){
    int n; cin >> n;
    int q; cin >> q;
    Graph *g = create_graph(n);
    int i, j, u;
    string op;
    for (int it = 0; it < q; it++){
        cin >> op;
        if (op == "add"){
            cin >> i;
            cin >> j;
            setEdge(g, i, j, 1);
        }
        else if(op == "BFS"){
            cin >> u;
            graphTraverseBFS(g, u);
            cout << endl;
        }
        else if(op == "DFS"){
            cin >> u;
            graphTraverseDFS(g, u);
            cout << endl;
        }
    }
    return 0;
}