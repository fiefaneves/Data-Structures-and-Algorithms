#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct Node{
    int element;
    Node *next;
}Node;

typedef struct List{
    Node *head; //pont for head
    Node *tail;   //pont for end
    Node *curr;   //pont for curr
    int size;  //size
}List;

Node *create_node(int it, Node *nextval){
    Node *n = (Node*) malloc (sizeof (Node));
    n->element=it;
    n->next = nextval;
    return n;
}

List *create_list(){
    List *l = (List*) malloc (sizeof (List));
    l->curr = l->tail = l->head = create_node(0, NULL);
    l->size = 0;
    return l;
}

void moveToStart(List *l){
    l->curr = l->head;
}

void prev(List *l){
    if (l->curr = l->head){
        return;
    }
    Node *temp = l->head;
    while(temp->next != l->curr){
        temp=temp->next;
    }
    l->curr=temp;
}

void next(List *l){
    if (l->curr!=l->tail){
        l->curr=l->curr->next;
    }
}

void insert(List *l, int it){
    l->curr->next = create_node(it, l->curr->next);
    if(l->tail==l->curr){
        l->tail=l->curr->next;
    }
    l->size++;
}

int remove(List *l){
    if (l->curr->next == NULL){
        return -1;
    }
    int it = l->curr->next->element;
    if(l->tail==l->curr->next){
        l->tail=l->curr;
    }
    Node *temp = l->curr->next;
    l->curr->next=l->curr->next->next;
    free(temp);
    l->size--;
    return it;
}

void print(List *l){
    Node *temp = l->head;
    for(int i=0;i<l->size;i++){
        cout << temp->next->element << " ";
        temp = temp->next;
    }
}

int count(List *l, int it){
    int cont=0;
    Node *temp = l->head;
    for(int i=0;i<l->size;i++){
        if(temp->next->element==it){
            cont++;
        }
        temp = temp->next;
    }
    return cont;
}

void clear(List *l){
    while(l->size!=0){
        remove(l);
        l->size--;
    }
}

void destruct(List *l){
    clear(l);
    free(l->head);
    free(l->curr);
    free(l->tail);
    free(l);
}

int main(){
    int cases; cin >> cases;
    for(int i=0;i<cases;i++){
        int n; cin >> n;
        List *l = create_list();
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
