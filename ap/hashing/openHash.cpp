#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct Dict{
    int m;  //size of the hash table
    int cnt;   //n of elements
    list<pair<int,int>> **H;    // hash table as an array of lists
    //set<int> keysList;
};

int h(int key){
    return abs(key)%10;
}

Dict *create_dict(int size){
    Dict *d = new Dict;
    d->m = size;
    d->cnt = 0;
    d->H = new list<pair<int,int>>*[size];    //delete[] H //array
    for(int i=0;i<size;i++){
        d->H[i] = new list<pair<int,int>>;
    }
    return d;
}

int* find(Dict *d, int k){
    int pos = h(k);
    for(auto [key, value]:*d->H[pos]){
        if(key==k){
            return &value;
        }
    }
    return nullptr;
}

void insert(Dict *d, int k, int e){
    if (find(d,k)==nullptr){
        int pos = h(k);
        d->H[pos]->push_back(make_pair(k, e));
        //or d->H[pos]->push_back({k, e});
        //d->keysList.emplace(k);
        d->cnt++;
    }
}

void erase(Dict *d, int k){
    int pos = h(k);
    for(auto i=d->H[pos]->begin();i!=d->H[pos]->end();i++){
        if(i->first==k){
            d->H[pos]->erase(i);
            //d->keysList.erase(k);
            return;
        }
    }
}

// set<int> getKey(Dict *d){
//     return d->keysList;
// }

//print em qualquer ordem
// void print(Dict *d){
//     for(auto e: getKey(d)){
//         cout << *find(d, e);
//     }
// }

//print na ordem das listas
void print_(Dict *d, int index){
    for(auto e:*d->H[index]){
        cout << e.second << ' ';
    }
    cout << endl;
}

int main(){
    int n; cin>>n;
    int key;
    Dict *d = create_dict(10);
    for(int i=0;i<n;i++){
        cin >> key;
        insert(d,key,key);
    }
    for (int i = 0; i < 10; i++){
        cout << i << ' ';
        print_(d, i);
    }
    return 0;
}