#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef struct Node{
    int element;
    Node *next;
}Node;

typedef struct Queue{
    Node *front; //pont for front
    Node *rear;   //pont for end
    int size;  //size
}Queue;

Node *create_node(int it, Node *nextval){
    Node *n = (Node*) malloc (sizeof (Node));
    n->element=it;
    n->next = nextval;
    return n;
}

Queue *create_queue(){
    Queue *q = (Queue*) malloc (sizeof (Queue));
    q->front = q->rear = create_node(0, NULL);
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int it){
    q->rear->next = create_node(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int dequeue(Queue *q){
    if(q->size=0){
        return -1;
    }
    int it = q->front->next->element;
    Node *temp = q->front->next;
    q->front->next = q->front->next->next;
    if(q->front->next==NULL){
        q->rear = q->front;
    }
    free(temp);
    q->size--;
    return it; 
}

void clear(Queue *q) { //TESTAR
    while (q->size!=0){
        dequeue(q);
        q->size--;
    }
}

int frontValue(Queue *q){
    if (q->front == NULL) {
        cout << "empty" << endl;
        return -1;
    }
    return q->front->element;
}

void print(Queue *q){
    Node *temp = q->front;
    for(int i=0;i<q->size;i++){
        cout << temp->element << endl;
        temp = temp->next;
    }
}

void destruct(Queue *q){
    Node *temp = q->front;
    for(int i=0;i<q->size;i++){
        temp = temp->next;
        free(temp);
    }
    free(q->front);
    free(q->rear);
    free(q);
}

int main(){

}