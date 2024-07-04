#include <bits/stdc++.h>

using namespace std;

typedef struct Node{
    int element;
    Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
    int size;
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
    if(q->size==0){
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

void print(Queue *q){
    Node *temp = q->front->next;
    for(int i=0;i<q->size;i++){
        cout << temp->element;
        if(i!=q->size-1){
            cout << " ";
        }
        temp = temp->next;
    }
    cout << "\n";
}

int main(){
    string operation = "";
    int question;
    Queue *q_questions = create_queue();
    Queue *q_solved = create_queue();
    while(operation!="end"){
        cin >> operation;
        if(operation=="add"){
            cin >> question;
            enqueue(q_questions, question);
        }
        if(operation=="solve"){
            if(q_questions->size>0){
                int n_question = dequeue(q_questions);
                enqueue(q_solved, n_question);
            }
        }
        if(operation=="print"){
            if(q_questions->size>0){
                print(q_questions);
            }
            else{
                cout << "x" << "\n";
            }
        }
        if(operation=="stats"){
            cout << q_solved->size << " " << q_questions->size << "\n";
        }
    }
}
