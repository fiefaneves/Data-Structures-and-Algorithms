#include <bits/stdc++.h>

using namespace std;

struct Dict{
    int m;
    int cnt;
    pair<int,int> *H;
};

int h(int key, int mod){
    int temp = (int) floor((((double) key) / ((double) mod)));
    return (key - (mod * temp));
}

Dict *create_dict(int size){
    Dict *d = new Dict;
    d->m = size;
    d->cnt = 0;
    d->H = new pair<int,int>[size];
    return d;
}

int Probing(int perm[], int p){    
    return perm[p-1];
}

int find(Dict *d, int k, int perm[], int size){
    int i = h(k, d->m);
    int p=1;
    if (d->H[i].first==k){
        return i;    
    }
    else{
        while(p<size+1){ 
            int newpos = Probing(perm, p);
            if (d->H[abs(i+newpos)%(d->m)].first==k){
                return abs(i+newpos)%(d->m);
            }
            p++;
        }
    }
    return -1;
}


void insert(Dict *d, int k, int e, int perm[], int size){
    int i = h(k, d->m);
    int p=1;
    if(find(d, k, perm, size)==-1){
        if (d->H[i]==pair<int,int>()){
            d->H[i] = make_pair(k,e);    
            d->cnt++;
        }
        else{
            while(p<size+1){ 
                int newpos = Probing(perm, p);
                if (d->H[abs(i+newpos)%(d->m)]==pair<int,int>()){
                    d->H[abs(i+newpos)%(d->m)] = make_pair(k,e);
                    d->cnt++;
                    break;
                }
                p++;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    while(n>1){
        int perm[n-1];
        int size=0;
        for (int i = 0; i < n-1; i++){
            cin >> perm[i];
            size++;
        }
        int operations; cin >> operations;
        string order;
        int key; 
        int value;
        Dict *d = create_dict(n);
        for (int i = 0; i < operations; i++){
            cin >> order;
            if (order == "add"){
                cin >> key >> value;
                insert(d, key, value, perm, size);
            }

            if (order == "find"){
                cin >> key;
                int aux = find(d, key, perm, size);
                if (aux == -1){
                    cout << aux << '\n';
                }
                else{
                    cout << aux << ' ' << d->H[aux].second << '\n';
                }   
            }            
        }
        cin >> n; 
    }
    return 0;
}