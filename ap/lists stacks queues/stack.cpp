#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct Node{
    int element;
    Node *next;
}Node;

typedef struct Stack{
    Node *top; //pont for first element
    int size;  //size
}Stack;

Node *create_node(int it, Node *nextval){
    Node *n = (Node*) malloc (sizeof (Node));
    n->element=it;
    n->next = nextval;
    return n;
}

Stack *create_stack(){
    Stack *s = (Stack*) malloc (sizeof (Stack));
    s->top = NULL;
    s->size=0;
    return s;
}

void push(Stack *s, int it){
    s->top = create_node(it, s->top);
    s->size++;
}

int pop(Stack *s){
    if (s->top == NULL){
        return -1;
    }
    int it = s->top->element;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return it;
}

void clear(Stack *s) { //TESTAR
    while (s->size!=0){
        pop(s);
        s->size--;
    }
}

int topValue(Stack *s) { //TESTAR
    if (s->top == NULL) {
        cout << "empty" << endl;
        return -1;
    }
    return s->top->element;
}

void print(Stack *s){
    Node *temp = s->top;
    for(int i=0;i<s->size;i++){
        cout << temp->element << endl;
        temp = temp->next;
    }
}

void destruct(Stack *s){
    Node *temp = s->top;
    for(int i=0;i<s->size;i++){
        temp = temp->next;
        free(temp);
    }
    free(s->top);
    free(s);
}

int main(){
    int cases; cin >> cases;
    for(int i=0;i<cases;i++){
        Stack *s = create_stack();
        cout << "Caso " << i+1 << ":" << endl;
        string operation;
        while (operation!="end"){
            string operation; cin >> operation;
            if(operation=="push"){
                int number; cin >> number;
                push(s, number);
            }
            if(operation=="pop"){
                int number; cin >> number;
                int soma=0;
                for(int j=0;j<number;j++){
                    int n = pop(s);
                    soma = soma + n;
                }
                cout << soma << endl;            
            }
            print(s);
        }      
        destruct(s);
    }
    return 0;
}
