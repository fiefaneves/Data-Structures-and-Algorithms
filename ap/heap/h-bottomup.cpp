#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void heapBottomUp(vector<int> &H){
    int size = H.size()-1;
    for (int i = (size)/2; i >= 1; i--){
        int k = i;
        int v = H[k]; 
        bool heap = false;
        while (!heap && 2*k <= size){
            int j = 2*k;
            if (j<size){
                if (H[j] > H[j+1]){
                    j = j + 1;
                }
            }
            if (v <= H[j]){
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

void print(vector<int> &H){
    int size = H.size();
    for (int i = 1 ; i < size ; i++){
        cout << H[i] << ' ';
    }
    cout << '\n';
}

void print_reverse(vector<int> &H){
    int size = H.size();
    for (int i = size ; i > 1 ; i--){
        cout << H[i-1] << ' ';
    }
    cout << '\n';
}

void removeMin(vector<int> &H){
    int size = H.size()-1;
    if (size < 1){
        return;
    }
    H[1] = H[size];
    H.pop_back();
    size--;
    int k = 1;
    int v = H[k];
    bool heap = false;
    while (!heap && 2*k <= size){
        int j = 2*k;
        if (j<size){
            if (H[j] > H[j+1]){
                j = j + 1;
            }
        }
        if (v <= H[j]){ 
            heap = true;
        }
        else{
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
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

void heapsort(vector<int> &H){
    int size = H.size()-1;
    if (size < 1){
        return;
    }
    while (size > 1){
        swap(H[1], H[size]);
        size--;
        int k = 1;
        int v = H[k];
        bool heap = false;
        while (!heap && 2 * k <= size){
            int j = 2 * k;
            if (j < size){
                if (H[j] > H[j+1]){
                    j = j + 1;
                }
            }
            if (v <= H[j]){
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

int main(){
    int cases; cin >> cases;
    int TAM;
    int data;
    for (int i = 0; i < cases; i++){
        cin >> TAM;
        vector<int> H;
        H.push_back(0);
        for (int j = 1; j < TAM+1; j++){
            cin >> data;
            H.push_back(data);
        }
        heapBottomUp(H);
        print(H);
        vector<int> Hcopy(H);
        for (int i = 0 ; i < TAM-1 ; i++){
            removeMin(Hcopy);
            print(Hcopy);
        }
        heapsort(H);
        print_reverse(H);
        cout << '\n';
    }
    return 0;
}