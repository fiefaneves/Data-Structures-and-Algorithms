#include <bits/stdc++.h>

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

void clear(Queue *q) {
    while (q->size!=0){
        dequeue(q);
        q->size--;
    }
}

int frontValue(Queue *q){
    if (q->front == NULL) {
        cout << "empty" << "\n";
        return -1;
    }
    return q->front->next->element;
}

void destruct(Queue *q){
    clear(q);
    free(q->rear);
    free(q->front);
    free(q);
}

typedef struct Student {
    int index;
    int arrive;
    int limit;
}Student;

int main(){
    int cases; cin >> cases;
    Queue *q = create_queue();
    for(int i=0;i<cases;i++){
        int time=0;
        int n_students; cin >> n_students;
        Student students[n_students];
        for(int j=0;j<n_students;j++){
            int time_arrive, time_limit; cin >> time_arrive >> time_limit;
            students[j] = {j, time_arrive, time_limit};
        }    

        int j=0;
        while(j<n_students || q->size!=0){
            while (j<n_students && students[j].arrive <= time){
                enqueue(q, students[j].arrive);
                enqueue(q, students[j].limit);
                j++;
            }
            
            if(q->size!=0){
                int a = frontValue(q);
                dequeue(q);
                int l = frontValue(q);
                dequeue(q);
                if(time<=l){
                    cout << time << " ";
                    time++;
                }else{
                    cout << 0 << " ";
                }
            }
            else{
                if(j<n_students){
                    time = students[j].arrive;
                }
            }
        }
        cout << "\n";
        clear(q);
    }
    destruct(q);
}