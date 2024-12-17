#include <bits/stdc++.h>

using namespace std;

class Node {
    friend class LinkedList; //para que a classe LinkedList possa acessar os atributos privados de Node
public:
    // declarando construtores
    Node() {val = -1; next = nullptr;} //construtor default
    Node(int v){val = v; next = nullptr;}
private:
    int val;
    Node *next;
};
//construtor fora da classe
    // Node::Node(int v){
        // val = v;
        // next = NULL;
    // }

class LinkedList {
public:
    LinkedList(){
        head = new Node();
        tail = head;
        curr = head;
        sz = 0;
    };

    int size(){return sz;};

    void append(int val){
        curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        tail = new Node(val);
        curr->next = tail;
        sz++;
    };

    int find_pos(int pos){        
        if(pos < 0 || pos >= sz){
            return -1;
        }
        curr = head;
        for(int i = 0; i <= pos; i++){
            curr = curr->next;
        }
        return curr->val;
    };

    int operator[](int pos){return find_pos(pos);};

private:
    Node *head;
    Node *tail;
    Node *curr;
    size_t sz;
};

int main(){
    LinkedList list;
    list.append(2);
    list.append(5);
    list.append(7);
    list.append(6);

    // for (int i = 0; i < list.size(); i++){
    //     cout << list.find_pos(i) << " ";
    // }
    // cout << endl;

    // operator []
    for (int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}