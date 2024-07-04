#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    //CRIAR
    list<int> myList; //criar uma lista vazia
    list<int> myList = {1, 2, 3, 4}; //criar uma lista ja com elementos
    list<int> myList(5, 10);  // lista com 5 elementos, todos iguais a 10

    //INSERÇÃO
    myList.push_front(0); //Inserir no início
    myList.push_back(5); //Inserir no final
    
    auto it = myList.begin(); //inserir de uma posição específica (usando iteradores)
    advance(it, 2);  // move o iterador para a terceira posição
    myList.insert(it, 99);

    //REMOÇÃO
    myList.pop_front(); //remover do inicio
    myList.pop_back(); //remover do final

    auto it = myList.begin(); //Remover de uma posição específica (usando iteradores)
    advance(it, 2);  // move o iterador para a terceira posição
    myList.erase(it);

    myList.remove(99); //Remover todos os elementos com um valor específico

    //ACESSAR
    int first = myList.front(); //acessar primeiro elemento
    int last = myList.back(); //Acessar o último elemento

    //CUNSULTA
    bool isEmpty = myList.empty(); //Verificar se a lista está vazia
    size_t size = myList.size(); //Obter o tamanho da lista

    //MODIFICAÇÃO DE CONTEUDO
    myList.clear();  //Limpar a lista (remover todos os elementos)

    list<int> anotherList = {6, 7, 8}; //Mesclar outra lista
    myList.merge(anotherList);

    myList.reverse(); //reverter a lista
    myList.sort(); //ordenar a lista

    //ITERAÇÃO
    for (int value : myList) { //loop for
        cout << value << " ";
    }
    cout << endl;

    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++) { //iteradores
        cout << *it << " ";
    }
    cout << endl;
}