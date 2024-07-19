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
    int from; 
    int to; 

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
            if (getMark(g, e.second) != 1 && D[e.second] > e.first){
                D[e.second] = e.first;
                pq.push({D[e.second], t.to, e.second});
            }
        }
    }
}

int main(){
    int c, o;
    int x, y, p;
    int t=1;
    while(cin >> c >> o){
        if (c==0 && o==0) break;
        cout << "Caso " << t << ": ";
        Graph *g = new Graph(c);
        for (int i = 0; i < o; i++){
            cin >> x >> y >> p;
            setEdge(g, x, y, p);
        }
        vector<int> Dist(c);
        vector<int> Vert(c);
        Prim(g, Dist, Vert);

        int sum = 0;
        for (int i = 0; i < n(g); i++){
            sum = sum + Dist[i];
        }
        cout << sum << '\n';

        t++;
        delete g;
    }
    return 0;
}