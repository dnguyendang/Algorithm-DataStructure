#include<iostream>
using namespace std;

struct Queue{
    int front;
    int rear;
    int data;
    unsigned capacity;
    int size;
    int* arr;
};

Queue* createQueue(unsigned capacity){
    struct Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = new int(capacity);
    queue->size = 0;
    return queue;
}

int size(Queue* queue){
    return queue->size;
}

int isEmpty(Queue* queue){
    return queue->size == 0;
}

void push(Queue* queue ,int data){
    queue->arr[++queue->rear] = data;
    queue->size++;
} 

void pop(Queue* queue){
    queue->front++;
    queue->size--;
}

int peek(Queue* queue){
    return queue->arr[queue->front];
}

void displayQueue(Queue* queue){
    cout << "Queue: " << endl;
    for(int i = queue->front; i < queue->rear + 1; i++){
        cout << queue->arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue* Q = createQueue(50);
    push(Q, 6);
    push(Q, 5);
    push(Q, 7);
    push(Q, 1);
    push(Q, 3);
    push(Q, 9);
    push(Q, 3);
    push(Q, 2);
    push(Q, 10);

    displayQueue(Q);

    pop(Q);
    pop(Q);
    displayQueue(Q);

    cout << "Value at position where front pointing to: " << peek(Q) << endl;
    cout << "Value at position where rear pointing to: " << Q->arr[Q->rear] << endl;

    return 0;
}

// application
// co che in 
// Giải thuật tìm kiếm theo chiều rộng (Breadth-First search)