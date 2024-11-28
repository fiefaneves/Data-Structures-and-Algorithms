#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct List{
    int maxSize; //capacity
    int size;   //n elements
    int curr;   //position of the curr
    int *listArray;  //array with values
} List;

List *create_list(int size){
    List *l = (List*) malloc (sizeof (List));
    l->maxSize = size;
    l->size = l->curr = 0;
    l->listArray = (int*) malloc (size * sizeof(int));
    return l;
}

void moveToStart(List *l){
    l->curr = 0;
}

void moveToEnd(List *l){
    l->curr=l->size;
}

void prev(List *l){
    if (l->curr!=0){
        l->curr--;
    }
}

void next(List *l){
    if (l->curr<l->size){
        l->curr++;
    }
}

void insert(List *l, int it){
    if (l->size >= l->maxSize){
        cout << "Error.";
    }
    int i = l->size;
    while (i>l->curr){
        l->listArray[i] = l->listArray[i-1];
        i--;
    }
    l->listArray[l->curr] = it;
    l->size++;
}

int remove(List *l){
    if (l->curr<0 || l->curr>=l->size){
        return -1;
    }
    int it = l->listArray[l->curr];
    int i = l->curr;
    while (i<l->size-1){
        l->listArray[i] = l->listArray[i+1];
        i++;
    }
    l->size--;
    return it;
}

void print(List *l){
    for(int i=0;i<l->size;i++){
        cout << l->listArray[i] << " ";
    }
}

void destruct(List *l){
    free(l->listArray);
    free(l);
}

int count(List *l, int it){
    int cont=0;
    for(int i=0;i<l->size;i++){
        if(l->listArray[i]==it){
            cont++;
        }
    }
    return cont;
}

int main(){
    int cases; cin >> cases;
    for(int i=0;i<cases;i++){
        int n; cin >> n;
        List *l = create_list(n);
        cout << "Caso " << i+1 << ":" << endl;
        for(int j=0;j<n;j++){
            string operation; cin >> operation;
            if(operation=="insert"){
                int number; cin >> number;
                insert(l, number);
            }
            if(operation=="remove"){
                remove(l);
            }
            if(operation=="count"){
                int number; cin >> number;
                int cont = count(l, number);
                cout << cont << endl;
            }
            if(operation=="prev"){
                prev(l);
            }
            if(operation=="next"){
                next(l);
            }
        }
        destruct(l);
    }
}
