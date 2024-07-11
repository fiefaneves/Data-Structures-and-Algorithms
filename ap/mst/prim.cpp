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

// void Prim(Graph *g, vector<int> &D, vector<int> &V){
//     priority_queue<element, vector<element>, greater<element>> pq;
//     for (int i = 0; i < n(g); i++){
//         D[i] = INF;
//         V[i] = 0;
//         setMark(g, i, 0);
//     }
//     pq.push({0, 0, 0});
//     D[0] = 0;
//     for (int i = 0; i < n(g); i++){
//         element t;
//         do{
//             if (pq.empty()){return;}
//             t = pq.top();
//             pq.pop();
//         }while (!getMark(g,t.to)==0);
        
//         setMark(g, t.to, 1);
//         V[t.to] = t.from;

//         auto w = first(g, t.to);
//         while (w < n(g)){
//             if (getMark(g, w) != 1 && D[w] > weight(g, t.to, w)){
//                 D[w] = weight(g, t.to, w);
//                 pq.push({D[w], t.to, w});
//             }
//             w = next(g, t.to, w);            
//         }
//     }
// }

void Prim(Graph *g, vector<int> &D, vector<int> &V){
    priority_queue<element, vector<element>, greater<element>> pq;
    for (int i = 0; i < n(g); i++){
        D[i] = INF;
        V[i] = 0;
        setMark(g, i, 0);
    }
    pq.push({0, 0, 0});
    D[0] = 0;
    for (int i = 0; i < n(g); i++){
        element t;
        do{
            if (pq.empty()){return;}
            t = pq.top();
            pq.pop();
        }while (!getMark(g,t.to)==0);
        
        setMark(g, t.to, 1);
        V[t.to] = t.from;
        for (auto e : g->list[t.to]){
            if (getMark(g, e.second) != 1 && D[e.second] > D[t.to]+weight(g, t.to, e.second)){
                D[e.second] = D[t.to]+weight(g, t.to, e.second);
                pq.push({D[e.second], t.to, e.second});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    Graph *g = new Graph(n);
    int a, b, wt;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> wt;
        setEdge(g, a, b, wt);
    }
    vector<int> Dist(n);
    vector<int> Vert(n);
    Prim(g, Dist, Vert);
    int sum = 0;
    for (int i = 0; i < (int)Dist.size(); i++){
        sum = sum + Dist[i];
    }
    cout << sum << '\n';
    delete g;
    return 0;
}