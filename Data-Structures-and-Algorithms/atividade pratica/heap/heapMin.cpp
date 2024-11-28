#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void heapify(vector<int> &H, int n, int i) {
    int smallest = i; // Inicializa o menor como raiz
    int left = 2 * i; // Filho à esquerda
    int right = 2 * i + 1; // Filho à direita

    // Se o filho à esquerda é menor que a raiz
    if (left < n && H[left] < H[smallest])
        smallest = left;

    // Se o filho à direita é menor que o menor até agora
    if (right < n && H[right] < H[smallest])
        smallest = right;

    // Se o menor não é a raiz
    if (smallest != i) {
        swap(H[i], H[smallest]);

        // Recursivamente faz heapify na subárvore afetada
        heapify(H, n, smallest);
    }
}

// Função para construir um min-heap
void buildHeap(vector<int> &H, int n) {
    // Índice do último nó não-folha
    int startIdx = (n / 2) - 1;

    // Executa heapify em todos os nós não-folha
    for (int i = startIdx; i > 0; i--) {
        heapify(H, n, i);
    }
}

// Função principal para realizar HeapSort usando min-heap
void heapSort(vector<int> &H) {
    int n = H.size();

    // Constrói o heap (reorganiza o array)
    buildHeap(H, n);

    // Um por um extrai um elemento do heap
    for (int i = n - 1; i > 0; i--){
        // Move a raiz atual para o fim
        swap(H[1], H[i]);

        // Chama heapify no heap reduzido
        heapify(H, i, 1);
    }

    // Reverter o array para obter a ordem crescente
    // reverse(H.begin(), H.end());
}

// Função para imprimir o array
void print(const vector<int> &H) {
    for (int i = 1; i < H.size(); ++i) {
        cout << H[i] << " ";
    }
    cout << '\n';
}

int main(){
    int n; cin >> n;
    int data;
    int cost;
    int sum;
    while(n > 0){
        vector<int> H;
        H.push_back(0);
        cost = 0;
        for (int i = 0; i < n; i++){
            cin >> data;
            H.push_back(data);
        }
        heapSort(H);
        while(H.size() > 2){
            sum = H[1] + H[2];
            H[1] = sum;
            H[2] = H[H.size()-1];
            H.pop_back();
            heapSort(H);
            print(H);
            cost = cost + sum;
        }
        cout << cost << '\n';
        cin >> n;
    }
    return 0;
}