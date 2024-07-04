#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    //STACK
    stack<int> myStack; //Criar uma pilha vazia
    bool isEmpty = myStack.empty(); //Verificar se a pilha está vazia
    size_t size = myStack.size(); //size_t size = myStack.size();
    myStack.push(10); //Adicionar um elemento ao topo da pilha (push)
    myStack.pop(); //Remover o elemento do topo da pilha (pop)
    int topElement = myStack.top(); //Acessar o elemento no topo da pilha (top)

    //QUEUE
    queue<int> myQueue; //Criar uma fila vazia
    bool isEmpty = myQueue.empty(); //Verificar se a fila está vazia
    size_t size = myQueue.size(); //Obter o tamanho da fila
    myQueue.push(10); //Adicionar um elemento ao final da fila (push)
    myQueue.pop(); //Remover o elemento da frente da fila (pop)
    int frontElement = myQueue.front(); //Acessar o elemento na frente da fila (front)
    int backElement = myQueue.back(); //Acessar o elemento no final da fila (back)
}