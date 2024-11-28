#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void heapify(vector<char> &H){
    int size = H.size()-1;
    for (int i = (size)/2; i >= 1; i--){
        int k = i;
        int v = H[k]; 
        bool heap = false;
        while (!heap && 2*k <= size){
            int j = 2*k;
            if (j<size){
                if (H[j] < H[j+1]){
                    j = j + 1;
                }
            }
            if (v >= H[j]){
                heap = true;
            }
            else{
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

void removeMax(vector<char> &H, int &count){
    int size = H.size()-1;
    if (size < 1){
        cout << "Heap vazia!" << '\n';
        return;
    }
    H[1] = H[size]; 
    H.pop_back();
    count--;
    size--;
    int k = 1;
    int v = H[k];
    bool heap = false;
    while (!heap && 2*k <= size){
        int j = 2*k;
        if (j<size){
            if (H[j] < H[j+1]){
                j = j + 1;
            }
        }
        if (v >= H[j]){ 
            heap = true;
        }
        else{
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}

void heapsort(vector<char> &H){
    int size = H.size() - 1;
    if (size < 1){
        return;
    }
    while (size > 1){
        swap(H[1], H[size]);
        size--;
        int k = 1;
        int v = H[k];
        bool heap = false;
        while (!heap && 2 * k <= size) {
            int j = 2 * k;
            if (j < size){
                if (H[j] < H[j+1]){
                    j = j + 1;
                }                
            }
            if(v >= H[j]){
                heap = true;
            }
            else{
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

void findMax(vector<char> &H){
    int size = H.size()-1;
    if (size < 1){
        cout << "Não há elemento no topo." << '\n';
        return;
    }
    else{
        cout << H[1] << '\n';
    }
}

void print(vector<char> &H){
    int size = H.size();
    for (int i = 1 ; i < size ; i++){
        cout << H[i] << ' ';
    }
    cout << '\n';
}

bool isLeaf(vector<char> &H, int pos){
    int size = H.size();
    return (pos >= size/2) && (pos < size);
}

int leftchild(int pos){
    return 2*pos;
}

int rightchild(int pos){
    return 2*pos+1;
}

int parent(int pos){ 
    return (pos-1)/2; 
}

int main(){
    long long int TAM; cin >> TAM;
    int n; cin >> n;
    string command;
    char data;
    vector<char> H;
    int count=1;
    H.push_back('0');
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == "insert"){
            cin >> data;
            if (count < TAM+1){
                H.push_back(data);
                heapify(H);
                count++;
            }
            else{
                cout << "Tamanho máximo atingido!" << '\n';
            }
        }
        else if (command == "max"){
            findMax(H);
        }
        else if (command == "remove"){
            removeMax(H, count);
        }   
    }
    heapsort(H);
    print(H);
    return 0;
}