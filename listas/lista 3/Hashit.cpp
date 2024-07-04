#include <bits/stdc++.h>

using namespace std;

struct Dict{
    int m;
    int cnt; 
    pair<int,string> *H;
};

int h(Dict *d, string key){
    int s = key.size();
    int sum = 0;
    for (int i = 0; i<s; i++){
        sum = sum + (key[i]*(i+1));
    }
    return abs(sum*19)%(d->m);   
}

Dict *create_dict(int size){
    Dict *d = new Dict;
    d->m = size;
    d->cnt = 0;
    d->H = new pair<int,string>[size];
    return d;
}

int Probing(int p){
    int newpos = p*p+23*p;
    return newpos;
}

pair<int,string> find(Dict *d, string k){
    int i = h(d, k);
    int p=1;
    if (d->H[i].second==k){
        return d->H[i];    
    }
    else{
        while(p<20){ 
            int newpos = Probing(p);
            if (d->H[abs(i+newpos)%(d->m)].second==k){
                return d->H[abs(i+newpos)%(d->m)];
            }
            p++;
        }
    }
    return pair<int,string>();
}

void insert(Dict *d, string k){
    int i = h(d, k);
    int p=1;
    if(find(d, k)==pair<int,string>()){
        if (d->H[i]==pair<int,string>()){
            d->H[i] = make_pair(i,k);    
            d->cnt++;
        }
        else{
            while(p<20){ 
                int newpos = Probing(p);
                if (d->H[abs(i+newpos)%(d->m)]==pair<int,string>()){
                    d->H[abs(i+newpos)%(d->m)] = make_pair(abs(i+newpos)%(d->m),k);
                    d->cnt++;
                    break;
                }
                p++;
            }   
        }
    }
}

void erase(Dict *d, string k){
    pair<int,string> aux = find(d,k);
    if(aux.second==k){
        d->H[aux.first]=pair<int,string>();
        d->cnt--;
    }
}

void print(Dict *d){
    for (int i = 0; i < d->m; i++){
        if (d->H[i]!=pair<int,string>()){
            cout << d->H[i].first << ':' << d->H[i].second;
            if (i<((d->m)+1)){
                cout << '\n';
            }
        }
    }
}

int main(){
    int tests; cin >> tests;
    for (int j = 0; j < tests; j++){
        Dict *d = create_dict(101);
        int operations; cin >> operations;
        for (int i = 0; i < operations; i++){
            string line; cin >> line;
            size_t colonPos = line.find(':');
            string command = line.substr(0, colonPos);
            string key = line.substr(colonPos + 1);
            if (command == "ADD"){
                insert(d,key);
            }
            else if (command == "DEL"){
                erase(d,key);
            }   
        }
        cout << d->cnt << '\n';
        print(d);
    }
    return 0;
}