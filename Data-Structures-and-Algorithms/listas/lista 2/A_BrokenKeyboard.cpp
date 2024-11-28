#include <bits/stdc++.h>

#define TAM 100001

using namespace std;

typedef struct Node{
    char element;
    Node *next;
}Node;

typedef struct List{
    Node *head; //pont for head
    Node *tail;   //pont for end
    Node *curr;   //pont for curr
    int size;  //size
}List;

Node *create_node(char it, Node *nextval){
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

void moveToEnd(List *l){
    l->curr = l->tail;
}

void insert(List *l, char it){
    l->curr->next = create_node(it, l->curr->next);
    if(l->tail==l->curr){
        l->tail=l->curr->next;
    }
    l->size++;
}

void printReverse(Node *head) {
    if (head == NULL) {
        return;
    }
    printReverse(head->next);
    cout << head->element;
}

void clear(List *l){
    Node *temp = l->head->next;
    while(temp!=NULL){
        Node *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    l->head = create_node(0, NULL);
    l->curr = l->head;
    l->tail = l->head;
    l->size = 0;
}

int main(){
    char phrase[TAM];
    while(scanf(" %s", phrase) != EOF){
        List *l = create_list();
        int len = strlen(phrase);
        for(int i=0;i<len;i++){
            if(phrase[i] == '['){
                moveToEnd(l);
            }
            if(phrase[i] == ']'){
                moveToStart(l);  
            }
            if(phrase[i] != '[' && phrase[i] != ']'){
                insert(l, phrase[i]);
            }
        }
        printReverse(l->head->next);
        cout << "\n";
        clear(l);  
    }     
    return 0;
}