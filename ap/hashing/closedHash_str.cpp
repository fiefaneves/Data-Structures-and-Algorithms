#include <bits/stdc++.h>

using namespace std;

struct Dict{
    int m;  //size of the hash table
    int cnt;   //n of elements
    pair<string,string> *H;    // hash table as an array of pair
};

int h(Dict *d, string key){
    int s = key.size();
    int sum = 0;
    for (int i = 0; i<s; i++){
        sum = sum + key[i];
    }
    return abs(sum)%d->m;   
}

int s(string key){
    //new hash function;
    return 0;
}

Dict *create_dict(int size){
    Dict *d = new Dict;
    d->m = size;
    d->cnt = 0;
    d->H = new pair<string,string>[size];
    return d;
}

int linearProbing(int p){
    return p;
}

int pseudo_randomProbing(int perm[], int p){
    return perm[p];
}

int quadraticProbing(int p){
    return ((p*p)+p)/2;
}

int doublehashing(int p, string key){
    return p * s(key);
}

pair<string,string> find(Dict *d, string k){
    int i = h(d,k);
    int p=0;
    while(p<d->m){
        if (d->H[(i+linearProbing(p))%d->m].first==k){
            return d->H[(i+linearProbing(p))%d->m];    
        }
        p++;
    }
    return pair<string,string>();
}

int findAp(Dict *d, string k){
    int i = h(d,k);
    int p=0;
    while(p<d->m){
        if (d->H[(i+linearProbing(p))%d->m].first==k){
            return (i+linearProbing(p))%d->m;    
        }
        p++;
    }
    return -1;
}

void insert(Dict *d, string k, string e){
    int i = h(d, k);
    int p=0;
    if(d->H[(i+linearProbing(p))%d->m]==pair<string,string>()){
        d->H[(i+linearProbing(p))%d->m] = make_pair(k,e);
        d->cnt++;
    }
    else{
        while(d->H[(i+linearProbing(p))%d->m]!=pair<string,string>() && p<d->m){
            p++;
        }
        if(d->H[(i+linearProbing(p))%d->m]==pair<string,string>()){
            d->H[(i+linearProbing(p))%d->m] = make_pair(k,e);
            d->cnt++;
        }
    }
}

void erase(Dict *d, string k){
    int i = h(d, k);
    int p=0;
    while(p<d->m){
        if (d->H[(i+linearProbing(p))%d->m].first==k){
            d->H[(i+linearProbing(p))%d->m]=pair<string,string>();    
        }
        p++;
    }
}

void print(Dict *d){
    for (int i = 0; i < d->m; i++){
        if (d->H[i]!=pair<string,string>()){
            cout << d->H[i].first << ' ';
        }
    }
    cout << endl;
}

// void randomSwaps(int array[], int n, int numSwaps) {
//     srand(time(NULL));

//     for (int i = 0; i < numSwaps; i++) {
//         int idx1 = rand() % n;
//         int idx2 = rand() % n;
//         swap(array[idx1], array[idx2]);
//     }
// }

int main(){
    int operations; cin >> operations;
    string order;
    string value;
    Dict *d = create_dict(operations);
    //if using pseudorandom probing
    // int perm[d->m];
    // for(int i=0;i<d->m;i++){
    //     perm[i]=i;
    // }
    // randomSwaps(perm,d->m,20);
    for (int i = 0; i < operations; i++){
        cin >> order;
        if (order == "add"){
            cin >> value;
            insert(d,value,value);
        }
        else if (order == "sch"){
            cin >> value;
            int index = findAp(d,value);
            cout << value << ' ' << index << '\n';
        }
        else if (order == "rmv"){
            cin >> value;
            erase(d,value);
        }
    }     
    return 0;
}