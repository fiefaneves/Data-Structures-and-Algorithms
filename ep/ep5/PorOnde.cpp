#include <bits/stdc++.h>

const int INF = INT_MAX;

using namespace std;

struct Graph{
    vector<vector<int>> list;
    int numEdge;   
    int numVert;

    Graph(int n){
        numVert = n;
        numEdge = 0;
        list.resize(n);
    }
};

void setEdge(Graph *g, int i, int j){
    g->list[i].push_back(j);
    g->list[j].push_back(i);
    g->numEdge++;
}

void BFS(Graph *g, vector<int>& Mark, vector<int>& Parent, int start, int end){
    int v;
    queue<int> Q;
    Q.push(start);
    Mark[start] = 0;
    Parent[start] = -1;
    while (Q.size() > 0){
        v = Q.front();
        Q.pop();
        for (auto e : g->list[v]){
            if (Mark[e] != INF){
                continue;
            }   
            Mark[e] = Mark[v]+1;
            Parent[e] = v;
            Q.push(e);
            if (e==end){
                break;
            }
        }
    }
}

int main(){
    int cases; cin >> cases;
    int v, a; 
    int n1, n2;
    int p;
    for (int i = 0; i < cases; i++){
        cin >> v >> a;
        cout << "Caso " << i+1 << '\n';
        Graph *g = new Graph(v);
        for (int j = 0; j < a; j++){
            cin >> n1 >> n2;
            setEdge(g, n1, n2);
        }

        for (vector<int>& e : g->list) {
            sort(e.begin(), e.end());
        }

        cin >> p;
        for (int k = 0; k < p; k++){
            cin >> n1 >> n2;
            vector<int> Mark(v, INF);
            vector<int> Parent(v, -2);
            BFS(g, Mark, Parent, n1, n2);
        
            stack<int> stack_answ;
            if (Parent[n2] != -2){
                while (Parent[n2] != -1){
                    stack_answ.push(n2);
                    n2 = Parent[n2];
                }
                stack_answ.push(n1);
                int size = (int) stack_answ.size();
                for (int it = 0; it < size; it++){
                    cout << stack_answ.top();
                    stack_answ.pop();
                    if (!stack_answ.empty()){
                        cout << ' ';
                    }
                }
                cout <<'\n';
            }
            else{
                cout << -1 << '\n';
            }
        }  
        delete g;
    }    
    return 0;      
}