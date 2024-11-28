#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    //declaração
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //inserção
    int elemento; cin >> elemento;
    minHeap.push(elemento);
    //acessar menor elemento
    minHeap.top();
    //remoção
    minHeap.pop();
    //verificar se está vazia
    minHeap.empty();
    //tamanho
    minHeap.size();
    
}
