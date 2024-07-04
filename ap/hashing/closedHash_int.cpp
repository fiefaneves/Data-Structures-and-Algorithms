#include <bits/stdc++.h>

using namespace std;

struct Dict{
    int m;  //size of the hash table
    int cnt;   //n of elements
    pair<int,int> *H;    // hash table as an array of pair
};

int h(int key){
    return abs(key)%10;
}

int s(int key){
    //new hash function;
    /* code */
    return 0;
}

Dict *create_dict(int size){
    Dict *d = new Dict;
    d->m = size;
    d->cnt = 0;
    d->H = new pair<int,int>[size];
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

int doublehashing(int p, int key){
    return p * s(key);
}

pair<int,int> find(Dict *d, int k){
    int i = h(k);
    int p=0;
    while(p<d->m){
        if (d->H[(i+linearProbing(p))%d->m].first==k){
            return d->H[(i+linearProbing(p))%d->m];    
        }
        p++;
    }
    return pair<int,int>();
}

int findAp(Dict *d, int k){
    int i = h(k);
    int p=0;
    while(p<d->m){
        if (d->H[(i+linearProbing(p))%d->m].first==k){
            return (i+linearProbing(p))%d->m;    
        }
        p++;
    }
    return -1;
}

void insert(Dict *d, int k, int e){
    int i = h(k);
    int p=0;
    if(d->H[(i+linearProbing(p))%d->m]==pair<int,int>()){
        d->H[(i+linearProbing(p))%d->m] = make_pair(k,e);
        d->cnt++;
    }
    else{
        while(d->H[(i+linearProbing(p))%d->m]!=pair<int,int>() && p<d->m){
            p++;
        }
        if(d->H[(i+linearProbing(p))%d->m]==pair<int,int>()){
            d->H[(i+linearProbing(p))%d->m] = make_pair(k,e);
            d->cnt++;
        }
    }
}

void erase(Dict *d, int k){
    int i = h(k);
    int p=0;
    while(p<d->m){
        if (d->H[(i+linearProbing(p))%d->m].first==k){
            d->H[(i+linearProbing(p))%d->m]=pair<int,int>();    
        }
        p++;
    }
}

void print(Dict *d){
    for (int i = 0; i < d->m; i++){
        if (d->H[i]!=pair<int,int>()){
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
    int order;
    int value;
    Dict *d = create_dict(operations);
    //if using pseudorandom probing
    // int perm[d->m];
    // for(int i=0;i<d->m;i++){
    //     perm[i]=i;
    // }
    // randomSwaps(perm,d->m,20);
    for (int i = 0; i < operations; i++){
        cin >> order;
        if (order == 0){
            cin >> value;
            insert(d,value,value);
        }
        else if (order == 1){
            cin >> value;
            int index = findAp(d,value);
            cout << value << ' ' << index << '\n';
        }
        else if (order == 2){
            cin >> value;
            erase(d,value);
        }
    }     
    return 0;
}


// void erase(Dict *d, int k, int perm[]){
//     int i = h(k, d->m);
//     int p=0;
//     if(find(d, k, perm)!=-1){
//         if (d->H[i].first==k){
//             d->H[i] = pair<int,int>();    
//         }
//         else{
//             while(p<perm.size()){ 
//                 int newpos = Probing(perm, p);
//                 if (d->H[abs(i+newpos)%d->m].first==k){
//                     d->H[abs(i+newpos)%d->m] = pair<int,int>();
//                 }
//                 p++;
//             }
//         }
//     }
// }