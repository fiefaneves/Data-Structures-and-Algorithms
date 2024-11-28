#include <bits/stdc++.h>

using namespace std;

void heapifyhelp(vector<int> &H, int n, int i){
    int k = i;
    int v = H[k];
    bool heap = false;
    while (!heap && 2 * k <= n) {
        int j = 2 * k;
        if (j < n){
            if (H[j] > H[j+1]){
                j = j + 1;
            }                
        }
        if(v <= H[j]){
            heap = true;
        }
        else{
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}

void heapify(vector<int> &H){
    int size = H.size()-1;
    for (int i = (size)/2; i >= 1; i--){
        heapifyhelp(H, size, i);
    }
}

void insert(vector<int> &H, int k){
    H.push_back(k);
    int size = H.size()-1;
    while(size > 1 && H[size] < H[size/2]){
        swap(H[size], H[size/2]);
        size = size/2;
    }
}

void removeMin(vector<int> &H){
    int size = H.size()-1;
    if (size < 1){
        return;
    }
    H[1] = H[size];
    H.pop_back();
    size--;
    heapifyhelp(H, size, 1);
}

int main(){
    int n; cin >> n;
    int data;
    int cost;
    int sum;
    int aux;
    while(n > 0){
        vector<int> H;
        H.push_back(0);
        cost = 0;
        for (int i = 0; i < n; i++){
            cin >> data;
            insert(H, data);
        }
        while(H.size() > 2){
            aux = H[1];
            removeMin(H);
            sum = aux + H[1];
            removeMin(H);
            insert(H, sum);
            cost = cost + sum;
        }
        cout << cost << '\n';
        cin >> n;
    }
    return 0;
}